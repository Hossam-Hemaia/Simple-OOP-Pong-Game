#ifndef _Home_player_H_
#define _Home_player_H_
#include "Player.h"
#include <windows.h>
class Ball;

class Home_player: public Player{
private:
    int homex;
    int homey;
    int home_score;
public:
    enum eDirection{STOP = 0, UP = 1, DOWN = 2};
    eDirection homplyr = STOP;
    Home_player();
    virtual~Home_player() = default;
    virtual char draw_player() override;
    virtual int get_playerx(int posx) override;
    virtual int get_playery() override;
    virtual void set_playerx(int hmx = 0) override;
    virtual void set_playery(int posy) override;
    virtual void set_player_score(int score) override;
    virtual int get_player_score() override;
    virtual void player_movement(Ball &b) override;
};

#endif // _Home_player_H_
