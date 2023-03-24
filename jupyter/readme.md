## 各种编程语言的jupyter环境搭建

&nbsp;&nbsp;&nbsp;&nbsp;之前使用过jupyter notebook学习python深度学习，可以在运行代码的同时便于做笔记，同时便于展示,在学习其他编程语言时也希望能使用类似的工具，发现jupyter不止支持python，还支持众多其他的语言，因此尝试学习搭建相关的环境

### 1. javascript + jupyter
#### 环境准备

- 操作系统: Ubuntu 20.04
- python: 3.8.10
- pip3: 20.0.2
- nodejs: v10.19.0
- npm: 6.14.4

#### 安装jupyter

```bash
sudo apt install jupyter-notebook
sudo apt install jupyter-client
```

&nbsp;&nbsp;&nbsp;&nbsp;不安装jupyter-client，后续安装ijavascript显示无法找到jupyter-kernelspec

#### 安装并运行ijavascript以支持javascript(ijavascript作为jupyter notebook的javascript内核)

```bash
sudo npm install -g --unsafe-perm ijavascript
sudo ijsinstall --install=global
```

#### 在项目目录初始化nodejs生成package.json，以支持nodejs

```bash
npm init
```

#### 安装并运行jp-babel，支持ES6

```bash
sudo npm install -g --unsafe-perm jp-babel
sudo jp-babel
```

### 2. rust + jupyter

#### 环境准备

- 操作系统: Ubuntu 20.04
- python: 3.8.10
- pip3: 20.0.2
- cmake: 3.16.3

#### 安装jupyter

```bash
sudo apt install jupyter-notebook
sudo apt install jupyter-client
```

#### 安装rust
```bash
curl https://sh.rustup.rs -sSf | sh
```
#### 安装EvCxR并编译(EvCxR作为jupyter notebook的rust内核)
```bash
cargo install evcxr_jupyter
evcxr_jupyter --install
```

### 3. lisp + jupyter
#### 环境准备

- 操作系统: Ubuntu 20.04
- python: 3.8.10
- pip3: 20.0.2

#### 安装jupyter

```bash
sudo apt install jupyter-notebook
sudo apt install jupyter-client
```

#### 安装roswell
```bash
curl -L https://github.com/roswell/roswell/releases/download/v19.08.10.101/roswell_19.08.10.101-1_amd64.deb --output roswell.deb
sudo dpkg -i roswell.deb && rm -rf roswell.ded
```
#### 安装common-lisp-jupyter
```bash
export PATH=$PATH:~/.roswell/bin
ros install common-lisp-jupyter
```

[备注] 编译期间可能遇到某些库不存在要自行下载(比如libzmq3-dev: `sudo apt install libzmq3-dev`)

### 4. c++/c + jupyter
#### 环境准备

- 操作系统: Ubuntu 20.04
- python: 3.8.10
- pip3: 20.0.2

#### miniconda并更换conda源
```bash
wget https://mirrors.tuna.tsinghua.edu.cn/anaconda/miniconda/Miniconda3-latest-Linux-x86_64.sh
chmod +x Miniconda3-latest-Linux-x86_64.sh
./Miniconda3-latest-Linux-x86_64.sh
rm Miniconda3-latest-Linux-x86_64.sh
conda config --add channels https://mirrors.tuna.tsinghua.edu.cn/anaconda/pkgs/free/
conda config --add channels https://mirrors.tuna.tsinghua.edu.cn/anaconda/pkgs/main/
conda config --set show_channel_urls yes 
conda config --set auto_activate_base false
```

#### 安装jupyter(默认安装在base环境下)
```bash
conda install jupyter
```
#### 安装c++内核xeus-cling
```bash
conda install xeus-cling -c conda-forge
```
[备注] 使用pip无法安装,xeus-cling被打包到conda里,因此需使用conda安装,同时由于使用conda安装c++内核,需使用conda创建环境并使用conda环境中的jupyter环境
