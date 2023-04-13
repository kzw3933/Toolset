## 第一部分 背景
1. 版本控制系统（追踪变更）
2. 为什么需要版本控制
3. 如何学习Git

## 第二部分 数据模型
- 思考历史：快照的故事
    简单模型：线性历史
    Git：有向无环图（DAG）

## 第三部分 命令

1. 基础命令
 - `git help <command>`：获取关于git命令的帮助信息
 - `git init`：创建一个新的Git仓库，数据存储在.git目录中
 - `git status`：告诉你正在发生什么
 - `git add <filename>`：将文件添加到暂存区
 - `git commit`：创建一个新的提交
 - `git log`：展示扁平化的历史记录
 - `git log --all --graph --decorate`：将历史记录可视化为DAG
 - `git diff <filename>`：显示与暂存区相比的更改
 - `git diff <revision> <filename>`：显示快照之间文件的差异
 - `git checkout <revision>`：更新HEAD和当前分支

2. 分支与合并
 - `git branch`：展示分支
 - `git branch <name>`：创建一个分支
 - `git checkout -b <name>`：创建一个分支并切换到它
 - `git merge <revision>`：合并到当前分支
 - `git rebase`：将一系列补丁变基到一个新的基础上

3. 远程仓库
 - `git remote`：列出远程仓库
 - `git remote add <name> <url>`：添加一个远程仓库
 - `git push <remote> <local branch>:<remote branch>`：将对象发送到远程仓库，并更新远程引用
 - `git branch --set-upstream-to=<remote>/<remote branch>`：设置本地与远程分支之间的对应关系
 - `git fetch`：从远程检索对象/引用
 - `git pull`：相当于git fetch;git merge
 - `git clone`：从远程下载仓库

4. 撤销操作
 - `git commit --amend`：编辑提交的内容/信息
 - `git reset HEAD <file>`：取消暂存文件
 - `git checkout -- <file>`：丢弃更改

5. 高级命令
 - `git config`：Git高度可定制
 - `git clone --depth=1`：浅克隆，不包括完整的版本历史
 - `git add -p`：交互式暂存
 - `git rebase -i`：交互式变基
 - `git blame`：显示最后编辑哪行的人
 - `git stash`：暂时移除对工作目录的修改
 - `git bisect`：二分历史记录
 - .gitignore：指定要忽略的故意未跟踪的文件

## 第四部分 案例研究


## 第五部分 Github的使用

- Github常用词含义
```
watch：会持续收到项目的动态
fork：复制某个项目到自己的仓库
star：点赞数，表示对该项目表示认可，点赞数越多的项目一般越火
clone：将项目下载到本地
follow：关注你感兴趣的作者，会收到他们的动态
```
- 使用Github搜索项目
    - 精准搜索仓库标题、仓库描述、README
        ```
        in:name xxx 项目名包含xxx
        in:description xxx 项目描述包含xxx
        in:readme xxx 项目介绍文档里含有xxx
        ```
    - stars或fork数量去查找
        ```
        stars:>xxx stars数大于xxx
        stars:xx..xx stars数在xx…xx之间
        forks:>xxx forks数大于xxx
        forks:xx..xx forks数在xx…xx之间
        ```
    - 按照地区和语言进行搜索
        ```
        location：地区
        language：语言
        ```
    - 根据仓库大小搜索(单位KB)
        ```
        size:>= 数字
        ```
    - 根据仓库是否在更新的搜索
        ```
        pushed:> YYYY-MM-DD 最后上传日期大于YYYY-MM-DD
        created:> YYYY-MM-DD 创建日期大于YYYY-MM-DD
        ```
    - 根据某个人或组织进行搜索
        ```
        user: name 查找某个用户
        org: name 查找某个组织
        followers:>=xxx 查找关注者数量超过xxx的开发者
        ```
    - 根据仓库的LICENSE搜索
        ```
        license:对应协议
        ```
    - awesome加强搜索
        ```
        Awesome 已经成为不少 GitHub 项目喜爱的命名之一，Awesome 往往整合了大量的同一领域的资料，让大家可以更好的学习awesome 关键字, awesome 系列一般是用来收集学习、工具、书籍类相关的项目
        ```
    - 热门搜索（GitHub Trend 和 GitHub Topic）
        ```
        GitHub Trend 页面总结了每天/每周/每月周期的热门 Repositories 和 Developers，可以看到在某个周期处于热门状态的开发项目和开发者
        ```