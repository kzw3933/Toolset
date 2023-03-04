## 学习制作linux下的.desktop文件，支持桌面应用

### 桌面图标位置

&nbsp;&nbsp;&nbsp;&nbsp;`/usr/share/applications` 或 `/home/user/.local/share/applications`

### 桌面图标格式

所有的桌面图标格式均为desktop,即名为xxx.desktop

### 编辑内容

```bash
[Desktop Entry]   // 文件头(必须)
Encoding=UTF-8    // 编码方式(可选)
Name = XXX        // 程序名(必须)
Icon=图标文件名     // 图标(可选),全称包含路径
Exec=脚本文件路径   // 执行脚本(若为应用程序桌面图标则为必选)
Type=Application  // 分类
Comment=comment   // 鼠标经过图标上面时的提示文字
```

### 示例(创建wps文字图标)

```bash
[Desktop Entry]
 
Name = wps word
Exec = /usr/local/wps-office_10.1.0.6757_x86_64/wps
Icon = /usr/local/wps-office_10.1.0.6757_x86_64/resource/icons/hicolor/256x256/apps/wps-office-wpsmain.png
Encoding = UTF-8
Comment = wps word
Type = Application
```

**备注：若启动项是带有欢迎界面（例如matlab），`Exec = 路径/matlab` 后要加`-desktop`，即：`Exec = 路径/matlab -desktop`**

