# VS Code 运行说明

## 1. 适用环境

本项目适用于 Windows + VS Code + MinGW 环境。

建议已安装：

- VS Code
- C/C++ 扩展（Microsoft）
- PowerShell
- MinGW，且可用 `g++.exe`、`gdb.exe`、`windres.exe`

脚本会优先使用系统 `PATH` 中的工具；如果未加入 `PATH`，也兼容 `C:\mingw64\bin\` 下的 MinGW。

## 2. 项目结构

当前工程目录结构如下：

```text
src/
├─ include/      头文件
├─ source/       源文件
└─ resources/    Windows 资源脚本

assets/
├─ icons/        图标资源
├─ images/       图片资源
└─ audio/        音频资源
```

其中：

- 头文件检索路径为 `src/include`
- 编译的源文件位于 `src/source`
- 资源脚本为 `src/resources/Tetris.rc`
- 图标资源为 `assets/icons/Tetris.ico` 和 `assets/icons/small.ico`

## 3. 打开方式

用 VS Code 打开项目根目录，也就是包含以下文件的目录：

- `build-mingw.ps1`
- `.vscode/`
- `src/`
- `assets/`

不要只打开 `src/` 子目录，否则任务和调试配置会失效。

## 4. 构建方式

### 方法一：快捷键构建

按 `Ctrl+Shift+B`，默认会执行：

```text
build Tetris MinGW
```

它会调用：

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .\build-mingw.ps1
```

### 方法二：命令面板运行任务

在命令面板中执行：

```text
Tasks: Run Task
```

然后选择：

- `build Tetris MinGW`
- `run Tetris MinGW`

## 5. 调试方式

按 `F5`，选择：

```text
Debug Tetris MinGW
```

调试配置会先执行构建任务，然后启动：

```text
.vscode-build\mingw\Tetris.exe
```

当前工作目录为项目根目录。

## 6. 构建输出

成功构建后，输出文件位于：

```text
.vscode-build\mingw\Tetris.exe
```

同时在资源编译阶段，脚本还会临时生成：

- `.vscode-build\mingw\Tetris.utf8.rc`
- `.vscode-build\mingw\Tetris.res.o`

这些都属于中间产物，不需要手动维护。

## 7. 资源文件说明

原始 `Tetris.rc` 是 UTF-16 编码，MinGW 的 `windres` 不能直接稳定编译该文件。

当前脚本的处理方式是：

1. 读取 `src/resources/Tetris.rc`
2. 临时转换为 UTF-8
3. 将图标路径替换为 `assets/icons/` 下的实际文件
4. 使用 `windres` 编译资源
5. 将资源对象与 C++ 源文件一起链接

因此在 VS Code 环境下，图标和菜单资源是会参与构建的。

## 8. 常见问题

### 找不到 `g++.exe`

说明 MinGW 没加入系统 `PATH`，或者未安装在 `C:\mingw64\bin\`。  
处理方式：

- 把 MinGW 的 `bin` 目录加入 `PATH`
- 或安装到 `C:\mingw64\bin\`

### 找不到 `gdb.exe`

说明调试器不可用。  
构建通常还能继续，但 `F5` 调试会失败。

### 找不到 `windres.exe`

程序主体仍可能编译通过，但资源文件无法编译进最终 `exe`。

### 打开的是 `src/` 而不是项目根目录

会导致：

- VS Code 任务不可用
- 调试配置不可用
- include 路径不正确

应重新打开项目根目录。

