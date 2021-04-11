//
// Created by mateu on 4/1/2021.
//

#include "Board.h"

Board::Board(bool *board, size_t x, size_t y) :
        size_x_(x),
        size_y_(y) {
    board_ = new bool[size()];
    memcpy(board_, board, size());
}

Board::~Board() {
    delete[] board_;
}

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
    return board_[translate_adress(x, y)];
}

std::array<bool *, 9> Board::get_neighbours(int x, int y) {
    return get_neighbours(translate_adress(x, y));
}

std::array<bool *, 9> Board::get_neighbours(int i) {
    return std::array<bool *, 9>();
}

Board Board::load_board(const std::string &path) {
}

void Board::save_board(const Board &) {

}

Board::Board(const Board &other) {
    copy(other);
}

void Board::copy(const Board &other) {
    size_y_ = other.size_y_;
    size_x_ = other.size_x_;
    board_ = new bool[size()];
    memcpy(board_, other.board_, size());
}

Board::Board(Board &&other) {
    size_y_ = other.size_y_;
    size_x_ = other.size_x_;
    board_ = other.board_;
    other.board_ = nullptr;
}

const Board &Board::operator=(const Board &other) {
    if (this == &other)
        return *this;
    copy(other);
    return *this;
}

int Board::size() const {
    return size_x_ * size_y_;
}

size_t Board::translate_adress(int x, int y) const {
    return y * size_y_ + x;
}

bool &Board::operator()(int i) {
    return board_[i];
}
