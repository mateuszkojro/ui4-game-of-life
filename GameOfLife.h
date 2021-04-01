//
// Created by mateu on 3/24/2021.
//

#ifndef GAME_OF_LIFE_GAMEOFLIFE_H
#define GAME_OF_LIFE_GAMEOFLIFE_H

#include "GameEngine.h"
#include "Board.h"

/// \brief Implementation of the game of life
class GameOfLife : public GameEngine {
public:
    explicit GameOfLife(const Config &config)
            : GameEngine(config) {};

    void on_start() override;

    void on_tick() override;

    void on_end() override;

    ~GameOfLife() override;

private:
    /// \brief Gets value at position from current board
    /// \param x x coordinate of position to get
    /// \param y y coordinate of position to get
    /// \return value at position in current_board_
    bool get_element(int x, int y) const;

    /// \brief Sets value at position on next_board
    /// \param x x coordinate of position to be set
    /// \param y y coordinate of position to be set
    /// \param value value to set at position
    void set_element(int x, int y, bool value);

    /// \brief Swaps current_board with next_board to be shown and to prepare for next tick
    void swap_boards();

    /// \brief Counts a number of alive cells around cell at position
    /// \param x x coordinate of analyzed position
    /// \param y y coordinate of analyzed position
    /// \return number of alive cells around position
    unsigned count_alive_near_position(int x, int y) const;

    /// \brief board that is currently shown on the screen
    Board* current_board_;
    ///\brief board that will be shown on the next tick
    Board* next_board_;

};

#endif //GAME_OF_LIFE_GAMEOFLIFE_H
