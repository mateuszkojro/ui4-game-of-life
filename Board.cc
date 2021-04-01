//
// Created by mateu on 4/1/2021.
//

#include "Board.h"

Board::Board(bool *board) : board_(board) {}

Board::~Board() {}

size_t Board::get_size_x() const {
    return size_x_;
}

size_t Board::get_size_y() const {
    return size_y_;
}

bool *Board::get_board() const {
    return board_;
}
