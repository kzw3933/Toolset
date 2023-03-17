## 使用Express开发个人博客系统

### 项目准备
#### 项目框架设计
个人博客项目可分为首页、内容页、文章编辑页、登录页。分别布局如下:

```
            Header
--------------------------------
        |       文章列表区
        |     XXXXXXXXXXXX
        |     XXXXXXXXXXXX
aside   |     XXXXXXXXXXXX
        |     XXXXXXXXXXXX
        |     XXXXXXXXXXXX
--------------------------------
            Footer

        博客首页设计布局     
```
```
            Header
--------------------------------
        |    
        |    
        |    
aside   |    文章内容显示区
        |    
        |    
--------------------------------
            Footer

        博客内容页设计布局    
```
```
            Header
--------------------------------
        |     文章标题编辑区
        |    ----------------
        |     
aside   |     文章内容编辑区
        |     
        |     
--------------------------------
            Footer

        博客文章编辑页设计布局    
```
```
          大图背景

    ---------------------
    |                   |
    |    登录表单        |
    |                   |
    ---------------------
        博客登录页设计布局    
```

#### 数据库设计



```
                                文章表

Field           Type        Null    Key         Default     Extra
articleID       int         NO      PRI                     auto_increment
articleTitle    varchar     NO      UNI 
articleAuthor   varchar     NO
articleContext  longtext    NO
articleTime     date        NO
articleClick    int         NO

```

```
                                作者表
Field           Type        Null    Key         Default     Extra
authorID        int         NO      PRI                     auto_increment
authorName      varchar     NO      UNI
authorPassword  varchar     NO

```

```mysql
CREATE DATABASE IF NOT EXISTS blog CHARACTER SET utf8;

USE blog;

CREATE TABLE author(
authorID INT KEY AUTO_INCREMENT,
authorName VARCHAR(20) NOT NULL UNIQUE,
authorPassword VARCHAR(32) NOT NULL
);

CREATE TABLE article(
    articleID INT KEY AUTO_INCREMENT,
    articleTitle VARCHAR(100) NOT NULL UNIQUE,
    articleAuthor VARCHAR(20) NOT NULL,
    articleContext LONGTEXT NOT NULL,
    articleTime DATE NOT NULL,
    articleClick INT DEFAULT 0
);

INSERT author VALUES(DEFAULT, 'node', 'e10adc3949ba59abbe56e057f20f883e');

```

### 项目开发

### 快速生成一个项目

```bash
npm install -g express-generator  ## 安装express项目生成器
express -e blog  ## 生成一个使用ejs模版的express博客项目
npm install normalize.css  ## 使用normalize.css来统一浏览器默认样式
```
### 各个界面的实现
```
在index.js和app.js中实现路由逻辑,并实现路由对应的模版文件(login.ejs)以及样式表(mai.css)
```
- 实现博客登录界面
- 实现博客首页界面
- 博客文章内容页的实现
- 博客文章发布的实现
- 博客友情链接的实现
- 博客关于页面的实现
- 博客404页面的实现

### 博客侧边栏的优化

### 修改文章、删除文章的实现

### 博客文章分页的实现

