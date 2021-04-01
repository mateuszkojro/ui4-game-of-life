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

bool &Board::operator()(int x, int y) {
    return <#initializer#>;
}

std::array<bool *, 9> Board::get_neighbours(int x, int y) {
    return std::array<bool *, 9>();
}

Board Board::load_board(const std::string path) {
    return Board();
}

void Board::save_board(const Board &) {

}

Board::Board(bool *board, size_t x, size_t y) {

}

Board::Board(const Board &other) {

}

Board::Board(Board &&other) {

}

const Board &Board::operator=(const Board &) {
    return <#initializer#>;
}

size_t Board::translate_adress(int x, int y) {
    return 0;
}
