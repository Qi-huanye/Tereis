# Tereis

基于 C++ 与 Windows API 实现的俄罗斯方块课程项目。

本项目使用 MinGW 进行构建，当前已完成基础窗口框架、方块逻辑、绘图显示与资源编译接入，适合作为《大学计算》程序设计大作业使用。

## 项目简介

项目目标是实现一个可运行的桌面版俄罗斯方块程序，包含以下核心内容：

- 创建 Windows 游戏窗口
- 实现方块生成、移动、旋转与下落
- 实现碰撞检测、方块固定与游戏结束判定
- 实现消行逻辑与基础分数系统
- 实现界面绘制与部分资源显示
- 提供 MinGW 构建脚本和 VS Code 调试配置

## 目录结构

```text
Tereis/
├─ src/
│  ├─ include/           头文件
│  ├─ source/            源文件
│  └─ resources/         Windows 资源脚本
├─ assets/
│  ├─ icons/             图标资源
│  ├─ images/            图片资源
│  └─ audio/             音频资源
├─ .vscode/              VS Code 配置
├─ .vscode-build/        本地构建输出目录
├─ report/               实验报告材料与草稿
├─ build-mingw.ps1       MinGW 构建脚本
├─ list.md               项目阶段划分
├─ VSCode运行说明.md     VS Code 使用说明
└─ README.md             项目说明
```

## 开发阶段划分

整个程序按 6 个阶段拆分实现：

1. 窗口创建与程序框架搭建
2. 游戏区域与方块数据结构设计
3. 方块生成、移动与旋转功能
4. 碰撞检测与方块固定逻辑
5. 消除逻辑与分数系统
6. 界面完善与创新功能扩展

详细内容见 [list.md](./list.md)。

## 构建与运行

### 环境要求

- Windows
- MinGW
- `g++.exe`
- `gdb.exe`
- `windres.exe`
- PowerShell

脚本会优先使用系统 `PATH` 中的工具；如果未加入 `PATH`，也兼容 `C:\mingw64\bin\` 下的 MinGW。

### 使用脚本构建

在项目根目录执行：

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .\build-mingw.ps1
```

构建完成后会生成：

```text
.vscode-build\mingw\Tetris.exe
```

### 构建并直接运行

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .\build-mingw.ps1 -Run
```

### 使用 VS Code

项目已提供：

- 构建任务 `build Tetris MinGW`
- 运行任务 `run Tetris MinGW`
- 调试配置 `Debug Tetris MinGW`

详见 [VSCode运行说明.md](./VSCode运行说明.md)。

## 资源文件说明

项目包含 Windows 资源文件 `src/resources/Tetris.rc`，其中定义了图标、菜单、快捷键和关于框等内容。

由于原始 `Tetris.rc` 为 UTF-16 编码，当前构建脚本会在编译时临时转换资源文件编码，并将 `assets/icons/` 中的图标文件一起编译进最终程序，因此资源不再被跳过。

## 报告目录

实验报告相关材料已整理到 [report/](./report/)：

- `report.md`：报告正文草稿
- `outline.md`：章节提纲
- `notes.md`：待补充内容
- `images/`：截图和流程图
- `code-snippets/`：报告中准备引用的代码
- `submission/`：最终提交版文档

## 当前状态

当前项目已完成的工作：

- 修复项目迁移后的路径配置问题
- 补充 `.gitignore`
- 接入资源文件编译流程
- 整理项目阶段清单
- 建立实验报告目录结构

后续可以继续完善的方向：

- 优化界面表现
- 完善分数与状态提示
- 增加创新功能
- 补充测试截图和实验分析
