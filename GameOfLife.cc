//
// Created by mateu on 3/24/2021.
//

#include <algorithm>
#include <iostream>
#include "GameOfLife.h"

void GameOfLife::play() {
    start_engine();
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
    renderer_->create_window(current_board_->get_size_x(),
                             current_board_->get_size_y());

    renderer_->clear_screen(Color::Black);
//    renderer_->show_text_big(Coord{0, 0}, "Gra w zycie");
//    renderer_->show_text_medium(Coord{0, 1}, "Wpisz \"start\" i nacisnij ENTER to start");
//    renderer_->render();
    std::string text;
    while (text != "start") {
        std::cin >> text;
    }
    start_game_loop();
    // pokazac menu
}

void GameOfLife::render_board() {
    for (int x = 0; x < next_board_->get_size_x(); x++) {
        for (int y = 0; y < next_board_->get_size_y(); y++) {
            Color color;
            if ((*next_board_)(x, y))
                color = Color::White;
            else
                color = Color::Black;
            renderer_->set_pixel(Coord{x, y}, color);
        }
    }
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
                count(neighbours));
    }
    swap_boards();
    render_board();
    renderer_->render();
}

void GameOfLife::on_end() {
    // Show some stats on exit
    renderer_->show_text_small(Coord{0, 0}, "Dziekuje!");
}

void GameOfLife::swap_boards() {
    Board *temp = current_board_;
    current_board_ = next_board_;
    next_board_ = temp;
}
/// Count the number of fields in an array that are true
/// \param data is a std::array<bool*, 9> with surrounding cells
/// \return number of cells that are alive
int GameOfLife::count(std::array<bool *, 9> data) {
    int counter = 0;
    for (auto *field : data) {
        if (field) {
            counter++;
        }
    }
    return counter;
}

bool conway_activation(bool is_alive, int no_neighbours) {
    if (is_alive) {
        if (no_neighbours == 2 || no_neighbours == 3)
            return true;
        else
            return false;
    } else {
        if (no_neighbours == 3)
            return true;
        else
            return false;
    }
}
