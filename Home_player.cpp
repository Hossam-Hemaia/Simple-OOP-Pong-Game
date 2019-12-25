#include "Home_player.h"
#include "Ball.h"

Home_player::Home_player(): homex{13}, homey{76}, home_score{0}{
}

char Home_player::draw_player(){
    return Player::draw_player();
}

int Home_player::get_playerx(int posx){
    return Player::get_playerx(posx);
}

int Home_player::get_playery(){
    return homey;
}

void Home_player::set_playerx(int hmx){
    switch (homplyr){
        case UP:
            if (homex > 1){
                homex -= 1;
                Player::set_playerx(homex);
                homplyr = STOP;
            }break;
        case DOWN:
            if ((homex+5) < 30){
                homex += 1;
                Player::set_playerx(homex);
                homplyr = STOP;
            }break;
        case STOP:
            homex = homex;
            Player::set_playerx(homex);
            break;
        default:
            break;
    }
}

void Home_player::set_playery(int posy){
    posy = homey;
    Player::set_playery(posy);
}

void Home_player::set_player_score(int score){
    Player::set_player_score(score);
}

int Home_player::get_player_score(){
    return Player::get_player_score();
}

void Home_player::player_movement(Ball &b){
    if (GetAsyncKeyState(VK_UP)){
        homplyr = UP;
    }
    if (GetAsyncKeyState(VK_DOWN)){
        homplyr = DOWN;
    }
    Player::player_movement(b);
}
