#pragma once

#include "resource.h"
#include "stdafx.h"
#include <mmsystem.h>

#pragma comment(lib, "winmm.lib")

constexpr int GRID = 30;
constexpr int nGameWidth = 10;
constexpr int nGameHeight = 20;
constexpr int nWidth = 16;
constexpr int nHeight = 22;

// 定义一个点，用来表示方块的位置
struct Point
{
    int x;
    int y;
};

extern int nType;              // 下一方块类型
extern int type;               // 当前方块类型
extern int state;              // 当前方块状态
extern int tScore;             // 当前得分
extern bool gameOverFlag;      // 游戏已经结束
extern bool suspendFlag;       // 暂停游戏
extern bool targetFlag;        // 启用瞄准器
extern int workRegion[20][10]; // 工作区数据，0 表示该位置没有被占用
extern Point point;            // 当前方块的当前位置
extern Point target;           // 当前方块目标位置，用于瞄准器
extern int bricks[7][4][4][4];
extern COLORREF BrickColor[7];

// 游戏逻辑相关函数
bool CanMoveDown();
bool CanMoveLeft();
bool CanMoveRight();
void MoveDown();
void MoveLeft();
void MoveRight();
void Rotate();
void DropDown();
void Fixing();
void DeleteOneLine(int number);
void DeleteLines();
bool GameOver();
void ComputeTarget();
void Restart();

// 绘图函数
void TDrawScreen(HDC hdc, HWND hWnd);
