# VS Code 运行说明

1. 用 VS Code 打开本文件所在文件夹: `C:\Users\27282\Desktop\src_学生版`
2. 安装 VS Code 扩展: `C/C++`，发布者是 `Microsoft`
3. 按 `Ctrl+Shift+B` 编译
4. 按 `F5` 调试运行，或在命令面板执行 `Tasks: Run Task` -> `run Tetris MinGW`

说明:

- 默认配置优先使用系统 `PATH` 中的 `g++.exe` / `gdb.exe`，也兼容 `C:\mingw64\bin\g++.exe`。
- 源码目录是 `src`，资源目录是 `assets`。
- MinGW 构建输出文件在 `.vscode-build\mingw\Tetris.exe`。
- 由于原项目的 `Tetris.rc` 是 UTF-16，MinGW 暂不编译资源文件；这只影响图标/菜单资源，不影响源码编译运行。
