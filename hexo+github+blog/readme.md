## Hexo博客初搭建



### 环境准备与工具准备

- 操作系统：Windows10
- Node
- Git
- Hexo
- GitHub 帐号

#### Node安装

&nbsp;&nbsp;&nbsp;&nbsp;官网下载node，安装完成后使用以下命令验证判断成功安装
```bash
node -v
```
&nbsp;&nbsp;&nbsp;&nbsp;由于需要使用npm下载各种模块，默认从国外服务器下载，速度较慢,可以使用以下命令配置淘宝镜像
```bash
npm config set registry https://registry.npm.taobao.org
```

#### 安装Hexo

```bash
npm install -g hexo-cli
```
&nbsp;&nbsp;&nbsp;&nbsp;可以使用以下命令验证成功安装

```bash
hexo -v
```

#### github注册与创建仓库

&nbsp;&nbsp;&nbsp;&nbsp;成功注册github后，创建一个`<username>.github.io`的仓库

#### git安装与账号配置

&nbsp;&nbsp;&nbsp;&nbsp;直接进入git官网下载git

&nbsp;&nbsp;&nbsp;&nbsp;git配置用户名和邮箱

```bash
git config --global user.name "你的用户名"
git config --global user.email "你的邮箱"
```

&nbsp;&nbsp;&nbsp;&nbsp;git查看配置信息
```bash
git config -l  //查看所有配置
git config --system --list //查看系统配置
git config --global --list //查看用户（全局）配置
```

#### 连接至github

&nbsp;&nbsp;&nbsp;&nbsp;使用以下命令生成ssh公钥，此公钥用于计算机连接Github
```bash
ssh-keygen -t rsa -C "你的邮箱"
```
&nbsp;&nbsp;&nbsp;&nbsp;之后打开C盘下用户文件夹下的`.ssh`的文件夹，会看到 `id_rsa.pub`,用记事本打开上述图片中的公钥（`id_rsa.pub`），复制里面的内容，然后开始在github中配置ssh密钥,进入github，点击右上角头像 选择settings，进入设置页后选择 SSH and GPG keys，名字随便起，公钥填到Key那一栏。

&nbsp;&nbsp;&nbsp;&nbsp;配置ssh公钥后可以使用以下命令判断是否成功

```bash
ssh -T git@github.com
```

---

### 创建Hexo项目

&nbsp;&nbsp;&nbsp;&nbsp;在目标路径（自选一个空文件夹）下打开cmd命令窗口，执行hexo init初始化项目
```bash
hexo init kzw-blog
```

&nbsp;&nbsp;&nbsp;&nbsp;进入刚才创建的项目 ，输入`npm i`安装相关依赖

```bash
cd kzw-blog
npm i
```

&nbsp;&nbsp;&nbsp;&nbsp;初始化项目后,项目下有如下文件

|  文件(夹) | 用途|
|  :--: |:--: |
| node_modules  |  依赖包 |
| scaffolds  |  生成文章的一些模板 |
| source  | 用来存放你的文章  |
|  themes | 主题  |
| .npmignore  | 发布时忽略的文件（可忽略  |
| _config.landscape.yml  |  主题的配置文件 |
| config.yml   | 博客的配置文件 |
| package.json  | 项目名称、描述、版本、运行和开发等信息  |

&nbsp;&nbsp;&nbsp;&nbsp;输入`hexo server`或者`hexo s`启动项目

```bash
hexo s
```

&nbsp;&nbsp;&nbsp;&nbsp;打开浏览器，输入地址：http://localhost:4000/，即可看到初始化的hexo博客

---


### 将静态博客挂载到 GitHub Pages

&nbsp;&nbsp;&nbsp;&nbsp;安装 hexo-deployer-git

```bash
npm install hexo-deployer-git --save
```
&nbsp;&nbsp;&nbsp;&nbsp;修改 `_config.yml` 文件,在kzw-blog目录下的`_config.yml`，就是整个Hexo框架的配置文件。可以在里面修改大部分的配置。详细可参考官方的配置描述。修改最后一行的配置，将repository修改为github项目地址即可，还有分支要改为main代表主分支（注意缩进）

```yaml
deploy:
  type: git
  repository: git@github.com:kzw3933/kzw3933.github.io.git
  branch: main
```
&nbsp;&nbsp;&nbsp;&nbsp;修改好配置后，运行如下命令，将代码部署到 GitHub

```bash
hexo clean && hexo generate && hexo deploy
```
- hexo clean：删除之前生成的文件，若未生成过静态文件，可忽略此命令
- hexo generate：生成静态文章，可以用hexo g缩写
- hexo deploy：部署文章，可以用hexo d缩写

&nbsp;&nbsp;&nbsp;&nbsp;稍等两分钟，打开浏览器访问：https://kzw3933.github.io ，这时候就可以看到博客内容了

---
---


## 配置博客主题

### 安装主题

&nbsp;&nbsp;&nbsp;&nbsp;使用npm安装hexo-theme-butterfly主题，后续魔改只需修改kzw-blog/node_modules/hexo-theme-butterfly文件夹中的文件

```bash
npm i hexo-theme-butterfly
```

### 应用主题

&nbsp;&nbsp;&nbsp;&nbsp;修改站点配置文件`_config.yml`，把主题改为`butterfly`

```yaml
theme: butterfly
```

&nbsp;&nbsp;&nbsp;&nbsp;下载pug以及stylus的渲染器(这两个渲染器是Butterfly生成基础页面所需的依赖包)

```bash
npm install hexo-renderer-pug hexo-renderer-stylus --save
```

### 基础用法

1. Front-matter

&nbsp;&nbsp;&nbsp;&nbsp;Front-matter 是 markdown 文件最上方以---分隔的区域，用于指定个别档案的变数。其中`Page Front-matter`用于页面配置,`Post Front-matter`用于文章页配置

&nbsp;&nbsp;&nbsp;&nbsp;Page Front-matter：

| 参数  | 描述|
|:--:|:--:|
|title 	|页面标题|
|date  	|页面创建日期|
|type  	|标籤、分类和友情链接三个页面需要配置|
|updated|	页面更新日期|
|description|页面描述|
|keywords	|页面关键字|
|comments	|显示页面评论模块(默认 true)|
|top_img|	页面顶部图片|
|mathjax|	显示mathjax(当设置mathjax的per_page: false时，才需要配置，默认 false)|
|kates 	|显示katex(当设置katex的per_page: false时，才需要配置，默认 false)|
|aside	|  显示侧边栏 (默认 true)|
|aplayer|	在需要的页面加载aplayer的js和css,请参考文章下面的音乐配置|
|highlight_shrink|	配置代码框是否展开(true/false)(默认为设置中highlight_shrink的配置)|

&nbsp;&nbsp;&nbsp;&nbsp;Post Front-matter：

| 参数  | 描述|
|:--:|:--:|
| title	        | 文章标题|
| date	        | 文章创建日期|
| updated	    | 文章更新日期|
| tags	        | 文章标籤|
| categories	| 文章分类|
| keywords	    | 文章关键字|
| description	| 文章描述|
| top_img	    | 文章顶部图片|
| cover	        | 文章缩略图(如果没有设置top_img,文章页顶部将显示缩略图，可设为false/图片地址/留空)|
| comments	    | 显示文章评论模块(默认 true)|
| toc	        | 显示文章TOC(默认为设置中toc的enable配置)|
| toc_number	| 显示toc_number(默认为设置中toc的number配置)|
| toc_style_simple	|显示 toc 简洁模式|
| copyright	   | 显示文章版权模块(默认为设置中post_copyright的enable配置)|
| copyright_author	| 文章版权模块的文章作者|
| copyright_author_href	| 文章版权模块的文章作者链接|
| copyright_url	| 文章版权模块的文章连结链接|
| copyright_info	| 文章版权模块的版权声明文字|
| mathjax	   | 显示mathjax(当设置mathjax的per_page: false时，才需要配置，默认 false)|
| katex	       | 显示katex(当设置katex的per_page: false时，才需要配置，默认 false)|
| aplayer	   | 在需要的页面加载aplayer的js和css,请参考文章下面的音乐配置|
| highlight_shrink| 配置代码框是否展开(true/false)(默认为设置中highlight_shrink的配置)|
| aside	        | 显示侧边栏 (默认 true)|

2. 标签页

&nbsp;&nbsp;&nbsp;&nbsp;在hexo博客的根目录，打开cmd执行如下命令

```bash
hexo new page tags
```

&nbsp;&nbsp;&nbsp;&nbsp;在[BlogRoot]\source\会生成一个含有`index.md`文件的tags文件夹,修改`[BlogRoot]\source\tags\index.md`，添加type: "tags"

```markdown
---
title: tags
date: 2022-10-28 12:00:00
type: "tags"
---
```

3. 友情链接

&nbsp;&nbsp;&nbsp;&nbsp;在hexo博客的根目录，打开cmd执行如下命令

```bash
hexo new page link
```
&nbsp;&nbsp;&nbsp;&nbsp;在`[BlogRoot]\source\`会生成一个含有`index.md`文件的link文件夹,修改`[BlogRoot]\source\link\index.md`，添加type: "link"

```markdown
---
title: link
date: 2022-10-28 12:00:00
type: "link"
---
```

&nbsp;&nbsp;&nbsp;&nbsp;前往`[BlogRoot]\source\_data`创建一个`link.yml`文件（如果沒有 _data 文件夹，自行创建），并写入如下信息（根据需要写）

```yaml
- class_name: 1.技术支持
  class_desc: 本网站的搭建由以下开源作者提供技术支持
  link_list: 
    - name: Hexo 
      link: https://hexo.io/zh-cn/
      avatar: https://d33wubrfki0l68.cloudfront.net/6657ba50e702d84afb32fe846bed54fba1a77add/827ae/logo.svg
      descr: 快速、简单且强大的网志框架
      siteshot: https://source.fomal.cc/siteshot/hexo.io.jpg
      
- class_name: 2.友情链接
  class_desc: 一些好朋友~~
  link_list:
    - name: Fomalhaut🥝
      link: https://fomal.cc/
      avatar: /assets/head.jpg
      descr: Future is now 🍭🍭🍭
      siteshot: https://source.fomal.cc/siteshot/www.fomal.cn.jpg
```

4. 图库

&nbsp;&nbsp;&nbsp;&nbsp;图库页面只是普通的页面，只需要hexo new page xxx创建页面就行,然后使用外挂标签 galleryGroup，具体用法查看对应的内容

```markdown
<div class="gallery-group-main">

{% galleryGroup '封面专区' '本站用作文章封面的图片，不保证分辨率' '/box/Gallery/photo' https://source.fomal.cc/img/default_cover_61.webp %}

{% galleryGroup '背景专区' '收藏的一些的背景与壁纸，分辨率很高' '/box/Gallery/wallpaper' https://source.fomal.cc/img/dm11.webp %}
</div>
```

5. 子页面

&nbsp;&nbsp;&nbsp;&nbsp;子页面也是普通的页面，你只需要hexo new page xxx创建页面就行,然后使用标签外挂 gallery，具体用法查看对应的内容

```markdown
{% gallery %} 
![p1]( https://source.fomal.cc/img/default_cover_1.webp ) 
![p2]( https://source.fomal.cc/img/default_cover_2.webp ) 
![p3]( https://source.fomal.cc/img/default_cover_3.webp ) 
![p4]( https://source.fomal.cc/img/default_cover_4.webp ) 
![p5]( https://source.fomal.cc/img/default_cover_5.webp ) 
![p6]( https://source.fomal.cc/img/default_cover_6.webp ) 
![p7]( https://source.fomal.cc/img/default_cover_7.webp ) 
![p8]( https://source.fomal.cc/img/default_cover_8.webp ) 
![p9]( https://source.fomal.cc/img/default_cover_9.webp ) 
![p10]( https://source.fomal.cc/img/default_cover_10.webp ) 
![p11]( https://source.fomal.cc/img/default_cover_11.webp ) 
![p12]( https://source.fomal.cc/img/default_cover_12.webp ) 
{% endgallery %}
```

6. 404页面

&nbsp;&nbsp;&nbsp;&nbsp;主題內置了一个简单的404页面，可在设置中开放,如需本地预览，访问 http://localhost:4000/404.html即可

```yaml
# A simple 404 page
error_404:
  enable: true
  subtitle: "页面沒有找到"
  background: 
```

---
---


## 博客个性化配置

### 语言

&nbsp;&nbsp;&nbsp;&nbsp;修改站点配置文件`_config.yml`，默认语言是 en,主题支持三种语言: `default(en)`,`zh-CN (简体中文)`,`zh-TW (繁体中文)`

### 网站资料

&nbsp;&nbsp;&nbsp;&nbsp;修改网站各种资料，例如标题、副标题和邮箱等个人资料，修改站点配置文件`_config.yml`。部分参数如下，详细参数可参考官方的配置描述

|  参数 | 描述 |
|:--:|:--:|
| title  | 网站标题  |
| subtitle  | 描述  |
| description  | 网站描述  |
| keywords  | 网站的关键词。支持多个关键词  |
|  author | 名字  |
| language  | 网站使用的语言。对于简体中文用户来说，使用不同的主题可能需要设置成不同的值，参考主题的文档自行设置，常见的有 zh-Hans和 zh-CN。  |
|  timezone | 网站时区。Hexo 默认使用电脑的时区。请参考 时区列表 进行设置，如 America/New_York, Japan, 和 UTC 。一般的，对于中国大陆地区可以使用 Asia/Shanghai  |

### 导航菜单

&nbsp;&nbsp;&nbsp;&nbsp;修改主题配置文件`_config.butterfly.yml`

```yaml
menu:
  Home: / || fas fa-home
  Archives: /archives/ || fas fa-archive
  Tags: /tags/ || fas fa-tags
  Categories: /categories/ || fas fa-folder-open
  List||fas fa-list:
    Music: /music/ || fas fa-music
    Movie: /movies/ || fas fa-video
  Link: /link/ || fas fa-link
  About: /about/ || fas fa-heart
```
&nbsp;&nbsp;&nbsp;&nbsp;必须是 /xxx/，后面||分开，然后写图标名，如果不想显示图标，图标名可不写,若主题版本大于 v4.0.0，可以直接在子目录里添加 hide 隐藏子目录，如下面的List

```yaml
menu:
  Home: / || fas fa-home
  Archives: /archives/ || fas fa-archive
  Tags: /tags/ || fas fa-tags
  Categories: /categories/ || fas fa-folder-open
  List||fas fa-list||hide:
   Music: /music/ || fas fa-music
    Movie: /movies/ || fas fa-video
  Link: /link/ || fas fa-link
  About: /about/ || fas fa-heart

```
&nbsp;&nbsp;&nbsp;&nbsp;文字可自行更改，中英文都可以

```yaml
menu:
  首页: / || fas fa-home
  时间轴: /archives/ || fas fa-archive
  标签: /tags/ || fas fa-tags
  分类: /categories/ || fas fa-folder-open
  清单||fa fa-heartbeat:
    音乐: /music/ || fas fa-music
    照片: /Gallery/ || fas fa-images
    电影: /movies/ || fas fa-video
  友链: /link/ || fas fa-link
  关于: /about/ || fas fa-heart
```

### 代码

#### 代码高亮主题

&nbsp;&nbsp;&nbsp;&nbsp;Butterfly支持 6 种代码高亮样式：`darker`、`pale night`、`light`、`ocean`、`mac`、`mac light`

#### 代码复制

&nbsp;&nbsp;&nbsp;&nbsp;修改主题配置文件`_config.butterfly.yml`中的`highlight_copy`属性，true表示可以复制

```yaml
highlight_copy: true
```

##### 代码框展开/关闭

&nbsp;&nbsp;&nbsp;&nbsp;修改主题配置文件`_config.butterfly.yml`中的`highlight_shrink`属性

```yaml
highlight_shrink: true #代码框不展开，需点击 '>' 打开
```
&nbsp;&nbsp;&nbsp;&nbsp;在默认情况下，代码框自动展开，可设置是否所有代码框都关闭状态，点击>可展开代码。true 全部代码框不展开，需点击>打开,false 代码框展开，有>点击按钮,none 不显示>按钮

#### 代码换行

&nbsp;&nbsp;&nbsp;&nbsp;在默认情况下，Hexo 在编译的时候不会实现代码自动换行。如果不希望在代码块的区域里有横向滚动条的话，那么可以考虑开启这个功能

&nbsp;&nbsp;&nbsp;&nbsp;改主题配置文件`_config.butterfly.yml`中的`code_word_wrap`属性

```yaml
code_word_wrap: true
```

#### 代码高度限制
&nbsp;&nbsp;&nbsp;&nbsp;可配置代码高度限制，超出的部分会隐藏，并显示展开按钮

```yaml
highlight_height_limit: false # unit: px
```
&nbsp;&nbsp;&nbsp;&nbsp;单位是px，直接添加数字，如 200,实际限制高度为highlight_height_limit + 30 px ，多增加 30px 限制，目的是避免代码高度只超出highlight_height_limit 一点时，出现展开按钮，展开没内容。,不适用于隐藏后的代码块（ css 设置 display: none）。

### 社交图标

&nbsp;&nbsp;&nbsp;&nbsp;Butterfly支持font-awesome v6图标。书写格式：图标名：url || 描述性文字

```yaml
social:
  fab fa-github: https://github.com/xxxxx || Github
  fas fa-envelope: mailto:xxxxxx@gmail.com || Email
```

### 顶部图

&nbsp;&nbsp;&nbsp;&nbsp;如果不要显示顶部图，可直接配置 disable_top_img: true

|配置 | 解释|
| :--:|:--:|
|index_img | 主页的 top_img|
|default_top_img |默认的 top_img，当页面的 top_img 没有配置时，会显示 default_top_img |
| archive_img| 归档页面的 top_img|
| tag_img| tag子页面 的 默认 top_img|
| tag_per_img| tag子页面的 top_img，可配置每个 tag 的 top_img|
|category_img |category 子页面 的 默认 top_img |
| category_per_img|category 子页面的 top_img，可配置每个 category 的 top_img |

&nbsp;&nbsp;&nbsp;&nbsp;修改主题配置文件`_config.butterfly.yml`
```yaml
index_img: xxx.png
```
&nbsp;&nbsp;&nbsp;&nbsp;其它页面 （tags/categories/自建页面）和文章页的top_img，要到对应的 md 页面设置front-matter中的top_img

### 文章置顶与封面

- 可以直接在文章的front-matter区域里添加sticky: 1属性来把这篇文章置顶。数值越大，置顶的优先级越大。

- 文章的markdown文档上，在Front-matter添加cover，并填上要显示的图片地址。如果不配置cover，可以设置显示默认的cover；如果不想在首页显示cover，可以设置为false。

&nbsp;&nbsp;&nbsp;&nbsp;修改主题配置文件`_config.butterfly.yml`

```yaml
cover:
  # 是否显示文章封面
  index_enable: true
  aside_enable: true
  archives_enable: true
  # 封面显示的位置
  # 三个值可配置 left , right , both
  position: both
  # 当没有设置cover时，默认的封面显示
  default_cover: 
```
&nbsp;&nbsp;&nbsp;&nbsp;当配置多张图片时，会随机选择一张作为cover，此时写法应为：

```
default_cover:
  - https://cdn.jsdelivr.net/gh/jerryc127/CDN@latest/cover/default_bg.png
  - https://cdn.jsdelivr.net/gh/jerryc127/CDN@latest/cover/default_bg2.png
  - https://cdn.jsdelivr.net/gh/jerryc127/CDN@latest/cover/default_bg3.png
```

### 文章页相关设置

#### 文章meta显示

&nbsp;&nbsp;&nbsp;&nbsp;`post_meta`这个属性用于显示文章的相关信息的，修改主题配置文件`_config.butterfly.yml`

```yaml
post_meta:
  page:
    date_type: both # created or updated or both 主页文章日期是创建日或者更新日或都显示
    date_format: relative # date/relative 显示日期还是相对日期
    categories: true # true or false 主页是否显示分类
    tags: true # true or false 主页是否显示标签
    label: true # true or false 显示描述性文字
  post:
    date_type: both # created or updated or both 文章页日期是创建日或者更新日或都显示
    date_format: relative # date/relative 显示日期还是相对日期
    categories: true # true or false 文章页是否显示分类
    tags: true # true or false 文章页是否显示标签
    label: true # true or false 显示描述性文字

```

#### 文章版权和协议许可

&nbsp;&nbsp;&nbsp;&nbsp;修改主题配置文件`_config.butterfly.yml`

```yaml
post_copyright:
  enable: true
  decode: false
  author_href:
  license: CC BY-NC-SA 4.0
  license_url: https://creativecommons.org/licenses/by-nc-sa/4.0/
```
&nbsp;&nbsp;&nbsp;&nbsp;由于Hexo 4.1开始，默认对网址进行解码，以至于如果是中文网址，会被解码，可设置decode: true来显示中文网址。如果有文章（例如：转载文章）不需要显示版权，可以在文章页Front-matter中单独设置。

```yaml
copyright: false
```

&nbsp;&nbsp;&nbsp;&nbsp;从v3.0.0开始，支持对单独文章设置版权信息，可以在文章Front-matter单独设置

```markdown
post_copyright:
copyright_author: xxxx
copyright_author_href: https://xxxxxx.com
copyright_url: https://xxxxxx.com
copyright_info: 此文章版权归xxxxx所有，如有转载，请註明来自原作者
```

#### 文章打赏

&nbsp;&nbsp;&nbsp;&nbsp;修改主题配置文件`_config.butterfly.yml`

```yaml
reward:
  enable: false
  QR_code:
    - img: /img/wechat.jpg
      link:
      text: wechat
    - img: /img/alipay.jpg
      link:
      text: alipay
```

#### 文章目录TOC

&nbsp;&nbsp;&nbsp;&nbsp;修改主题配置文件`_config.butterfly.yml`

```yaml
toc:
  post: true # 文章页是否显示 TOC
  page: false # 普通页面是否显示 TOC
  number: true	 # 是否显示章节数
  expand: false	# 是否展开 TOC
  style_simple: false # for post 简洁模式（侧边栏只显示 TOC, 只对文章页有效 ）
```

#### 相关文章推荐

&nbsp;&nbsp;&nbsp;&nbsp;相关文章推荐的原理是根据文章tags的比重来推荐，修改主题配置文件`_config.butterfly.yml`

```yaml
related_post:
  enable: true
  limit: 6 # 显示推荐文章数目
  date_type: created # or created or updated 文章日期显示创建日或者更新日

```

#### 文章锚点

&nbsp;&nbsp;&nbsp;&nbsp;开启文章锚点后，当你在文章页进行滚动时，文章链接会根据标题ID进行替换。`注意: 每替换一次，会留下一个歷史记录。所以如果一篇文章有很多锚点的话，网页的歷史记录会很多`。

修改主题配置文件`_config.butterfly.yml`

```yaml
# anchor
# when you scroll in post , the url will update according to header id.
anchor: true
```

#### 文章过期提醒

&nbsp;&nbsp;&nbsp;&nbsp;可设置是否显示文章过期提醒，以更新时间为基准

```yaml
# Displays outdated notice for a post (文章过期提醒)
noticeOutdate:
  enable: true
  style: flat # style: simple/flat
  limit_day: 365 # 距离更新时间多少天才显示文章过期提醒
  position: top # position: top/bottom
  message_prev: It has been # 天数之前的文字
  message_next: days since the last update, the content of the article may be outdated. # 天数之后的文字
```

#### 文章分页按钮

&nbsp;&nbsp;&nbsp;&nbsp;修改主题配置文件`_config.butterfly.yml`

```yaml
# post_pagination (分页)
# value: 1 || 2 || false	# false:为关闭分页按钮；1:下一篇显示的是旧文章；2:下一篇显示的是新文章
# 1: The 'next post' will link to old post
# 2: The 'next post' will link to new post
# false: disable pagination
post_pagination: false
```

### 头像

```yaml
avatar:
  img: /assets/head.jpg
  effect: false # true则会一直转圈
```

### 文章内容复制相关配置

```yaml
# copy settings
# copyright: Add the copyright information after copied content (复制的内容后面加上版权信息)
copy:
  enable: true	# 是否开启网站复制权限
  copyright:	# 复制的内容后面加上版权信息
    enable: true	# 是否开启复制版权信息添加
    limit_count: 50	# 字数限制，当复制文字大于这个字数限制时，将在复制的内容后面加上版权信息
```

### Footer设置

&nbsp;&nbsp;&nbsp;&nbsp;修改主题配置文件`_config.butterfly.yml`

```yaml
footer:
  owner:
    enable: true
    since: 2022	# 站点起始时间
  custom_text:	# 是一个给你用来在页脚自定义文本的选项。通常你可以在这里写声明文本等,支持 HTML。
  copyright: false # Copyright of theme and framework
```

### 右下角按钮

#### 简繁转换
&nbsp;&nbsp;&nbsp;&nbsp;修改主题配置文件`_config.butterfly.yml`

```yaml
translate:
  enable: false
  # 默认按钮显示文字(网站是简体，应设置为'default: 繁')
  default: 繁
  # the language of website (1 - Traditional Chinese/ 2 - Simplified Chinese）
  # 网站默认语言，1: 繁体中文, 2: 简体中文
  defaultEncoding: 2
  # Time delay 延迟时间,若不在前, 要设定延迟翻译时间, 如100表示100ms,默认为0
  translateDelay: 0
  # 当文字是简体时，按钮显示的文字
  msgToTraditionalChinese: '繁'
  # 当文字是繁体时，按钮显示的文字
  msgToSimplifiedChinese: '簡'

```

#### 夜间模式

&nbsp;&nbsp;&nbsp;&nbsp;修改主题配置文件`_config.butterfly.yml`

```yaml
# dark mode
darkmode:
  enable: false
  # dark 和 light 两种模式切换按钮
  button: true
  # Switch dark/light mode automatically (自動切換 dark mode和 light mode)
  # autoChangeMode: 1  Following System Settings, if the system doesn't support dark mode, it will switch dark mode between 6 pm to 6 am
  # autoChangeMode: 2  Switch dark mode between 6 pm to 6 am
  # autoChangeMode: false
  autoChangeMode: false
```

&nbsp;&nbsp;&nbsp;&nbsp;v2.0.0 开始增加一个选项，可开启自动切换light mode 和 dark mode。`autoChangeMode: 1` 跟随系统而变化，不支持的浏览器/系统将按照时间晚上6点到早上6点之间切换为 dark mode。`autoChangeMode: 2`只按照时间 晚上6点到早上6点之间切换为 dark mode,其余时间为light mode。`autoChangeMode: false` 取消自动切换。

#### 阅读模式

&nbsp;&nbsp;&nbsp;&nbsp;阅读模式下会去掉除文章外的内容，避免干扰阅读。只会出现在文章页面，右下角会有阅读模式按钮。
&nbsp;&nbsp;&nbsp;&nbsp;修改主题配置文件`_config.butterfly.yml`

```yaml
readmode: true
```

### 侧边栏设置

#### 排版

&nbsp;&nbsp;&nbsp;&nbsp;可自行决定哪个项目需要显示，可决定位置，也可以设置不显示侧边栏。修改主题配置文件`_config.butterfly.yml`

```yaml
aside:
  enable: true
  hide: false
  button: true
  mobile: true # display on mobile
  position: right # left or right
  display:
    archive: true
    tag: true
    category: true
  card_author:
    enable: true
    description:
    button:
      enable: true
      icon: # fab fa-github
      text: 🛴前往小家...
      link: https://github.com/fomalhaut1998
  card_announcement:
    enable: true
    content: <center>主域名：<br><a href="https://www.fomal.cc"><b><font color="#5ea6e5">fomal.cc</font></b></a>&nbsp;|&nbsp;<a href="https://www.fomal.cn"><b><font color="#5ea6e5">fomal.cn</font></b></a><br>备用域名：<br><a href="https://blog.fomal.cc"><b><font color="#5ea6e5">blog.fomal.cc</font></b></a><br><a href="https://aa.fomal.cc"><b><font color="#5ea6e5">aa.fomal.cc</font></b></a><br><a href="https://bb.fomal.cc"><b><font color="#5ea6e5">bb.fomal.cc</font></b></a><br><a href="mailto:admin@fomal.cn">📬：<b><font color="#a591e0">admin@fomal.cn</font></b></a></center>
  card_recent_post:
    enable: false
    limit: 3 # if set 0 will show all
    sort: date # date or updated
    sort_order: # Don't modify the setting unless you know how it works
  card_categories:
    enable: false
    limit: 8 # if set 0 will show all
    expand: none # none/true/false
    sort_order: # Don't modify the setting unless you know how it works
  card_tags:
    enable: false
    limit: 20 # if set 0 will show all
    color: true
    sort_order: # Don't modify the setting unless you know how it works
  card_archives:
    enable: false
    type: monthly # yearly or monthly
    format: MMMM YYYY # eg: YYYY年MM月
    order: -1 # Sort of order. 1, asc for ascending; -1, desc for descending
    limit: 8 # if set 0 will show all
    sort_order: # Don't modify the setting unless you know how it works
  card_webinfo:
    enable: true
    post修改主题配置文件_config.butterfly.yml_order: # Don't modify the setting unless you know how it works
  card_weibo:
    enable: true
```
#### 访问人数(UV和PV)

&nbsp;&nbsp;&nbsp;&nbsp;修改主题配置文件`_config.butterfly.yml`

```yaml
busuanzi:
  site_uv: true  # 本站总访客数
  site_pv: true  # 本站总访问量 
  page_pv: true  # 本文总阅读量
```

#### 运行时间

&nbsp;&nbsp;&nbsp;&nbsp;修改主题配置文件`_config.butterfly.yml`

```yaml
# Time difference between publish date and now (網頁運行時間)
# Formal: Month/Day/Year Time or Year/Month/Day Time
runtimeshow:
  enable: false
  publish_date: 8/9/2022 00:00:00
  ##网页开通时间
  #格式: 月/日/年 时间
  #也可以写成 年/月/日 时间

```

#### 最新评论

&nbsp;&nbsp;&nbsp;&nbsp;最新评论只会在刷新时才会去读取，并不会实时变化。
&nbsp;&nbsp;&nbsp;&nbsp;由于 API 有 访问次数限制，为了避免调用太多，主题默认存取期限为 10 分鐘。也就是説，调用后资料会存在 localStorage 里，10分鐘内刷新网站只会去 localStorage 读取资料。 10 分鐘期限一过，刷新页面时才会去调取 API 读取新的数据。（3.6.0 新增了 storage 配置，可自行配置缓存时间）。

&nbsp;&nbsp;&nbsp;&nbsp;修改主题配置文件`_config.butterfly.yml`

```yaml
# Aside widget - Newest Comments
newest_comments:
  enable: true
  sort_order: # Don't modify the setting unless you know how it works
  limit: 6  # 显示的数量
  storage: 10 # 设置缓存时间，单位 分钟 
  avatar: true # 是否显示头像
```

### 网站背景

&nbsp;&nbsp;&nbsp;&nbsp;修改主题配置文件`_config.butterfly.yml`

```yaml
# 图片格式 url(http://xxxxxx.com/xxx.jpg)
# 颜色（HEX值/RGB值/颜色单词/渐变色)
# 留空 不显示背景
background: url(https://source.fomal.cc/img/dm1.webp)
```
&nbsp;&nbsp;&nbsp;&nbsp;如果网站根目录不是'/'，使用本地图片时，需加上你的根目录。例如：网站是 https://yoursite.com/blog，引用一张img/xx.png图片，则设置background为 url(/blog/img/xx.png)

### 打字效果

&nbsp;&nbsp;&nbsp;&nbsp;详见：`activate-power-mode`

&nbsp;&nbsp;&nbsp;&nbsp;修改主题配置文件`_config.butterfly.yml`

```yaml
# Typewriter Effect (打字效果)
# https://github.com/disjukr/activate-power-mode
activate_power_mode:
  enable: false
  colorful: true # open particle animation (冒光特效)
  shake: true #  open shake (抖動特效)
  mobile: false
```

### footer 背景

&nbsp;&nbsp;&nbsp;&nbsp;修改主题配置文件`_config.butterfly.yml`

```yaml
# footer是否显示图片背景(与top_img一致)
footer_bg: true
```
- 留空/false：显示默认的颜色
- 图片链接：显示所配置的图片
- 颜色包括HEX值 - #0000FF | RGB值 - rgb(0,0,255) | 颜色单词 - orange | 渐变色 - linear-gradient( 135deg, #E2B0FF 10%, #9F44D3 100%)：对应的颜色
- true：显示跟 top_img 一样

### 背景特效

&nbsp;&nbsp;&nbsp;&nbsp;可设置每次刷新更换彩带，或者每次点击更换彩带。详细配置可查看`canvas_ribbon`

&nbsp;&nbsp;&nbsp;&nbsp;修改主题配置文件`_config.butterfly.yml`

```yaml
canvas_ribbon:
  enable: false
  size: 150
  alpha: 0.6
  zIndex: -1
  click_to_change: false  #設置是否每次點擊都更換彩带
  mobile: false # false 手機端不顯示 true 手機端顯示
```
### 鼠标点击效果

&nbsp;&nbsp;&nbsp;&nbsp;zIndex建议只在-1和9999上选。-1 代表烟火效果在底部。9999 代表烟火效果在前面。

&nbsp;&nbsp;&nbsp;&nbsp;修改主题配置文件`_config.butterfly.yml`

```yaml
fireworks:
  enable: true
  zIndex: 9999 # -1 or 9999
  mobile: false
```

### 自定义字体和字体大小

#### 全局字体

&nbsp;&nbsp;&nbsp;&nbsp;修改主题配置文件`_config.butterfly.yml`中的`font-family`属性即可，如不需要配置，留空。

```yaml
# Global font settings
# Don't modify the following settings unless you know how they work (非必要不要修改)
font:
  global-font-size: '15px'
  code-font-size: '14px'
  # -apple-system, BlinkMacSystemFont, "Segoe UI" , "Helvetica Neue" , Lato, Roboto, "PingFang SC" , "Microsoft JhengHei" , "Microsoft YaHei" , sans-serif
  # Wenkai, consolas, -apple-system, 'Quicksand', 'Nimbus Roman No9 L', 'PingFang SC', 'Hiragino Sans GB', 'Noto Serif SC', 'Microsoft Yahei', 'WenQuanYi Micro Hei', 'ST Heiti', sans-serif;
  font-family: var(--global-font), Consolas_1, -apple-system, 'Quicksand', 'Nimbus Roman No9 L', 'PingFang SC', 'Hiragino Sans GB', 'Noto Serif SC', 'Microsoft Yahei', 'WenQuanYi Micro Hei', 'ST Heiti', sans-serif;
  # consolas, ZhuZiAWan_light, "Microsoft YaHei", Menlo, "PingFang SC", "Microsoft JhengHei", sans-serif
  # Consolas_1, ZhuZiAWan_light, "Microsoft YaHei", Menlo, "PingFang SC", "Microsoft JhengHei", sans-serif
  code-font-family: Consolas_1, var(--global-font), "Microsoft YaHei", Menlo, "PingFang SC", "Microsoft JhengHei", sans-serif

```

#### Blog标题字体

&nbsp;&nbsp;&nbsp;&nbsp;修改主题配置文件`_config.butterfly.yml`中的`blog_title_font`属性即可，如不需要配置，留空.如不需要使用网络字体，只需要把font_link留空

```yaml
# Font settings for the site title and site subtitle
# https://fonts.googleapis.com/css?family=Titillium+Web&display=swap
# Titillium Web, 'PingFang SC' , 'Hiragino Sans GB' , 'Microsoft JhengHei' , 'Microsoft YaHei' , sans-serif
# 左上角網站名字 主頁居中網站名字
blog_title_font:
  font_link: 
  font-family: var(--global-font)
```

### 网站副标题

&nbsp;&nbsp;&nbsp;&nbsp;可设置主页中显示的网站副标题或者喜欢的座右铭

&nbsp;&nbsp;&nbsp;&nbsp;修改主题配置文件`_config.butterfly.yml`中的`subtitle`

```yaml
# the subtitle on homepage (主頁subtitle)
subtitle:
  enable: true
  # Typewriter Effect (打字效果)
  effect: true
  # loop (循環打字)
  loop: true
  # source 調用第三方服務
  # source: false 關閉調用
  # source: 1  調用一言網的一句話（簡體） https://hitokoto.cn/
  # source: 2  調用一句網（簡體） http://yijuzhan.com/
  # source: 3  調用今日詩詞（簡體） https://www.jinrishici.com/
  # subtitle 會先顯示 source , 再顯示 sub 的內容
  source: false
  # 如果關閉打字效果，subtitle 只會顯示 sub 的第一行文字
  sub:
    - "Welcome to Fomalhaut🥝のTiny Home!🤣🤣🤣"
    - "Hope you have a nice day!🍭🍭🍭"

```

### 页面加载动画preloader

&nbsp;&nbsp;&nbsp;&nbsp;当进入网页时，因为加载速度的问题，可能会导致top_img图片出现断层显示，或者网页加载不全而出现等待时间，开启preloader后，会显示加载动画，等页面加载完，加载动画会消失。

```yaml
# 加载动画 Loading Animation
preloader: true
```

### 字数统计

- 安装插件：在你的博客根目录，打开cmd命令窗口执行`npm install hexo-wordcount --save`。
- 开启配置：修改主题配置文件`_config.butterfly.yml`中的`wordcount`

```yaml
wordcount:
  enable: true
  post_wordcount: true
  min2read: true
  total_wordcount: true
```

### 图片大图查看模式

&nbsp;&nbsp;&nbsp;&nbsp;只能开启一个。
&nbsp;&nbsp;&nbsp;&nbsp;如果并不想为某张图片添加大图查看模式，可以使用 html 格式引用图片，并为图片添加 no-lightbox class 名，例如：<img src="xxxx.jpg" class="no-lightbox">

&nbsp;&nbsp;&nbsp;&nbsp;修改主题配置文件`_config.butterfly.yml`中`fancybox`属性

```yaml
# fancybox http://fancyapps.com/fancybox/3/
fancybox: true
```

### Pjax

&nbsp;&nbsp;&nbsp;&nbsp;用户点击链接，通过 ajax 更新页面需要变化的部分，然后使用 HTML5 的 pushState 修改浏览器的 URL 地址。这样可以不用重复加载相同的资源（css/js）， 从而提升网页的加载速度。

```yaml
# Pjax [Beta]
# It may contain bugs and unstable, give feedback when you find the bugs.
# https://github.com/MoOx/pjax
pjax: 
  enable: true
  # 对于一些第三方插件，有些并不支持 pjax 。
  # 你可以把网页加入到 exclude 里，这个网页会被 pjax 排除在外。
  # 点击该网页会重新加载网站。
  exclude: 
    - /music/
    - /no-pjax/
```

&nbsp;&nbsp;&nbsp;&nbsp;注意：使用 pjax 后，一些自己DIY的js可能会无效，跳转页面时需要重新调用（例如朋友圈、说说等），具体参考Pjax文档

### Inject

&nbsp;&nbsp;&nbsp;&nbsp;如想添加额外的 js/css/meta 等等东西，可以在 Inject 里添加，head(</body>标签之前)， bottom(</html>标签之前)。

```yaml
# Inject
# Insert the code to head (before '</head>' tag) and the bottom (before '</body>' tag)
# 插入代码到头部 </head> 之前 和 底部 </body> 之前
inject:
  head:
    - <link rel="stylesheet" href="/xxx.css">
  bottom:
    - <script src="xxxx"></script>
```

### 本地搜索系统

- 安装依赖：前往博客根目录，打开`cmd`命令窗口执行`npm install hexo-generator-search --save`
- 注入配置：修改站点配置文件`_config.yml`，添加如下代码：
```yaml
search:
path: search.xml
field: post
content: true
```
- 主题中开启搜索：在主题配置文件`_config.butterfly.yml`中修改以下内容
```yaml
local_search:
-  enable: false
+  enable: true
```

- 重新编译运行，即可看到效果：前往博客根目录，打开`cmd`命令窗口依次执行如下命令：
```yaml
hexo cl && hexo generate
hexo s -p 8000
```

&nbsp;&nbsp;&nbsp;&nbsp;详情可参考 `hexo-generator-search`