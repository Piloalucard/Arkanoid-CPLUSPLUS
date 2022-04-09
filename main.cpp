
#include <iostream>
#include <string>
#include <sstream>
#ifdef _WIN32
    #include <windows.h>
#endif



using namespace std;

void clear()
{
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}

#ifdef _WIN32
     void gotoxy(int x,int y)
     {
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
    }
#else
    template <class T>
    inline string ToString(const T& t)
    {
        stringstream ss;
        ss << t;
        return ss.str();
    }

    inline string gotoxy(const int& x,const int& y)
    {
        return "\33[" + ToString(x) + ";" + ToString(y) + "H";
    }
#endif


int main()
{
    gotoxy(2,4);
    cout << "Hola" << endl;
}
