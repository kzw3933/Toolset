## 学习使用nvim

### 环境搭建
```markdown
- Ubuntu 20.04
- JavaScript、Nodejs、npm
- Zsh、Bash
- Git
- Ripgrep
```
### vim基本知识
1. vim配置文件
nvim的配置文件一般在`~/.config/nvim`目录下

2. vim按键表示
- 命令输入
  - `x` 按下一次`x`键
  - `dw` 按下一次`d`键，然后按下一次`w`键
  - `dap` 按下一次`d`键，然后按下一次`a`键,然后按下一次`p`键
- 组合键
  - `<C-n>`  按住`Ctrl`键，然后按一下`n`键
  - `g<C-]>` 按一下g键，然后按住`Ctrl`键，再按一下`]`键
  - `<C-r>0` 按住`Ctrl`键后，按一下`r`键，放开后再按一下`0`键
  - `<C-w><C-=>` 按住`Ctrl`键后，按一下`w`键,放开`w`键后再按一下`=`键
- 占位符
  - `f{char}` 按一下`f`键，然后按任意字符
  - `^{a-z}` 按一下`^`键，然后按任意小写字母键
  - `m{a-zA-Z}` 按一下`m`键，然后按任意大小写子母键
  - `d{motion}` 按一下`d`键，然后键入任意动作命令
  - `<C-r>{register}` 按住`Ctrl`键后按一下`r`键，放开后键入任意一个寄存器地址
  - `<C-v>{nondigit}` 按住`Ctrl`键后按一下`v`键,放开后键入任意一个非数字键
- 特殊键
  - `<Esc>`    按一下退出键
  - `<CR>`      按一下回车键
  - `<Tab>`      按一下Tab键
  - `<S-Tab>`     按住`Shift`键后按一下`Tab`键
  - `<M-j>`     按住`Meta`键后按一下`j`键,`Meta`键要视情况而定，可能是`Option`键或`Alt`键
  - `<Up>`      按一下上光标键
  - `<Down>`        按一下下光标键
  - `<Space>`       按一下空格键
  - `<Leader>g`     按一下引导键，再按一下`g`键,`<Leader>`引导键是可以自行定义的，可以在`vimrc`文件中使用一下`let mapleader = ","`将其定义为`,`

3. 与命令行交互
在vim中，按下`:`键会从普通模式切换到命令模式,在命令模式下输入一些Ex命令，按下`<CR>`键就可以执行这些命令;在nvim中可以通过`:terminal`命令在终端缓冲区运行一个shell，在这种情况下,`>>`提示符就表示在终端缓冲区的shell中执行命令

### 添加python支持及neovim-remote支持

在nvim中使用`:checkhealth`可以查看neovim各种provider的详情报告,当前neovim提供了一些有剪切板支持的provider、python集成、Ruby集成

通过下载python客户端`pip3 install --user --upgrade neovim`并重启nvim启用python provider
再使用`pip3 install --user -upgrade neovim-remote`安装neovim-remote(此工具依赖python3的neovim客户端)

### 安装插件

```markdown
简而言之，包指的是一个包含一个或多个插件的目录，插件是一个包含一个或者一堆脚本的目录，最后脚本指的是一个单独的用`Vim Script`写的指令集文件 
```
- nvim插件机制
1. nvim在启动时会遍历`$VIMCONFIG/pack/*/start`(*为自己起名的任意目录)目录下的插件，将搜寻到的插件加入`runtimepath`,然后再次遍历并source插件里的vim脚本
2. 需要注意的是也可以在opt目录下安装插件(即为可选插件，需要使用`packadd 包名`来载入包)
3. 另外nvim启动时默认会载入自己的配置文件`$VIMCONFIG/init.vim`
4. vim的包只要包文件在指定的文件夹即可，因此可以直接使用git安装

- minipac包管理器

1. 创建一个包目录`$VIMCONFIG/pack/minpac/opt`(可以在$VIMCONFIG/init.vim中使用packadd载入)
2. 使用`git clone https://github.com/k-takata/minpac.git`安装到刚才建的opt目录
3. 之后就可以直接使用`minpac#add(),minpac#update(),minpac#clean()`(可以在固定被载入的包中执行,比如$VIMCONFIG/init.vim)安装，删除包