#include "Block.h"
using namespace std;

Block::Block(){}

Block::Block(std::string c,int x,int y,int id)
{
    charac=c;
    this->characEsp="";
    for(int i=0; i<charac.length();i++)
    {
        this->characEsp+=" ";
    }
    this->x=x;
    this->y=y;
    redraw();
    this->id=id;
}

Block::~Block()
{

}

void Block::redraw()
{
    d.draw(x,y,charac);
}

void Block::delDraw()
{
    d.draw(x,y,characEsp);
}

bool Block::collision(int x, int y)
{
    if((y) == this->y)
    {
        if(x >= this->x && x <= (this->x+charac.length()))
        {
            return true;
        }
    }
    return false;
}

int Block::getCX()
{
    float c=0.0f;
    for(int i=0; i<this->charac.length();i++)
    {
        c = c+1.0f;
    }
    c = c / 2;
    int aux = int(c);
    if((c-aux) == 0.5)
    {
        c = c + 0.5;
        aux = int (c);
    }

    return x+aux;
}


bool Block::operator==(const Block& b) const
{
    return this->id == b.id;
}

bool Block::operator!=(const Block& b) const
{
    return this->id != b.id;
}

Block& Block::operator=(const Block& b)
{
    x=b.x;
    y=b.y;
    id=b.id;
    charac=b.charac;
    characEsp=b.characEsp;

    return *this;
}

