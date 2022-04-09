#ifndef PLAYER_H
#define PLAYER_H
#include <conio.h>
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

        moveLeft();
        moveRight();


    protected:

    private:
        setLoc(int x,int y);
};

#endif // PLAYER_H
