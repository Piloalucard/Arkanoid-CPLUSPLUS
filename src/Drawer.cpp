#include "Drawer.h"

using namespace std;

Drawer::Drawer()
{
    #ifdef _WIN32
        HWND console = GetConsoleWindow();
        RECT ConsoleRect;
        GetWindowRect(console, &ConsoleRect);
        MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 610, 440, TRUE);
        HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

        CONSOLE_CURSOR_INFO     cursorInfo;

        GetConsoleCursorInfo(out, &cursorInfo);
        cursorInfo.bVisible = false;
        SetConsoleCursorInfo(out, &cursorInfo);
    #else
        cout << "\e[8;610;440t";
    #endif // _WIN32
}

Drawer::~Drawer()
{
    //dtor
}

void Drawer::clear()
{
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}


void Drawer::draw(int x,int y,string s)
{
    #ifdef _WIN32
        gotoxy(x,y);
        cout << s << endl;
    #else
        cout << gotoxy(x,y) << s << endl;
    #endif

}

