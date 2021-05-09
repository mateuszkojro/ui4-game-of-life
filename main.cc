#include "SimpleConsoleRenderer.h"
#include "GameOfLife.h"

int main() {
    const unsigned size_x = 10;
    const unsigned size_y = 10;

    GameEngine::Config config{};

    config.framerate = 1;
    config.renderer = new SimpleConsoleRenderer;

    Board board(size_x, size_y);

    // Make the board empty
    board.fill(false);

    // Setup some config on the board
    board(1, 1) = true;
    board(1, 2) = true;
    board(1, 3) = true;

    board(3, 1) = true;
    board(3, 2) = true;
    board(3, 3) = true;

    board(6, 1) = true;
    board(6, 2) = true;
    board(6, 3) = true;

    board(9, 3) = true;
    board(9, 4) = true;
    board(9, 5) = true;

    // Start the GameEngine
    GameOfLife game_of_life(board, config);
    game_of_life.play();
}
