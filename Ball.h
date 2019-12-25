#ifndef _Ball_H_
#define _Ball_H_
#include "Pitch.h"
#include "Away_player.h"
#include "Player.h"
#include "Pitch.h"
#include <windows.h>
#include <memory>

class Ball{
    friend class Away_player;
private:
    int ballx;
    int bally;
public:
    enum eDirection {STOP = 0, UP = 1, LEFT = 2, DOWN = 3, OPup = 4, RIGHT = 5, OPdown = 6};
    eDirection startdirection = STOP;
    Ball();
    ~Ball();
    char drawball(){return char(254);}
    void setballx(){ballx = 15;}
    int getballx(){return ballx;}
    void setbally(){bally = 40;}
    int getbally(){return bally;}
    void ballstarter(std::unique_ptr<Player> &p);
    void ball_kick();
};

#endif // _Ball_H_
