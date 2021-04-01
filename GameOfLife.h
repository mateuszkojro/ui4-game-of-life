//
// Created by mateu on 3/24/2021.
//

#ifndef GAME_OF_LIFE_GAMEOFLIFE_H
#define GAME_OF_LIFE_GAMEOFLIFE_H

#include "GameEngine.h"
#include "Board.h"

bool conway_activation(bool value, int no_neighbours);

/// \brief Implementation of the game of life
class GameOfLife : public GameEngine {
public:
    explicit GameOfLife(const Config &config)
            : GameEngine(config),
              activation_func_(conway_activation) {};

    GameOfLife(const GameOfLife &) = delete;

    const GameOfLife &operator=(const GameOfLife &) = delete;

    void play();



    void set_activation_function(bool (*func)(bool, int));

    /// sets the function that will be used to determine if cell shoud be allive
    /// \param func returning bool (if is alive) has params (bool) is currently alive (int) how many
    /// neighbours it has
    ~GameOfLife() override;

protected:

    void on_start() override;

    void on_tick() override;

    void on_end() override;

private:


    /// \brief Swaps current_board with next_board to be s  hown and to prepare for next tick
    void swap_boards();

    /// \brief Counts a number of alive cells around cell at position
    /// \param x x coordinate of analyzed position
    /// \param y y coordinate of analyzed position
    /// \return number of alive cells around position
    unsigned count_alive_near_position(int x, int y) const;

    /// \brief board that is currently shown on the screen
    Board *current_board_;
    ///\brief board that will be shown on the next tick
    Board *next_board_;

    bool (*activation_func_)(bool, int);

};

#endif //GAME_OF_LIFE_GAMEOFLIFE_H
