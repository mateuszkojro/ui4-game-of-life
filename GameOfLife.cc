//
// Created by mateu on 3/24/2021.
//

#include <algorithm>
#include "GameOfLife.h"

void GameOfLife::play() {

}

void GameOfLife::set_activation_function(bool (*func)(bool, int)) {
    activation_func_ = func;
}

GameOfLife::~GameOfLife() {
    delete current_board_;
    delete next_board_;
}

void GameOfLife::on_start() {
    // Show a welcome screen and ready to go
}

void GameOfLife::on_tick() {
    // loop through all the active and inactive cells
    for (int i = 0; i < current_board_->size(); ++i) {
        // get neighbours for current cell
        auto neighbours = current_board_->get_neighbours(i);
        (*next_board_)(i) = activation_func_(
                // Whats the current state of the cell
                (*next_board_)(i),
                // Count cells that are active around this cell
                std::count(neighbours.begin(),
                           neighbours.end(),
                           true));
    }
    swap_boards();
}

void GameOfLife::on_end() {
    // Show some stats on exit
}

void GameOfLife::swap_boards() {
    Board *temp = current_board_;
    current_board_ = next_board_;
    next_board_ = temp;
}
