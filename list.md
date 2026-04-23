# 函数 TODO 分阶段清单

## 第一阶段：窗口创建与程序框架搭建

简要说明：完成程序入口、主窗口创建、消息循环和基础对话框处理。

- [ ] `_tWinMain` - `src/Tetris.cpp`
- [ ] `MyRegisterClass` - `src/Tetris.cpp`
- [ ] `InitInstance` - `src/Tetris.cpp`
- [ ] `WndProc` - `src/Tetris.cpp`
- [ ] `About` - `src/Tetris.cpp`

## 第二阶段：游戏区域与状态初始化

简要说明：完成游戏初始状态建立和重新开始相关逻辑。

- [ ] `Restart` - `src/TetrisLogic.cpp`

## 第三阶段：方块生成、移动与旋转

简要说明：完成方块的基础操作，包括下落、左右移动、旋转和快速到底。

- [ ] `MoveDown` - `src/TetrisLogic.cpp`
- [ ] `MoveLeft` - `src/TetrisLogic.cpp`
- [ ] `MoveRight` - `src/TetrisLogic.cpp`
- [ ] `Rotate` - `src/TetrisLogic.cpp`
- [ ] `DropDown` - `src/TetrisLogic.cpp`

## 第四阶段：碰撞检测与方块固定

简要说明：完成越界判断、碰撞检测、方块落地固定和结束判定。

- [ ] `CanMoveDown` - `src/TetrisLogic.cpp`
- [ ] `CanMoveLeft` - `src/TetrisLogic.cpp`
- [ ] `CanMoveRight` - `src/TetrisLogic.cpp`
- [ ] `Fixing` - `src/TetrisLogic.cpp`
- [ ] `GameOver` - `src/TetrisLogic.cpp`

## 第五阶段：消除逻辑与分数系统

简要说明：完成消行、行下移和得分更新等核心反馈机制。

- [ ] `DeleteOneLine` - `src/TetrisLogic.cpp`
- [ ] `DeleteLines` - `src/TetrisLogic.cpp`

## 第六阶段：界面绘制与扩展功能

简要说明：完成游戏界面绘制，并实现落点预测等增强功能。

- [ ] `ComputeTarget` - `src/TetrisLogic.cpp`
- [ ] `TDrawScreen` - `src/TetrisRender.cpp`

## 第七阶段：创新扩展