#include <iostream>
#include "SimpleConsoleRenderer.h"
#include "GameOfLife.h"

int main() {
    const unsigned size_x = 5;
    const unsigned size_y = 5;

    GameEngine::Config config{
            .framerate = 30,
            .renderer = new SimpleConsoleRenderer
    };
    auto data = new bool[size_x * size_y];

    memset(data, true, size_x * size_y);

    data[11] = true;
    data[12] = true;
    data[13] = true;

    Board board(data, size_x, size_y);

    GameOfLife game_of_life(board, config);
    game_of_life.play();
}
