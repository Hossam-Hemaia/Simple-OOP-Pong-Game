#include <iostream>
#include <windows.h>
#include "Util_game.h"
#include "Player.h"
#include "Home_player.h"
#include "Away_player.h"
#include "Ball.h"
#include "Pitch.h"
#include <vector>
#include <ctime>
#include <memory>
#include <iomanip>

int main(){
    bool gamerunning = true;
    Pitch ground;
    Ball ball;
    srand(time(NULL));
    std::unique_ptr<Player> phome = std::make_unique<Home_player>();
    std::unique_ptr<Player> paway = std::make_unique<Away_player>();
    std::vector<std::unique_ptr<Player>> players;
    players.push_back(std::move(phome));
    players.push_back(std::move(paway));
    while (gamerunning == true){
        drawmap(ground, ball, players);
        game_inputs(ball, players);
        game_logic( ball, players);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        std::cout << "Away Player Score: " << players.at(1)->get_player_score();
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        std::cout << std::setw(60) << "Home Player Score: "<< players.at(0)->get_player_score() << std::endl;
    }
    return 0;
}