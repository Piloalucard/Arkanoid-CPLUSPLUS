#include "Player.h"

Player::Player(int vidas)
{
    this->vidas = vidas;
    this->x=30;
    this->y=20;
    this->personaje="----------";
    this->personajeEsp="          ";
    d.draw(x,y,personaje);

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
    if(x > minX)
    {
        d.draw(x,y,personajeEsp);
        x--;
        d.draw(x,y,personaje);
    }

}

void Player::moveRight()
{
    if(x < maxX)
    {
        d.draw(x,y,personajeEsp);
        x++;
        d.draw(x,y,personaje);
    }

}






