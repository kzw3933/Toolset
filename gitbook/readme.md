## 学习gitbook的基本使用

由于经常在github遇到使用markdown编写电子书的项目(这些项目本身就是遵循gitbook的规范或是使用gitbook生成,这些项目本身有一定的目录结构和配置文件)，这些项目大多提供在线阅读文档,但是自己想下载到本地并生成pdf，这时就需要使用gitbook。

### gitbook介绍

Gitbook 是一个能将使用 Markown 语法的 md 格式文档，快速制作成各种格式电子书的工具。常被用于编写文档或者电子书，特点是方便简洁，易于使用。只要熟悉轻量级标记语法的 Markdown 语法，就能使用Gitbook来制作各种格式的电子书。

### gitbook环境搭建

#### 基础环境
```
操作系统: win10
```
#### 1. 安装ebook-concert

ebook-concert 主要用于生成 PDF、eBook，Mobi 等格式的电子书,下载地址https://calibre-ebook.com/download,下载并安装后可使用`ebook-concert  --version`验证,注意需确保ebook-concert在命令行可用(即可执行文件在环境变量可被找到)

#### 2. 安装nodejs和gitbook-cli
```markdown
这个过程有很多的坑,包括但不限于安装gitbook-cli后使用`gitbook -V`后一直卡在此处,以及gitbook的依赖包graceful-fs的问题,归结到一处，大多是版本依赖的问题,在最后使用了nvm重新安装指定版本的nodejs后成功
```
```
- 下载nvm,在https://github.com/coreybutler/nvm-windows/releases下载即可
- nvm install 10.22.0 // 安装10.22.0版本的node
- nvm use 10.22.0 // 使用10.22.0的node，此时对应的npm版本为6.14.6
- npm install gitbook-cli -g
- gitbook -V
```

#### 3. 使用gitbook生成pdf
在fpga并行编程目录下执行如下操作即可

```
gitbook install // 安装gitbook需要的插件
gitbook pdf .\    ..\FPGA并行编程.pdf
```