# 函数 TODO 分阶段清单

说明：项目整体仍划分为 6 个阶段，便于按模块推进；每个阶段内的函数顺序尽量与源码实现顺序和依赖关系保持一致。

## 第一阶段：窗口创建与程序框架搭建

简要说明：完成程序入口、窗口类注册、主窗口创建、消息循环以及基础对话框处理。

- [x] `1. _tWinMain` - `src/source/Tetris.cpp`
- [x] `2. MyRegisterClass` - `src/source/Tetris.cpp`
- [x] `3. InitInstance` - `src/source/Tetris.cpp`
- [x] `4. WndProc` - `src/source/Tetris.cpp`
- [x] `5. About` - `src/source/Tetris.cpp`

## 第二阶段：基础碰撞判断

简要说明：先完成活动方块的基础移动可行性判断，为后续移动、旋转和落地逻辑提供前置条件。

- [x] `6. CanMoveDown` - `src/source/TetrisLogic.cpp`
- [x] `7. CanMoveLeft` - `src/source/TetrisLogic.cpp`
- [ ] `8. CanMoveRight` - `src/source/TetrisLogic.cpp`

## 第三阶段：方块移动与旋转

简要说明：在可移动判断完成后，实现方块的下移、左移、右移、旋转和一键到底操作。

- [ ] `9. MoveDown` - `src/source/TetrisLogic.cpp`
- [ ] `10. MoveLeft` - `src/source/TetrisLogic.cpp`
- [ ] `11. MoveRight` - `src/source/TetrisLogic.cpp`
- [ ] `12. Rotate` - `src/source/TetrisLogic.cpp`
- [ ] `13. DropDown` - `src/source/TetrisLogic.cpp`

## 第四阶段：方块固定与游戏状态

简要说明：完成方块落地后的固定、游戏结束判断、预测落点与重新开始等状态控制逻辑。

- [ ] `14. Fixing` - `src/source/TetrisLogic.cpp`
- [ ] `17. GameOver` - `src/source/TetrisLogic.cpp`
- [ ] `18. ComputeTarget` - `src/source/TetrisLogic.cpp`
- [ ] `19. Restart` - `src/source/TetrisLogic.cpp`

## 第五阶段：消行与得分逻辑

简要说明：完成删除单行、批量消行以及相关分数更新逻辑。

- [ ] `15. DeleteOneLine` - `src/source/TetrisLogic.cpp`
- [ ] `16. DeleteLines` - `src/source/TetrisLogic.cpp`

## 第六阶段：界面绘制与整体完善

简要说明：完成最终游戏界面绘制，并与前面的逻辑配合形成可运行的完整项目。

- [ ] `20. TDrawScreen` - `src/source/TetrisRender.cpp`
