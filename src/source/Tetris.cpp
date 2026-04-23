// Tetris.cpp : 程序入口、窗口初始化与消息处理

#include "stdafx.h"
#include "Tetris.h"

#define MAX_LOADSTRING 100

HINSTANCE hInst;
TCHAR szTitle[MAX_LOADSTRING];
TCHAR szWindowClass[MAX_LOADSTRING];

ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPTSTR lpCmdLine,
    int nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);
    // TODO(作业1): 补全 Win32 程序入口函数。
    return 0;
}

ATOM MyRegisterClass(HINSTANCE hInstance)
{
    // TODO(作业2): 注册窗口类。
    UNREFERENCED_PARAMETER(hInstance);
    return 0;
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    // TODO(作业3): 创建并显示主窗口。
    UNREFERENCED_PARAMETER(hInstance);
    UNREFERENCED_PARAMETER(nCmdShow);
    return FALSE;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    // TODO(作业4): 补全主窗口消息处理函数。
    return DefWindowProc(hWnd, message, wParam, lParam);
}

INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    // TODO(作业5): 补全“关于”对话框的消息处理。
    UNREFERENCED_PARAMETER(hDlg);
    UNREFERENCED_PARAMETER(message);
    UNREFERENCED_PARAMETER(wParam);
    return (INT_PTR)FALSE;
}
