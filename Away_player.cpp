#include "Away_player.h"
#include "Ball.h"

Away_player::Away_player(): awayx{13}, awayy{4}, away_score{0}{
}

char Away_player::draw_player(){
    return Player::draw_player();
}

int Away_player::get_playerx(int posx){
    return Player::get_playerx(posx);
}

int Away_player::get_playery(){
    return awayy;
}

void Away_player::set_playerx(int awyx){
    switch (awyplyr){
        case UP:
            if (awayx > 1){
                --awayx;
                Player::set_playerx(awayx);
            }else{
                break;
            }break;
        case DOWN:
            if (awayx+5 < 30){
                ++awayx;
                Player::set_playerx(awayx);
            }else{
                break;
            }break;
        case STOP:
            if (awayx < 13){
                ++awayx;
                Player::set_playerx(awayx);
            }else if (awayx > 13){
                --awayx;
                Player::set_playerx(awayx);
            }else{
                break;
            }break;
        default:
            break;
    }
}

void Away_player::set_playery(int posy){
    posy = awayy;
    Player::set_playery(posy);
}

void Away_player::set_player_score(int score){
    Player::set_player_score(score);
}

int Away_player::get_player_score(){
    return Player::get_player_score();
}

void Away_player::player_movement(Ball &b){
    if (b.getbally() < 40 && awayx > b.getballx()-1 && awayx > 1){
        awyplyr = UP;
    }
    if (b.getbally() < 40 && (awayx+4) < b.getballx()+1 && (awayx+5) < 30){
        awyplyr = DOWN;
    }
    if (b.getbally() > 40 && (awayx > 1 || (awayx+5) < 30)){
       awyplyr = STOP;
    }
    Player::player_movement(b);
}

