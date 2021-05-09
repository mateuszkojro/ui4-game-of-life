//
// Created by mateu on 4/1/2021.
//

#include "Board.h"
#include <assert.h>
#include <cstdio>

Board::Board(bool *board, size_t x, size_t y) :
        size_x_(x),
        size_y_(y) {
    board_ = board;//new bool[size()];
}

Board::~Board() {
    delete[] board_;
    board_ = nullptr;
}

size_t Board::size_x() const {
    return size_x_;
}

size_t Board::size_y() const {
    return size_y_;
}

void Board::fill(bool value) {
  for (int i = 0; i < size(); i++) {
    operator()(i) = value;
  }
}

bool *Board::get_board() const {
    return board_;
}

std::array<bool, 9> Board::get_neighbours(int x, int y) {
    return get_neighbours(translate_adress(x, y));
}

std::array<bool, 9> Board::get_neighbours(int i) {
    std::array<bool, 9> result{};


    int pos_x, pos_y;

    // Transform continuous address to x, y one
    pos_y = i / size_x_;
    pos_x = i % size_x_;

    // place in out array
    int itr = 0;


    for (int y = -1; y <= 1; y++) {
        for (int x = -1; x <= 1; x++) {

            // transform to position on the board
            int board_x = pos_x + x;
            int board_y = pos_y + y;
            int board_i = translate_adress(board_x, board_y);

            bool is_target = (board_x == pos_x) && (board_y == pos_y);
            bool is_valid = (board_i != -1);

            if (!is_target && is_valid){
                result[itr++] = board_[board_i];
            } else {
                result[itr++] = false;
            }
        }
    }

    return result;
}

Board Board::load_board(const std::string &path) {
    std::fstream file;
    file.open(path, std::ios::in);
    size_t size_x, size_y;

    file >> size_x >> size_y;
    bool *board = new bool[size_y * size_x];
    for (int i = 0; i < size_x * size_y; ++i) {
        file >> board[i];
    }
    return Board(board, size_x, size_y);
}

void Board::save_board(const Board &board, const std::string &path) {
    std::fstream file;
    file.open(path, std::ios::out);
    file << board.size_x_;
    file << board.size_y_;
    for (int i = 0; i < board.size(); ++i) {
        file << board(i);
    }
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

Board::Board(Board &&other) noexcept {
    assert(false);
    size_y_ = other.size_y_;
    size_x_ = other.size_x_;
    board_ = other.board_;
    other.board_ = nullptr;
}

Board &Board::operator=(const Board &other) {
    if (this == &other)
        return *this;
    copy(other);
    return *this;
}

unsigned Board::size() const {
    return size_x_ * size_y_;
}

int Board::translate_adress(int x, int y) const {
  if (y >= size_y_)
    return -1;
  if (x >= size_x_)
    return -1;
  if (x < 0)
    return -1;
  if (y < 0)
    return -1;

  return y * size_x_ + x;
}

bool &Board::operator()(int i) {
    return board_[i];
}

bool &Board::operator()(int x, int y) {
    return operator()(translate_adress(x, y));
}

bool &Board::operator()(int i) const {
    return board_[i];
}

bool &Board::operator()(int x, int y) const {
    return operator()(translate_adress(x, y));
}
