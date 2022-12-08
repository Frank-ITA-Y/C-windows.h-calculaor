#include <iostream>
#include <windows.h>
#include <commctrl.h>
#include <windowsx.h>
#include <string>

HWND hwndWNDMain;
HWND hwndTXT_input;
HWND hwndTXT_output;
HWND hwndBTN[4][4];
std::string symbols[4][4] = { {"1", "2", "3", "+"}, {"4", "5", "6", "-"}, {"7", "8", "9", "X"}, {" ", "0", "=", "/"} };
float a = 0, b = 0;
int check = 0;

LRESULT CALLBACK WndCalcProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam){
    switch (message)
    {
    case WM_CREATE:
        std::cout << "WM_CREATE !!!\n";
        hwndTXT_input = CreateWindow(
                                    WC_EDIT, "",
                                    WS_CHILD | WS_VISIBLE | ES_RIGHT,
                                    15, 10,
                                    270, 25,
                                    hWnd, NULL, NULL, NULL
                                    );
        hwndTXT_output = CreateWindow(
                                    WC_EDIT, "",
                                    WS_CHILD | WS_VISIBLE | ES_RIGHT,
                                    15, 55,
                                    270, 25,
                                    hWnd, NULL, NULL, NULL
                                    );
        for (int i = 0, id = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                hwndBTN[i][j] = CreateWindow(
                                    WC_BUTTON, &(symbols[i][j])[0],
                                    WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
                                    15+(j*70), 130+(i*70),
                                    60, 60,
                                    hWnd, (HMENU)id, NULL, NULL
                                    ); 
                id++;
            }
            
        }
        
        break;
    case WM_COMMAND:
        switch (HIWORD(wParam))
        {
        case BN_CLICKED:
            switch (LOWORD(wParam))
            {
                case 0:
                {
                    char buff[1000];
                    std::cout << "hai premuto 1\n";
                    Edit_GetText(hwndTXT_input, buff, 1000);
                    std::string str(buff);
                    str = str + "1";
                    Edit_SetText(hwndTXT_input, &str[0]);
                    break;
                }
                case 1:
                {
                    char buff[1000];
                    std::cout << "hai premuto 2\n";
                    Edit_GetText(hwndTXT_input, buff, 1000);
                    std::string str(buff);
                    str = str + "2";
                    Edit_SetText(hwndTXT_input, &str[0]);
                    break;
                }
                case 2:
                {
                    char buff[1000];
                    std::cout << "hai premuto 3\n";
                    Edit_GetText(hwndTXT_input, buff, 1000);
                    std::string str(buff);
                    str = str + "3";
                    Edit_SetText(hwndTXT_input, &str[0]);
                    break;
                }
                case 3://+
                {
                    char buff[1000];
                    Edit_GetText(hwndTXT_input, buff, 1000);
                    std::string str(buff);
                    if (check == 0)
                    {
                        Edit_SetText(hwndTXT_input, "");
                        a = std::stof(str);
                        check = 2;
                    }
                    
                    break;
                }
                case 4:
                {
                    char buff[1000];
                    std::cout << "hai premuto 4\n";
                    Edit_GetText(hwndTXT_input, buff, 1000);
                    std::string str(buff);
                    str = str + "4";
                    Edit_SetText(hwndTXT_input, &str[0]);
                    break;
                }    
                case 5:
                {
                    char buff[1000];
                    std::cout << "hai premuto 5\n";
                    Edit_GetText(hwndTXT_input, buff, 1000);
                    std::string str(buff);
                    str = str + "5";
                    Edit_SetText(hwndTXT_input, &str[0]);
                    break;
                }
                case 6:
                {
                    char buff[1000];
                    std::cout << "hai premuto 6\n";
                    Edit_GetText(hwndTXT_input, buff, 1000);
                    std::string str(buff);
                    str = str + "6";
                    Edit_SetText(hwndTXT_input, &str[0]);
                    break;
                }
                case 7://meno
                {
                    char buff[1000];
                    Edit_GetText(hwndTXT_input, buff, 1000);
                    std::string str(buff);
                    if (check == 0)
                    {
                        Edit_SetText(hwndTXT_input, "");
                        a = std::stof(str);
                        check = 3;
                    }
                    break;
                }
                case 8:
                {
                    char buff[1000];
                    std::cout << "hai premuto 7\n";
                    Edit_GetText(hwndTXT_input, buff, 1000);
                    std::string str(buff);
                    str = str + "7";
                    Edit_SetText(hwndTXT_input, &str[0]);
                    break;
                }
                case 9:
                {
                    char buff[1000];
                    std::cout << "hai premuto 8\n";
                    Edit_GetText(hwndTXT_input, buff, 1000);
                    std::string str(buff);
                    str = str + "8";
                    Edit_SetText(hwndTXT_input, &str[0]);
                    break;
                }
                case 10:
                {
                    char buff[1000];
                    std::cout << "hai premuto 9\n";
                    Edit_GetText(hwndTXT_input, buff, 1000);
                    std::string str(buff);
                    str = str + "9";
                    Edit_SetText(hwndTXT_input, &str[0]);
                    break;
                }
                case 11://per
                {
                    char buff[1000];
                    Edit_GetText(hwndTXT_input, buff, 1000);
                    std::string str(buff);
                    if (check == 0)
                    {
                        Edit_SetText(hwndTXT_input, "");
                        a = std::stof(str);
                        check = 4;
                    }
                    break;
                }
                case 12://vuoto
                {    
                    break;
                }
                case 13:
                {
                    char buff[1000];
                    std::cout << "hai premuto 0\n";
                    Edit_GetText(hwndTXT_input, buff, 1000);
                    std::string str(buff);
                    str = str + "0";
                    Edit_SetText(hwndTXT_input, &str[0]);
                    break;
                }
                case 14://=
                {
                    std::cout << "=\n";
                    char buff[1000];
                    Edit_GetText(hwndTXT_input, buff, 1000);
                    std::string str(buff);
                    b = std::stof(str);
                    if (check == 2)
                    {
                        std::cout << "SOMMA\n";
                        std::string results = std::to_string(a + b);
                        Edit_SetText(hwndTXT_output, &results[0]);
                        Edit_SetText(hwndTXT_input, "");
                        check = 0;
                    }
                    else if(check == 3) {
                        std::cout << "DIFFBRO\n";
                        std::string results = std::to_string(a - b);
                        Edit_SetText(hwndTXT_output, &results[0]);
                        Edit_SetText(hwndTXT_input, "");
                        check = 0;
                    }
                    else if(check == 4) {
                        std::cout << "Ecco il mio prodotto (voce sixuyle)\n";
                        std::string results = std::to_string(a * b);
                        Edit_SetText(hwndTXT_output, &results[0]);
                        Edit_SetText(hwndTXT_input, "");
                        check = 0;
                    }
                    else if(check == 5) {
                        std::cout << "Ce lo stiamo dividendo tutto\n";
                        if(b != 0){
                            std::string results = std::to_string(a / b);
                            Edit_SetText(hwndTXT_output, &results[0]);
                            Edit_SetText(hwndTXT_input, "");
                        }
                        else{
                            Edit_SetText(hwndTXT_output, "Err.DIVISIONE 0(V.S.)per questo farei tutto!");
                            Edit_SetText(hwndTXT_input, "");
                        }
                        
                        check = 0;   
                    }
                    break;
                }
                case 15:
                {
                    char buff[1000];
                    Edit_GetText(hwndTXT_input, buff, 1000);
                    std::string str(buff);
                    if (check == 0)
                    {
                        Edit_SetText(hwndTXT_input, "");
                        a = std::stof(str);
                        check = 5;
                    }
                    break;
                }
            }
            break;
        }    
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
        break;
    }
}

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lCmdLine, int nCmdShow){
    WNDCLASSEX wc;
    MSG msg;
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

    if (!RegisterClassEx(&wc))
    {
        MessageBox(NULL,"Errore Registrazione Classe Finestra", "ERRORE", MB_OK | MB_ICONERROR);
        return -1;
    }
    hwndWNDMain = CreateWindow(
                            "wndCalcClass", "Calcolatrice",
                            WS_BORDER | WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU | WS_VISIBLE,
                            CW_USEDEFAULT, CW_USEDEFAULT,
                            310, 450,
                            NULL, NULL, hInstance, NULL
                            );
    if (!hwndWNDMain)
    {
        MessageBox(NULL,"Errore Creazione Finestra", "ERRORE", MB_OK | MB_ICONERROR);
        return -2;
    }
    ShowWindow(hwndWNDMain, SW_SHOWNORMAL);
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}
