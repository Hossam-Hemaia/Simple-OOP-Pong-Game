#include "Util_game.h"
#include <iostream>
#include <windows.h>
#include <chrono>
#include <thread>

void drawmap(Pitch &g, Ball &b, std::vector<std::unique_ptr<Player>> &p){
    //std::this_thread::sleep_for(std::chrono::microseconds(200));
    LockWindowUpdate(GetConsoleWindow());
    system("cls");
    for (size_t k = 0; k < 31; ++k){
        for (size_t j = 0; j < 82; ++j){
            if (g.map[k] == g.map[p.at(1)->get_playerx(k)] && g.map[j] == g.map[p.at(1)->get_playery()]){
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                        std::cout << p.at(1)->draw_player();
            }else if (g.map[k] == g.map[p.at(0)->get_playerx(k)] && g.map[j] == g.map[p.at(0)->get_playery()]){
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                        std::cout << p.at(0)->draw_player();
            }else if (g.map[k] == g.map[b.getballx()] && g.map[j] == g.map[b.getbally()]){
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
                        std::cout << b.drawball();
            }else{
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
                std::cout << g.map[k][j]; 
            }
        }std::cout << std::endl;
    }
    LockWindowUpdate(NULL);
}

void game_inputs(Ball &b, std::vector<std::unique_ptr<Player>> &p){
    for (auto &pl:p){
        pl->set_playery(0);
        pl->player_movement(b);
        b.ballstarter(pl);
    }
}

void game_logic(Ball &b, std::vector<std::unique_ptr<Player>> &p){
    for (auto &pl:p){
        pl->set_playerx(0);
    }
    b.ball_kick();
    for (auto &pl:p){
        if (b.getbally() == 1 && (b.getbally()+75) == pl->get_playery() ){
            pl->set_player_score(1);
            pl->set_playerx(13);
            b.setballx();
            b.setbally();
            b.startdirection = Ball::STOP;
        }else if (b.getbally() == 78 && (b.getbally()-74) == pl->get_playery()){
            pl->set_player_score(1);
            pl->set_playerx(13);
            b.setballx();
            b.setbally();
            b.startdirection = Ball::STOP;
        }
    }
}