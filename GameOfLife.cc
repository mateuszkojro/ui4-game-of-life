//
// Created by mateu on 3/24/2021.
//

#include "GameOfLife.h"
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <ostream>
#include <cstdio>

static void show_board(const Board &board) {
  for (int i = 0; i < board.size(); i++) {
    std::cout << board(i) << " ";
  }
}

void GameOfLife::play() {
    start_engine();
}

void GameOfLife::set_activation_function(bool (*func)(bool, int)) {
    activation_func_ = func;
}

GameOfLife::~GameOfLife() {
    delete current_board_;
    delete next_board_;
    current_board_ = nullptr;
    next_board_ = nullptr;
}

void GameOfLife::on_start() {
    // Show a welcome screen and ready to go
    renderer_->create_window(current_board_->size_x(),
                             current_board_->size_y());

//    renderer_->clear_screen(Color::Black);
//    renderer_->show_text_big(Coord{0, 0}, "Gra");
//    renderer_->show_text_big(Coord{1, 0}, "w");
//    renderer_->show_text_big(Coord{2, 0}, "zycie");
//    renderer_->render();
//    std::string text;
//    while (text != "start") {
//        std::cin >> text;
//    }
    start_game_loop();
}

void GameOfLife::render_current_board() {
    for (int x = 0; x < current_board_->size_x(); x++) {
        for (int y = 0; y < current_board_->size_y(); y++) {
            Color color;
            if ((*current_board_)(x, y))
                color = Color::White;
            else
                color = Color::Black;

            renderer_->set_pixel(Coord(x, y), color);
        }
    }
    renderer_->render();
}

void GameOfLife::on_tick() {
  // loop through all the active and inactive cells
  for (int i = 0; i < current_board_->size(); ++i) {
    // get neighbours for current cell
    auto neighbours = current_board_->get_neighbours(i);
    // make a cell alive if activation function determines so
    bool value = activation_func_(
        // Whats the current state of the cell
        (*next_board_)(i),
        // Count cells that are active around this cell
        std::count(neighbours.begin(), neighbours.end(), true));

#if DEBUG
    std::printf("Value at cell %d is %d input was (%lld)\n", i, value,
                std::count(neighbours.begin(), neighbours.end(), true));
#endif

    (*next_board_)(i) = value;
  }

#if DEBUG
  static int tick = 0;
  std::printf("Tick %d\n", tick++);
  std::printf("Current board\n");
  show_board(*current_board_);
  std::printf("\nNext board\n");
  show_board(*next_board_);
  std::printf("\n\n");
#else
  render_current_board();
#endif

  Board temp = *next_board_;
  *next_board_ = *current_board_;
  *current_board_ = temp;

}

void GameOfLife::on_end() {
    // Show some stats on exit
    renderer_->show_text_small(Coord(0, 0), "Dziekuje!");
}

/// Activation function proposed by Conway in his original game
/// \param is_alive is cell that is checked alive
/// \param no_neighbours how many neighbours are alive
/// \return should the cell be alive or not
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
