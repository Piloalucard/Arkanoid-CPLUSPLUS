#ifndef BLOCK_H
#define BLOCK_H
#include "Ball.h"


class Block
{
    public:
        Drawer d;
        int x,y,id;
        std::string charac,characEsp;
        Block();
        Block(std::string c,int x,int y,int id);
        virtual ~Block();

        void redraw();
        void delDraw();
        bool collision(int x,int y);
        int getCX();

        bool operator == (const Block&) const;
        bool operator != (const Block&) const;
        Block& operator = (const Block&);


    protected:

    private:
};

#endif // BLOCK_H
