// A minimal Windows 98 skeleton

#include <windows.h>

LRESULT CALLBACK WindowFunc(HWND, UINT, WPARAM, LPARAM);

char szWinName[] = "MyWin"; // name of window class

int WINAPI WinMain(HINSTANCE hThisInst, HINSTANCE hPrevInst, LPSTR lpszArgs, int nWinMode)
{
    HWND hwnd;
    MSG msg;
    WNDCLASSEX wcl;

    // define a window class
    wcl.cbSize = sizeof(WNDCLASSEX);

    wcl.hInstance = hThisInst;      // handle to this instance
    wcl.lpszClassName = szWinName;  // window class name
    wcl.lpfnWndProc = WindowFunc;   // window function
    wcl.style = 0;                  // default style

    wcl.hIcon = LoadIcon(NULL, IDI_APPLICATION);    // standard icon
    wcl.hIconSm = LoadIcon(NULL, IDI_WINLOGO);      // small icon
    wcl.hCursor = LoadCursor(NULL, IDC_CROSS);      // cursor style

    wcl.lpszMenuName = NULL;    // no menu
    wcl.cbClsExtra = 0;         // no extra info needed
    wcl.cbWndExtra = 0;         // no extra info needed

    // make the window background white
    wcl.hbrBackground = (HBRUSH) GetStockObject(WHITE_BRUSH);

    // register the window class
    if (!RegisterClassEx(&wcl)) return 0;

    // now that the window class has been registered, a window can be created
    hwnd = CreateWindow(
        szWinName,              // name of window class
        "Windows 98 Skeleton",  // title
        WS_OVERLAPPEDWINDOW,    // window style - normal
        CW_USEDEFAULT,          // x coordinate - let windows decide
        CW_USEDEFAULT,          // y coordinate - let windows decide
        CW_USEDEFAULT,          // width - let windows decide
        CW_USEDEFAULT,          // height - let windows decide
        HWND_DESKTOP,           // no parent window
        NULL,                   // no menu
        hThisInst,              // handle of this instance of the program
        NULL                    // no additional arguments
    );

    // display the window
    ShowWindow(hwnd, nWinMode);
    UpdateWindow(hwnd);

    // create the message loop
    while(GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg); // translate keyboard messages
        DispatchMessage(&msg);  // return control to Windows 98
    }

    return msg.wParam;
}

/* This function is called by Windows 98 and is passed messages from the message queue. */
LRESULT CALLBACK WindowFunc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch(message) {
        case WM_DESTROY:	// terminate the program
            PostQuitMessage(0);
            break;
        default:
            // let windows process any messages not specified in the preceding switch statement
            return DefWindowProc(hwnd, message, wParam, lParam);
    }

    return 0;
}