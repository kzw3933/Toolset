## 项目初衷

&nbsp;&nbsp;&nbsp;&nbsp;之前使用过jupyter notebook学习python深度学习，可以在运行代码的同时便于做笔记，同时便于展示,在学习其他编程语言时也希望能使用类似的工具，发现jupyter不止支持python，还支持众多其他的语言，因此尝试学习搭建相关的环境

## 环境搭建

### 环境准备

- 操作系统: Ubuntu 20.04
- python: 3.8.10
- pip3: 20.0.2
- nodejs: v10.19.0
- npm: 6.14.4

### 安装jupyter

```bash
sudo apt install jupyter-notebook
sudo apt install jupyter-client
```

&nbsp;&nbsp;&nbsp;&nbsp;不安装jupyter-client，后续安装ijavascript显示无法找到jupyter-kernelspec

### 安装并运行ijavascript以支持javascript

```bash
sudo npm install -g --unsafe-perm ijavascript
sudo ijsinstall --install=global
```

### 在项目目录初始化nodejs生成package.json，以支持nodejs

```bash
npm init
```

### 安装并运行jp-babel，支持ES6

```bash
sudo npm install -g --unsafe-perm jp-babel
sudo jp-babel
```



