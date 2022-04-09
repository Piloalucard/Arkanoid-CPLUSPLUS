#include "Player.h"
#include <iterator>
#include <list>

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
    Player player(5);
    Drawer d;
    Ball ball("*");
    string dark="||",clear="||";
    list<Block> blocks;
    while(player.lifes > 0)
    {
        if(blocks.empty())
        {
            int id=0;
            for(int i=d.minX+1; i<=d.maxX; i+=3)
            {
                for(int j=d.minY+1; j<(d.maxY/2); j++)
                {
                    if((i+j)%2 == 1)
                    {
                        Block b(dark,i,j,id);
                        blocks.push_back(b);
                    }
                    else
                    {
                        Block b(clear,i,j,id);
                        blocks.push_back(b);
                    }
                    id++;

                }
            }



        }
        if(ball.y < (d.maxY/2))
        {
            std::list<Block>::iterator it;
            for (it = blocks.begin(); it != blocks.end(); it++)
            {

                if(it->collision(ball.x,ball.y))
                {
                    blocks.erase(it);
                    it->delDraw();
                    player.score+=10;
                    player.drawScore();
                    ball.collision();



                }


            }

        }


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
                    ball.collision();
                    player.redraw();
                }

            }
            Sleep(100);
        }






    }

    d.draw(28,14,"GAME OVER!");

    getch();
    getch();
}
