#include "Drawer.h"

using namespace std;

Drawer::Drawer()
{
    #ifdef _WIN32
        HWND console = GetConsoleWindow();
        RECT ConsoleRect;
        GetWindowRect(console, &ConsoleRect);
        MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 610, 400, TRUE);
    #else
        cout << "\e[8;610;400t";
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

#ifdef _WIN32
     void Drawer::gotoxy(int x,int y)
     {
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
    }
#else
    inline string Drawer::ToString(const T& t)
    {
        stringstream ss;
        ss << t;
        return ss.str();
    }

    inline string Drawer::gotoxy(const int& x,const int& y)
    {
        return "\33[" + ToString(x) + ";" + ToString(y) + "H";
    }
#endif

void Drawer::draw(int x,int y,string s)
{
    #ifdef _WIN32
        gotoxy(x,y);
        cout << s << endl;
    #else
        cout << gotoxy(x,y) << s << endl;
    #endif

}

