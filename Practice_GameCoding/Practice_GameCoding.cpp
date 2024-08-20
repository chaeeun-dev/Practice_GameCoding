﻿// Practice_GameCoding.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "pch.h"    // 꼭 맨 위에 작성하기!
#include "Practice_GameCoding.h"
#include "Game.h"

#define MAX_LOADSTRING 100

int mousePosX;
int mousePosY;

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
HWND g_hwnd;    // 전역 핸들 번호 추가

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // 1) 윈도우 창 정보 등록
    MyRegisterClass(hInstance);

    // 2) 윈도우 창 생성 및 애플리케이션 초기화
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    MSG msg = {};

    Game game;
    game.Init(g_hwnd);

    // 기본 메시지 루프입니다:
    while (msg.message != WM_QUIT)      // 창 끄면 바로 프로그램 종료되도록
    {
        if (::PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))    // 메시지가 드물게 있음
        {
            TranslateMessage(&msg);     // 추가적인 이벤트를 만들어줌
            DispatchMessage(&msg);      // 메시지를 처리해줌 (둘 거의 비슷)

        }
        else
        {
            // 게임 로직
            game.Update();
            game.Render();
        }
    }

    return (int) msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex = {};

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_PRACTICEGAMECODING));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName = nullptr;    // menu
    wcex.lpszClassName = L"Practice_GameCoding";    // 윈도우 클래스의 키(이름)
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   RECT windowRect = { 0, 0, 800, 600 };
   ::AdjustWindowRect(&windowRect, WS_OVERLAPPEDWINDOW, false);     // 좌우상하 좌표를 윈도우 크기에 맞춤

   HWND hWnd = CreateWindowW(L"Practice_GameCoding", L"Client", WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, windowRect.right - windowRect.left, windowRect.bottom - windowRect.top, nullptr, nullptr, hInstance, nullptr);

   g_hwnd = hWnd;

   if (!hWnd)
   {
      return FALSE;
   }

   ::ShowWindow(hWnd, nCmdShow);
   ::UpdateWindow(hWnd);

   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
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
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...

            // 마우스 위치 그리는 코드
            WCHAR buffer[100];
            ::wsprintf(buffer, L"(%d,%d)", mousePosX, mousePosY);      // 포맷 지정해 마우스 위치 넣음
            ::TextOut(hdc, 100, 100, buffer, ::wcslen(buffer));
            EndPaint(hWnd, &ps);
        }
        break;
    //case WM_MOUSEMOVE:
    //    mousePosX = LOWORD(lParam);     // x 좌표를 가져옴
    //    mousePosY = HIWORD(lParam);     // y 좌표를 가져옴
    //    ::InvalidateRect(hWnd, nullptr, true);  // 강제로 WM_PAINT

    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}