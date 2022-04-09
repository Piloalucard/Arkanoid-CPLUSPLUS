#ifndef BALL_H
#define BALL_H
#include <time.h>
#include "Player.h"

class Ball
{
    public:
        int x,y;
        bool up,left;
        bool isMoving;
        std::string b,bE;
        Drawer d;
        Ball(std::string b);
        virtual ~Ball();

        void startMove();
        bool continueMove();
        void collisionMove();

        void reset(int x,int y);

    protected:

    private:
        void newPosDraw();
        void delDraw();
};

#endif // BALL_H
