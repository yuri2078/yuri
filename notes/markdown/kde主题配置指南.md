# kde 主题配置指南

## 任务切换

```bash
https://www.opencode.net/adhe/neve4plasma
```

## tela 图标

```bash
git clone https://github.com/vinceliuice/Tela-icon-theme.git
cd Tela-icon-theme
./install.sh

```

## 主题

+ deepin 主题 `https://github.com/yeyushengfan258/DeepinV20-kde.git`
+ layan 主题 : `https://github.com/vinceliuice/Layan-kde.git`
+ McSur 主题 : `https://github.com/yeyushengfan258/McSur-kde.git`
+ McMuse 主题 : `https://github.com/yeyushengfan258/McMuse-circle.git`

```bash
git clone https://github.com/yeyushengfan258/DeepinV20-kde.git
cd DeepinV20-kde/
./install.sh # (sudo)
```

## 桌面圆角项目

```bash
git clone https://github.com/a-parhom/LightlyShaders.git
mkdir qt5buil ;cd qt5build
cmake ../ -DCMAKE_INSTALL_PREFIX=/usr && make && sudo make install && (kwin_x11 --replace &)
```

然后在 系统设置 -> 工作区设置 -> 桌面特效 -> LightlyShaders 设置就行

## latte-dock 样式

```bash
git clone https://github.com/JM-Enthusiast/latte-indicator-win11.git
kpackagetool5 -i . -t Latte/Indicator
```

## zsh

1. ```sh
   sudo pacman -S zsh zsh-autosuggestions zsh-syntax-highlighting zsh-completions
   chsh -l # 查看安装了哪些 Shell
   chsh -s /usr/bin/zsh # 修改当前账户的默认 Shell
   
   curl -fsSL https://raw.githubusercontent.com/zimfw/install/master/install.zsh | zsh
   vim ~/.zshrc
   zmodule romkatv/powerlevel10k
   zimfw install
   sudo pacman -S ttf-jetbrains-mono-nerd
   ```

   

## 各种控件存储目录

> 所有用户(root) `/usr/share/*` 当前用户 `~/.local/share/*`

任务切换 : `~/.local/share/kwin/tabbox/*`

sddm 主题 : `/usr/share/sddm/themes`

konsole 配色 : `/usr/share/konsole/`
