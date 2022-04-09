
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

int main()
{

    cout << gotoxy(2,4) << "Hola" << endl;
}
