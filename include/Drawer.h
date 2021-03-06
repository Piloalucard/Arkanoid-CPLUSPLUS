#ifndef DRAWER_H
#define DRAWER_H

#include <iostream>
#include <string>
#include <sstream>
#ifdef _WIN32
    #define _WIN32_WINNT 0x0500
    #include <windows.h>
#endif
using namespace std;

class Drawer
{
    public:
        Drawer();
        int const maxX=61,minX=2,minY=2,maxY=22;
        virtual ~Drawer();
        void clear();
        void draw(int x,int y,string s);
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

    protected:

    private:
};

#endif // DRAWER_H
