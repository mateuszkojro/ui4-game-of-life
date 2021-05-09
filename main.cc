#include "SimpleConsoleRenderer.h"
#include "GameOfLife.h"

int main() {
    const unsigned size_x = 5;
    const unsigned size_y = 5;

    GameEngine::Config config{};

    config.framerate = 1;
    config.renderer = new SimpleConsoleRenderer;

    auto data = new bool[size_x * size_y];

    memset(data, false, size_x * size_y);

     Board board(data, size_x, size_y);

    board(1, 1) = true;
    board(1, 2) = true;
    board(1, 3) = true;

    GameOfLife game_of_life(board, config);
    game_of_life.play();
}
