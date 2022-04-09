#include "Player.h"

using namespace std;

Player::Player(int lifes)
{
    this->lifes = lifes;
    this->x=30;
    this->y=20;
    this->personaje="$$$$$$$$$$$";
    this->personajeEsp="";
    for(int i=0; i<personaje.length();i++)
    {
        this->personajeEsp+=" ";
    }

    this->score = 0;
    d.draw(x,y,personaje);
    drawScore();
    drawLife();


}

Player::~Player()
{
    //dtor
}

void Player::setLoc(int x,int y)
{
    this->x=x;
    this->y=y;
}

void Player::moveLeft()
{
    if(x > d.minX)
    {
        d.draw(x,y,personajeEsp);
        x--;
        d.draw(x,y,personaje);
    }

}

void Player::moveRight()
{
    if(x < d.maxX)
    {
        d.draw(x,y,personajeEsp);
        x++;
        d.draw(x,y,personaje);
    }

}

void Player::redraw()
{
    d.draw(x,y,personaje);
}


void Player::drawLife()
{

    string hearts="Hearts: ";
    for(int i=0;i<lifes;i++)
    {
        hearts+=" ";
    }
    string aux="";
    for(int i=0;i<=hearts.length();i++)
    {
        aux+=" ";
    }
    d.draw(5,1,aux);
    d.draw(5,1,hearts);
}
void Player::drawScore()
{

    stringstream ss;
    ss << score;
    string str = ss.str();
    string sc="Score: "+ str;
    string aux="";
    for(int i=0;i<=sc.length();i++)
    {d.draw(x,y,personaje);
        aux+=" ";
    }
    d.draw(50,1,aux);
    d.draw(50,1,sc);
}

int Player::getCX()
{
    return x+5;
}


bool Player::collision(int x, int y)
{
    if((y) == this->y)
    {
        if(x >= this->x && x <= (this->x+personaje.length()))
        {
            return true;
        }
    }
    return false;
}






