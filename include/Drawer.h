#ifndef DRAWER_H
#define DRAWER_H

#include <iostream>
#include <string>
#include <sstream>
#ifdef _WIN32
    #define _WIN32_WINNT 0x0500
    #include <windows.h>
#endif


class Drawer
{
    public:
        Drawer();
        virtual ~Drawer();
        void clear();
        void draw(int x,int y,std::string s);
        #ifdef _WIN32
            void gotoxy(int x,int y);
        #else
            template <class T>;
            inline std::string ToString(const T& t);
            inline std::string gotoxy(const int& x,const int& y);
        #endif

    protected:

    private:
};

#endif // DRAWER_H
