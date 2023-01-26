## docker的学习与使用(一键部署，开箱即用)

### docker安装

- [参考博客](https://blog.csdn.net/weixin_50999155/article/details/119581698)

  安装 docker-ce docker-cli containerd.io docker-compose-plugin

- docker国内源配置(/etc/docker/daemon.json)

```json
{
    "registry-mirrors": [
          "https://registry.docker-cn.com",
          "https://hub-mirror.c.163.com",
          "https://fsp2sfpr.mirror,aliyuncs.com/"
    ]
}
```

### docker的基本命令及使用

- docker拉取nginx

```shell
docker pull nginx:1.22 // 镜像名：版本
docker run --name some-nginx -d -p 8080:80 nginx:1.22 // -d 后台运行 -p 公开端口
docker logs some-nginx:1.22 // 查看启动日志
docker stop some-nginx
docker ps // 查看运行的容器
docker ps -a // 查看所有容器
docker rm some-nginx // 删除容器
docker rmi nginx:1.22  // 删除镜像
```

- docker拉取mysql

```shell
docker run --name some-mysql -e MYSQL_ROOT_PASSWORD=my-secret-pw -d mysql:5.7  // 本地找不到会自动拉取镜像
docker run -it --rm mysql:5.7 mysql -h172.17.0.2 -uroot -p // 启动一个新的容器，使用mysql客户端 -it 使用交互模式 --rm 在容器退出后自动删除容器 mysql -h172.17.0.2 -uroot -p表示启动容器时执行的命令
docker inspect some-mysql // 查看容器的信息
docker exec -it some-mysql /bin/bash   // 在已启动的容器中执行命令
```

### docker网络
```shell
docker network ls
```
- bridge桥接网路
```
如果不指定，新创建的容器默认将连接到bridge网络。
默认情况下，使用bridge网络，宿主机可以ping通容器ip，容器中也能ping通宿主机。
容器之间只能通过 IP 地址相互访问，由于容器的ip会随着启动顺序发生变化，因此不推荐使用ip访问。
```
- host
```
容器与宿主机共享网络，不需要映射端口即可通过宿主机IP访问。（-p选项会被忽略）
主机模式网络可用于优化性能，在容器需要处理大量端口的情况下，它不需要网络地址转换 （NAT），并且不会为每个端口创建“用户空间代理”。
``` 
- none
```
禁用容器中所用网络，在启动容器时使用。
```

- 用户自定义网络
```
在用户自定义网络中，容器之间通过容器名进行访问
用户自定义网络使用 Docker 的嵌入式 DNS 服务器将容器名解析成 IP。

```
```shell
docker network create my-net // 创建用户自定义网络
docker network connect my-net db-mysql // 将已有容器连接到此网络
docker network disconnect my-net db-mysql // 断开连接
docker run -it --rm --network my-net mysql:5.7 mysql -hsome-mysql -uroot -p // 创建容器指定网络,注意此时只连接到用户自定义网络
```

### docker存储

```
将数据存储在容器中，一旦容器被删除，数据也会被删除。同时也会使容器变得越来越大，不方便恢复和迁移。
将数据存储到容器之外，这样删除容器也不会丢失数据。一旦容器故障，我们可以重新创建一个容器，将数据挂载到容器里，就可以快速的恢复。
```

**存储方式**

- volumn卷
```
卷 是docker 容器存储数据的首选方式，卷有以下优势：
 - 卷可以在多个正在运行的容器之间共享数据。仅当显式删除卷时，才会删除卷。
 - 当你想要将容器数据存储在外部网络存储上或云提供商上，而不是本地时。
 - 卷更容易备份或迁移，当您需要备份、还原数据或将数据从一个 Docker 主机迁移到另一个 Docker 主机时，卷是更好的选择。
```
```
docker volumn create vol-my-data
docker run --name some-mysql \
-v /home/jack/mysql/mysql.cnf:/etc/mysql/conf.d/mysql.cnf:ro \
-v vol-my-data:/var/lib/mysql \
-e MYSQL_ROOT_PASSWORD=my-secret-pw -d mysql:5.7
```

- bind mount 绑定挂载
```
绑定挂载适用以下场景：
 将配置文件从主机共享到容器。
 在 Docker 主机上的开发环境和容器之间共享源代码或编译目录。
   例如，可以将 Maven 的target/目录挂载到容器中，每次在主机上用 Maven打包项目时，容器内都可以使用新编译的程序包。
```
```
-v
 
绑定挂载将主机上的目录或者文件装载到容器中。绑定挂载会覆盖容器中的目录或文件。
如果宿主机目录不存在，docker会自动创建这个目录。但是docker只自动创建文件夹，不会创建文件。
```
```shell
mkdir /home/jack/mysql
cd /home/jack/mysql && touch mysql.cnf
docker run --name some-mysql \
-v /home/jack/mysql/mysql.cnf:/etc/mysql/conf.d/mysql.cnf:ro \
-v /home/jack/data:/var/lib/mysql \
-e MYSQL_ROOT_PASSWORD=my-secret-pw -d mysql:5.7

```

- tmpfs 临时挂载
```
临时挂载将数据保留在主机内存中，当容器停止时，文件将被删除。
```

```shell
docker run -d -it --tmpfs /tmp nginx:1.22-alpine
```

### docker部署自己的应用

```
使用docker来部署一个应用系统，RuoYi是一款用java编写的，基于SpringBoot+Bootstrap的后台管理系统。
ruoyi官方文档：http://doc.ruoyi.vip/ruoyi/
源码下载：https://gitee.com/y_project/RuoYi/tree/v4.7.4/
将源码编译打包成ruoyi-admin.jar文件，放到宿主机/home/app目录下，/home/app/sql目录下是数据库初始化脚本。
```

1. 创建网路和存储卷
```shell
docker volume create ruoyi-data
docker network create ruoyi-net
```

2. 部署mysql并初始化数据库
```
- 创建数据库ry
- 设置字符集为utf-8
- 执行数据库初始化脚本
```
```shell
docker run -e MYSQL_ROOT_PASSWORD=123456 \
           -e MYSQL_DATABASE=ry \
					 -v /home/jack/Desktop/Toolset/docker/app/sql:/docker-entrypoint-initdb.d \
           -v /home/jack/Desktop/Toolset/docker/app/ruoyi-data:/var/lib/mysql  \
        	 --network ruoyi-net \
           --name ruoyi-db \
           -d mysql:5.7 \
           --skip-character-set-client-handshake \
           --character-set-server=utf8mb4 --collation-server=utf8mb4_unicode_ci
```

```
使用MYSQL_DATABASE环境变量创建数据库
设置字符集--character-set-server=utf8mb4 --collation-server=utf8mb4_unicode_ci  
容器使用/docker-entrypoint-initdb.d目录下的脚本初始化数据库，脚本可以是.sh.sql和
.sql.gz这三种格式。
```
3. 部署应用
```
docker run -p 8080:8080 \
					 -v /home/jack/Desktop/Toolset/docker/app/ruoyi-admin.jar:/usr/local/src/ruoyi-admin.jar \
        	 --network ruoyi-net \
           --name ruoyi-app \
					 -d openjdk:8u342-jre \
           java -jar /usr/local/src/ruoyi-admin.jar
```

### docker compose容器编排

```
在实际工作中，部署一个应用可能需要部署多个容器，一个一个部署非常不方便。docker compose可以一键部署和启动多个容器，它使用yaml文件来编排服务。
github和docker hub很多项目都提供了docker-compose.yaml文件，我们可以一键部署项目，非常方便。
```

#### 安装wordpress


1. 编写docker-compose.yml
```yaml
version: '3.1'

services:

  wordpress:
    image: wordpress
    restart: always
    ports:
      - 8080:80
    environment:
      WORDPRESS_DB_HOST: db
      WORDPRESS_DB_USER: exampleuser
      WORDPRESS_DB_PASSWORD: examplepass
      WORDPRESS_DB_NAME: exampledb
    volumes:
      - wordpress:/var/www/html

  db:
    image: mysql:5.7
    restart: always
    environment:
      MYSQL_DATABASE: exampledb
      MYSQL_USER: exampleuser
      MYSQL_PASSWORD: examplepass
      MYSQL_RANDOM_ROOT_PASSWORD: '1'
    volumes:
      - db:/var/lib/mysql

volumes:
  wordpress:
  db:
```

2. docker compose 一键部署
```shell
docker compose up -d // 一键部署启动
docker compose start/stop // 启动/停止服务
docker compose down // 停止并删除容器，不会删除存储卷volume
```

#### docker-compose.yaml语法

```
yaml文件语法

1. 缩进代表上下级关系，缩进时不允许使用Tab键，只允许使用空格
2. : 键值对，后面必须有空格
3. - 列表，后面必须有空格
4. [] 数组
5. # 注释
6. {key:value,k1:v1} 字典
7. | 多行文本块
8. ---表示一个文档的开始
```

```
compose 文件结构(docker-compose.yml通常需要包含以下几个顶级元素)

services必要元素，定义一个或多个容器的运行参数
    在services中可以通过以下元素定义容器的运行参数
    image 容器 镜像
    ports端口映射
    environment环境变量
    networks容器使用的网络
    volumes容器挂载的存储卷
    command容器启动时执行的命令
    depends_on定义启动顺序
    复数形式（例如ports,networks,volumes,depends_on）参数需要传入列表
networks创建自定义网络
volumes 创建存储卷

```

### dockerfile制作镜像

#### dockerfile常用命令

```dockerfile
FROM ubuntu:18.04
WORKDIR /app
COPY . .
RUN make .
CMD python app.py
EXPOSE 80

```
```
FROM 打包使用的基础镜像
WORKDIR相当于cd命令，进入工作目录
COPY 将宿主机的文件复制到容器内
RUN打包时执行的命令，相当于打包过程中在容器中执行shell脚本，通常用来安装应用程序所需要的依赖、设置权限、初始化配置文件等
CMD运行镜像时执行的命令
EXPOSE指定容器在运行时监听的网络端口，它并不会公开端口，仅起到声明的作用，公开端口需要容器运行时使用-p参数指定。

```

#### 制作自己的镜像

- 编写dockerfile
  
```dockerfile
FROM openjdk:8u342-jre
WORKDIR /app
COPY ./ruoyi-admin.jar .
CMD [ "java", "-jar", "ruoyi-admin.jar" ]
EXPOSE 8080
```

- `docker build .` 打包

- `docker images` 查看镜像id

- `docker tag 6d5d2350a23e ruoyi-app:4.7.4-jar`


#### images镜像与layer层

```
image文件由一系列层构建而成，dockerfile每一个命令都会生成一个层。每一层都是只读的。
例如之前制作的镜像，就产生了4个层。
也可以使用docker image history ruoyi-java:4.7.4命令查看
创建容器时，会创建一个新的可写层，通常称为“容器层”。对正在运行的容器所做的所有更改（如写入新文件、修改现有文件和删除文件）都将写入容器层，而不会修改镜像。
```

#### 多阶段构建

```
在构建基于 Java 的应用程序时，需要一个 JDK 将源代码编译为 Java 字节码。但是，在生产中不需要该 JDK。
多阶段构建可以将生成时依赖与运行时依赖分开，减小整个image文件大小
```

### 私有仓库


#### docker registry

```
我们可以使用docker push将自己的image推送到docker hub中进行共享，但是在实际工作中，很多公司的代码不能上传到公开的仓库中，因此我们可以创建自己的镜像仓库。
docker 官网提供了一个docker registry的私有仓库项目，可以方便的通过docker部署。
docker run -d -p 5000:5000 --restart always --name registry registry:2
docker image tag ruoyi-java:4.7.4 localhost:5000/ruoyi-java:4.7.4
docker push localhost:5000/ruoyi-java:4.7.4
docker pull localhost:5000/ruoyi-java:4.7.4
如果出现客户端使用https而服务端使用http的错误,需要修改/etc/docker/daemon.json，加入 "insecure-registries": ["192.168.56.108:5000"]
```

#### 保存与加载镜像

```
当我们处于离线状态，比如在很多内网上不能访问互联网，这时候不能通过镜像仓库的方式共享image，我们可以使用导出和导入功能，手动拷贝镜像。
docker save会包含所有层，以及所有标签 + 版本信息。
docker save alpine:3.15 > alpine-3.15.tar  保存image
docker rmi alpine:3.15 删除本地image
docker load < alpine-3.15.tar 加载image
```

```
不要跟export和import命令混淆
docker save/load IMAGE save和load操作的是镜像
docker export/import CONTAINERexport和import操作对象是容器
image包含多个层，每一层都不可变，save保存的信息包含每个层和所有标签 + 版本信息。
容器运行的时候会创建一个可写入的容器层，所有的更改都写入容器层，export导出的只有容器层，不包含父层和标签信息。
```



