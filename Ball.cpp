#include "Ball.h"
#include <cstdlib>

void Ball::ballstarter(std::unique_ptr<Player> &p){
    if (GetAsyncKeyState(VK_SPACE) && startdirection == STOP){
        startdirection = (((eDirection)((rand()%2) + 1)) == LEFT)? LEFT : RIGHT;
    }
    if ((ballx) == p->get_playerx(ballx) && (bally+1) == p->get_playery()){ //home player bounce
        startdirection = ((eDirection)((rand()%3) + 1));
    }
     if ((ballx) == p->get_playerx(ballx) && (bally-1) == p->get_playery()){ //away player bounce
        startdirection = ((eDirection)((rand()%3) + 4));
    }
    if ((ballx+1) == 30 && startdirection == UP && (bally-1) != p->get_playery()){ // down wall bounce
        startdirection = DOWN;
    }else if ((ballx+1) == 30 && startdirection == UP && (bally-1) == p->get_playery() && ballx == p->get_playerx(ballx)){
        startdirection = ((eDirection)((rand()%2) + 4));
    }
    if ((ballx-1) == 0 && startdirection == DOWN && (bally-1) != p->get_playery()){ // up wall bounce
        startdirection = UP;
    }else if ((ballx-1) == 0 && startdirection == DOWN && (bally-1) == p->get_playery() && ballx == p->get_playerx(ballx)){
        startdirection = ((eDirection)((rand()%2) + 5));
    }
    if ((ballx+1) == 30 && startdirection == OPdown && (bally+1) != p->get_playery()){ // down wall bounce
        startdirection = OPup;
    }else if ((ballx+1) == 30 && startdirection == OPdown && (bally+1) == p->get_playery() && ballx == p->get_playerx(ballx)){
        startdirection = ((eDirection)((rand()%2) + 2));
    }
    if ((ballx-1) == 0 && startdirection == OPup && (bally+1) != p->get_playery()){ // up wall bounce
        startdirection = OPdown;
    }else if ((ballx-1) == 0 && startdirection == OPup && (bally+1) == p->get_playery() && ballx == p->get_playerx(ballx)){
        startdirection = ((eDirection)((rand()%2) + 1));
    }
    if ((ballx+1) == 30 && startdirection == LEFT && (bally-1) == p->get_playery() && ballx == p->get_playerx(ballx)){
        startdirection = ((eDirection)((rand()%2) + 4));
    }
    if ((ballx+1) == 30 && startdirection == RIGHT && (bally+1) == p->get_playery() && ballx == p->get_playerx(ballx)){
        startdirection = ((eDirection)((rand()%2) + 2));
    }
    if ((ballx-1) == 0 && startdirection == LEFT && (bally-1) == p->get_playery() && ballx == p->get_playerx(ballx)){
        startdirection = ((eDirection)((rand()%2) + 5));
    }
    if ((ballx-1) == 0 && startdirection == RIGHT && (bally+1) == p->get_playery() && ballx == p->get_playerx(ballx)){
        startdirection = ((eDirection)((rand()%2) + 2));
    }
}

Ball::Ball():ballx{15}, bally{40}{
}

Ball::~Ball(){
}

void Ball::ball_kick(){
    switch (startdirection){
        case RIGHT:
               ++bally;
            break;
        case UP:
                ++ballx;
                --bally;
            break;
        case OPup:
                --ballx;
                ++bally;
            break;
        case DOWN:
                --ballx;
                --bally;
            break;
        case OPdown:
                ++ballx;
                ++bally;
            break;
        case LEFT:
                --bally;
            break;
        default:
            break;
    }
}