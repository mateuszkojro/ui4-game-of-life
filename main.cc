#include <iostream>
#include "SimpleConsoleRenderer.h"
#include "GameOfLife.h"

int main() {
    GameEngine::Config config;
    config.framerate = 30;
    config.renderer = new SimpleConsoleRenderer;

    auto data = new bool[5 * 5];

    memset(data, true, 5 * 5);

    data[11] = true;
    data[12] = true;
    data[13] = true;

    Board board(data, 5, 5);

    GameOfLife game_of_life(board, config);
    game_of_life.play();

}
