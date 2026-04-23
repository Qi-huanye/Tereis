# VS Code 运行说明

1. 用 VS Code 打开项目根目录。
2. 安装 VS Code 扩展: `C/C++`，发布者是 `Microsoft`
3. 按 `Ctrl+Shift+B` 编译
4. 按 `F5` 调试运行，或在命令面板执行 `Tasks: Run Task` -> `run Tetris MinGW`

说明:

- 默认配置优先使用系统 `PATH` 中的 `g++.exe` / `gdb.exe`，也兼容 `C:\mingw64\bin\g++.exe`。
- 源码目录已按工程结构整理为 `src/include`、`src/source`、`src/resources`，资源目录已整理为 `assets/icons`、`assets/images`、`assets/audio`。
- MinGW 构建输出文件在 `.vscode-build\mingw\Tetris.exe`。
- `Tetris.rc` 位于 `src/resources`，构建脚本会在编译时临时转换编码并编译资源文件。
