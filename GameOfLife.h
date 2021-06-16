//
// Created by mateu on 3/24/2021.
//

#ifndef GAME_OF_LIFE_GAMEOFLIFE_H
#define GAME_OF_LIFE_GAMEOFLIFE_H

#include "Board.h"
#include "GameEngine.h"

/// Activation function based on the original Conway's Game of Life
/// \param is_alive is the cell alive or not
/// \param no_neighbours how many alive neighbours are around
/// \return true if cell should be alive false if not
bool conway_activation(bool is_alive, int no_neighbours);

/// \brief Implementation of the game of life
class GameOfLife : public GameEngine {
public:
  explicit GameOfLife(const Board &board, const Config &config)
      : GameEngine(config), activation_func_(conway_activation) {

    current_board_ = new Board(board);
    next_board_ = new Board(board);
  };

  GameOfLife(const GameOfLife &) = delete;

  const GameOfLife &operator=(const GameOfLife &) = delete;

  /// render current_board_
  void render_current_board();

  /// start the game engine
  void play();

  /// Sets the function that will be used to determine if the cell should be
  /// alive \param func function ptr function should return bool (true if a cell
  /// should be alive) based on the number of alive neighbours and if given cell
  /// is alive
  void set_activation_function(bool (*func)(bool, int));

  /// sets the function that will be used to determine if cell should be alive
  /// \param func returning bool (if is alive) has params (bool) is currently
  /// alive (int) how many neighbours it has
  ~GameOfLife() override;

protected:
  void on_start() override;

  void on_tick() override;

  void on_end() override;

private:
  /// \brief board that is currently shown on the screen
  Board *current_board_;
  /// \brief board that will be shown on the next tick
  Board *next_board_;

  /// \brief function that determines if the cell should be active or not
  bool (*activation_func_)(bool, int);
};

#endif // GAME_OF_LIFE_GAMEOFLIFE_H
