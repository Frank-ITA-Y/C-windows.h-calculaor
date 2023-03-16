# CALCULATOR C++ WINDWOS.h
the _**~~best~~**_ **calculator** in the _world_ **(fake news)**

## INSTALLATION
if you want install it you can use 2 ways:
1. **double** _click_ ~~on~~ _calculator.exe_
2. open **new** _terminal_ in the **folder bin**
    - write ```./calculator.exe```
    - if the file don't exist write in the **folder scr/cpp-file** ```g++ ./main.cpp -o main.exe -lgdi32``` after that  write```./calculator.exe```
    - or ```mingw32 make MakeFile```
### LIBRARIES FOR DEVELOPMENT OF THIS CALCULATOR
```c++
    #include  <iostream>
    #include  <windows.h>
    #include  <commctrl.h>
    #include  <windowsx.h>
    #include  <string>
```
entry point
```c++
    INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lCmdLine, int nCmdShow)
```
"proc" definition
```c++
    LRESULT CALLBACK WndCalcProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
```
add the {}
Standard Window params
```c++
    WNDCLASSEX wc;
    ZeroMemory(&wc, sizeof(WNDCLASSEX));
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.cbClsExtra = 0;
    wc.hInstance = hInstance;
    wc.cbWndExtra = 0;
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.hIcon = NULL;
    wc.hIconSm = NULL;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = NULL;
    wc.lpszMenuName = NULL;
    wc.lpszClassName = "wndCalcClass";
    wc.lpfnWndProc = WndCalcProc;
```

## HELP ME

I've some problem with GUI if you want to modify the graphics of app please contact me with a repository

## **LICENCE**

- MIT licence
