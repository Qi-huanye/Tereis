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

/**
 * @brief Win32 程序入口函数，负责完成应用启动初始化并进入消息循环。
 *
 * 该函数会加载窗口标题与窗口类名称资源，注册窗口类，创建主窗口，
 * 然后加载快捷键资源并持续分发系统消息，直到程序退出。
 *
 * @return int 程序退出时返回消息循环中的退出码。
 */
int APIENTRY _tWinMain(HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPTSTR lpCmdLine,
    int nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadString(hInstance, IDC_TETRIS, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_TETRIS));
    MSG msg;

    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int)msg.wParam;
}

/**
 * @brief 注册主窗口所需的窗口类信息。
 *
 * 该函数会设置窗口样式、消息处理函数、图标、光标、背景画刷、
 * 菜单资源和窗口类名，最后调用系统 API 完成注册。
 *
 * @param hInstance 当前程序实例句柄。
 * @return ATOM 注册成功时返回窗口类原子值，失败时返回 0。
 */
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEX wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_TETRIS));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCE(IDC_TETRIS);
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassEx(&wcex);
}

/**
 * @brief 创建主窗口并显示到屏幕上。
 *
 * 该函数会先根据游戏区域尺寸计算实际窗口大小，再创建主窗口，
 * 如果创建成功则显示并刷新窗口，供后续消息循环与绘制逻辑使用。
 *
 * @param hInstance 当前程序实例句柄。
 * @param nCmdShow 窗口显示方式参数。
 * @return BOOL 创建并显示成功返回 TRUE，否则返回 FALSE。
 */
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    RECT rect = { 0, 0, GRID * nWidth, GRID * nHeight };
    AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, TRUE);

    hInst = hInstance;

    HWND hWnd = CreateWindow(
        szWindowClass,
        szTitle,
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        0,
        rect.right - rect.left,
        rect.bottom - rect.top,
        nullptr,
        nullptr,
        hInstance,
        nullptr);

    if (!hWnd)
    {
        return FALSE;
    }

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    return TRUE;
}

/**
 * @brief 主窗口消息处理函数，负责响应菜单、绘制和退出等系统消息。
 *
 * 当前阶段主要处理“关于”和“退出”菜单命令、窗口重绘请求以及销毁消息，
 * 其余未处理的消息统一交给系统默认窗口过程继续处理。
 *
 * @param hWnd 当前窗口句柄。
 * @param message 当前接收到的消息类型。
 * @param wParam 消息附带的参数 1。
 * @param lParam 消息附带的参数 2。
 * @return LRESULT 消息处理结果。
 */
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);

        switch (wmId)
        {
        case IDM_ABOUT:
            DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
            break;
        case IDM_EXIT:
            DestroyWindow(hWnd);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
    }
    break;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        TDrawScreen(hdc, hWnd);
        EndPaint(hWnd, &ps);
    }
    break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }

    return 0;
}

/**
 * @brief “关于”对话框的消息处理函数。
 *
 * 该函数用于初始化关于对话框，并处理用户点击“确定”或“取消”时的关闭操作。
 * 对于未处理的对话框消息，返回 FALSE 交由系统继续处理。
 *
 * @param hDlg 对话框窗口句柄。
 * @param message 当前接收到的对话框消息类型。
 * @param wParam 消息附带的参数 1。
 * @param lParam 消息附带的参数 2。
 * @return INT_PTR 消息已处理返回 TRUE，否则返回 FALSE。
 */
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);

    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }

    return (INT_PTR)FALSE;
}
