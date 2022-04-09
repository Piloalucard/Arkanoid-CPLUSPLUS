#ifndef PLAYER_H
#define PLAYER_H
#ifdef _WIN32
    #include <conio.h>
#else
    #include <curses.h>
#endif

#include "Drawer.h"
#include "Ball.h"


class Player
{
    public:
        int lifes,score;
        int x,y;

        Drawer d;
        std::string personaje;
        std::string personajeEsp;
        Player(int lifes);
        void redraw();
        virtual ~Player();

        void moveLeft();
        void moveRight();
        void drawLife();
        void drawScore();

        int getCX();
        bool collision(int x,int y);

    protected:

    private:
        void setLoc(int x,int y);
};

#endif // PLAYER_H
