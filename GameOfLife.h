//
// Created by mateu on 3/24/2021.
//

#ifndef GAME_OF_LIFE_GAMEOFLIFE_H
#define GAME_OF_LIFE_GAMEOFLIFE_H

#include "GameEngine.h"

class GameOfLife : public GameEngine {
public:
    explicit GameOfLife(const Config &config)
            : GameEngine(config) {};

    void on_start() override;

    void on_tick() override;

    void on_end() override;

    ~GameOfLife() override;

private:
    bool *board;

};

#endif //GAME_OF_LIFE_GAMEOFLIFE_H
