//
// Created by mateu on 4/1/2021.
//

#include "Board.h"

Board::Board(bool *board) : board_(board) {}

Board::~Board() {

}

bool Board::operator==(const Board &rhs) const {
    return board_ == rhs.board_;
}

bool Board::operator!=(const Board &rhs) const {
    return !(rhs == *this);
}
