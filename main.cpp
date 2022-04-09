#include "Player.h"
#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80


using namespace std;



int main()
{
    Player player(3);
    while(true)
    {
        if(kbhit())
        {
            char tecla = getch();
            if(tecla == LEFT) player.moveLeft();
            if(tecla == RIGHT) player.moveRight();

        }
    }
    getch();
}
