#ifndef PLAYER_H
#define PLAYER_H
#ifdef _WIN32
    #include <conio.h>
#else
    #include <curses.h>
#endif

#include "Drawer.h"


class Player
{
    public:
        int vidas;
        int x,y;
        int const maxX=60,minX=1;
        Drawer d;
        std::string personaje;
        std::string personajeEsp;
        Player(int vidas);
        virtual ~Player();

        void moveLeft();
        void moveRight();


    protected:

    private:
        void setLoc(int x,int y);
};

#endif // PLAYER_H
