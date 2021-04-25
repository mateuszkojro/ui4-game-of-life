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
    std::array<bool *, 9> result{};

    auto coord_from_itr = [this](int i, int &x, int &y) {
        y = i / size_x_;
        x = i % size_x_;
    };

    int pos_x, pos_y;

    coord_from_itr(i, pos_x, pos_y);

    int itr = 0;
    for (int y = pos_y; y < 3; y++) {
        for (int x = pos_x; x < 3; x++) {
            if (x != pos_x && y != pos_y && translate_adress(x, y) != -1) {
                result[itr++] = &board_[translate_adress(x, y)];
            } else {
                result[itr++] = nullptr;
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

Board::Board(Board &&other) {
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

int Board::size() const {
    return size_x_ * size_y_;
}

int Board::translate_adress(int x, int y) const {
    if (y >= size_y_) {
        return -1;
    }
    if (x >= size_x_) {
        return -1;
    }
    return y * size_y_ + x;
}

bool &Board::operator()(int i) {
    return board_[i];
}

bool Board::operator()(int i) const {
    return board_[i];
}

bool Board::operator()(int x, int y) const {
    return operator()(translate_adress(x, y));
}
