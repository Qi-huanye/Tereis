# Dev-C++ 运行说明

## 1. 适用环境

本说明适用于 Windows 下的 Dev-C++ + MinGW 环境。

如果 Dev-C++ 自带的是较旧版本 MinGW，也可以尝试使用，但更建议使用支持 C++17 和 `windres` 的 MinGW。

## 2. 当前工程结构

项目已按工程方式整理：

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

## 3. 建议的工程类型

在 Dev-C++ 中新建工程时，建议选择：

```text
Windows Application
```

不要选控制台程序，否则窗口程序的入口和链接方式会不匹配。

## 4. 需要加入工程的文件

### 源文件

把以下文件加入工程：

- `src/source/stdafx.cpp`
- `src/source/Tetris.cpp`
- `src/source/TetrisLogic.cpp`
- `src/source/TetrisRender.cpp`

### 头文件

头文件通常不需要全部加入编译列表，但建议加入工程树便于查看：

- `src/include/stdafx.h`
- `src/include/Tetris.h`
- `src/include/targetver.h`
- `src/include/resource.h`

### 资源文件

如果 Dev-C++ 当前环境支持资源编译，再把下面文件加入工程：

- `src/resources/Tetris.rc`

## 5. 需要配置的选项

### 头文件搜索路径

把下面目录加入 include path：

```text
src/include
```

### 链接库

确保工程链接以下 Windows 库：

- `winmm`
- `gdi32`
- `user32`

### 编译标准

建议使用：

```text
C++17
```

### 预处理宏

建议定义：

- `UNICODE`
- `_UNICODE`
- `_WINDOWS`

### 工程类型相关参数

如果需要手动补参数，建议与当前脚本保持一致：

- `-mwindows`
- `-municode`

## 6. 关于资源文件

这里是 Dev-C++ 环境下最可能出问题的地方。

`src/resources/Tetris.rc` 原始编码是 UTF-16，而有些 MinGW / Dev-C++ 组合下的 `windres` 不能直接编译它。

同时，资源脚本中引用的图标名是：

- `Tetris.ico`
- `small.ico`

而实际文件位于：

- `assets/icons/Tetris.ico`
- `assets/icons/small.ico`

## 7. 推荐做法

### 做法一：先不编资源文件

最省事的方式是先不要把 `Tetris.rc` 加入 Dev-C++ 工程，只编译 C++ 源文件。

这样：

- 程序主体通常可以编译运行
- 但图标、菜单、关于框资源可能缺失

### 做法二：单独处理资源文件后再加入工程

如果你希望在 Dev-C++ 中也带资源运行，建议先做这两步：

1. 将 `Tetris.rc` 另存为 UTF-8 或 ANSI
2. 把资源中的图标路径改成实际可访问路径

例如改为：

```text
"assets/icons/Tetris.ico"
"assets/icons/small.ico"
```

这样更容易在 Dev-C++ 中直接通过资源编译。

## 8. 运行结果

如果配置正确，编译后应该能得到一个 Windows 图形界面的 `exe`，并正常弹出游戏窗口。

如果只是为了开发和调试，建议优先使用本项目现成的 VS Code 配置，因为当前目录结构、构建脚本和资源处理逻辑已经和 VS Code 对齐。 Dev-C++ 更适合作为兼容运行方案。

