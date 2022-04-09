#include "Player.h"

#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80
#define SPACE 32


using namespace std;



int main()
{
    Player player(3);

    Ball ball("*");
    while(player.lifes > 0)
    {

        if(kbhit())
        {

            char tecla = getch();
            if(tecla == LEFT) player.moveLeft();
            if(tecla == RIGHT) player.moveRight();

            if(tecla == SPACE)
            {
                if(!ball.isMoving)
                {
                    ball.startMove();
                }


            }
            else if(!ball.isMoving)
            {
                ball.reset(player.getCX(),player.y-1);

            }


        }
        else
        {
            if(ball.isMoving)
            {

                if(!ball.continueMove())
                {

                    player.lifes -=1;
                    player.drawLife();
                    ball.reset(player.getCX(),player.y-1);
                }
                else if(player.collision(ball.x,ball.y))
                {
                    ball.collisionMove();
                    player.redraw();
                }

            }
            Sleep(100);
        }






    }
    Drawer d;
    d.draw(30,11,"GAME OVER");
    getch();
}
