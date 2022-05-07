#include "Ball.h"
using namespace std;

Ball::Ball(std::string b)
{
    this->b = b;
    bE="";
    for(int i=0;i < b.length() ; i++)
    {
        bE+=" ";
    }
    reset(35,19);

}

void Ball::reset(int x,int y)
{
    this->isMoving=false;
    delDraw();
    this->x=x;
    this->y=y;
    newPosDraw();
    up=NULL;
    left=NULL;

}

Ball::~Ball()
{
    //dtor
}

void Ball::newPosDraw()
{
    d.draw(x,y,b);
}

void Ball::delDraw()
{
    d.draw(x,y,bE);
}

void Ball::startMove()
{
    int start;
    isMoving=true;

    srand (time(NULL));

    start = rand() % 2;
    delDraw();
    if(start == 0)
    {
        left=true;
        x--;
    }

    else
    {
        left=false;
        x++;
    }
    up=true;
    y--;
    newPosDraw();
}

bool Ball::continueMove()
{
    delDraw();
    if(up)
        y--;
    else
        y++;
    if(left)
        x--;
    else
        x++;

    if(d.minY+1 == y)
    {
        up = !up;
    }
    if(d.maxY == y)
    {
        return false;
    }

    if(d.minX+1 == x || (d.maxX+2) == x)
    {
        left = !left;
    }
    newPosDraw();
    return true;

}
void Ball::collision(int centro,string collider)
{
    if(x < centro)
    {
        left = true;
    }
    else if(x > centro)
    {
        left = false;
    }
    else
    {
        srand (time(NULL));
        int band = rand() % 2;
        if(band == 0)
        {
            left=true;
        }

        else
        {
            left=false;
        }
    }

    if(collider == "Block")
    {
        up = false;
    }
    else if(collider == "Player")
    {
        up = true;
    }
    continueMove();
}




