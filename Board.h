//
// Created by mateu on 4/1/2021.
//

#ifndef GAME_OF_LIFE_BOARD_H
#define GAME_OF_LIFE_BOARD_H

#include <array>
#include <string>

class Board {
public:

    Board() = delete;

    /// Accesses element of undderyling arr
    /// \param x x coordinate
    /// \param y y coordinate
    /// \return reference to given field
    bool &operator()(int x, int y);
    bool &operator()(int i);

    /// Rerturns array of ptrs to neighbours Some might be null
    /// \param x x coordinate
    /// \param y y coordinare
    /// \return array of ptrs to neighbour cells (some might be null)
    std::array<bool *, 9> get_neighbours(int x, int y);
    std::array<bool *, 9> get_neighbours(int i);

    static Board load_board(const std::string &path);

    static void save_board(const Board &);

    size_t get_size_x() const;

    size_t get_size_y() const;

    bool *get_board() const;



public:

    Board(bool *board, size_t x, size_t y);

    Board(const Board &other);

    Board(Board &&other);

    const Board &operator=(const Board &);

    int size() const;

    virtual ~Board();


private:
    /// Internal: Translate from x y coordinates to one dimentional arr
    /// \param x x coordinate
    /// \param y y coordinate
    /// \return addres in underlying arr
    size_t translate_adress(int x, int y) const;
    void copy(const Board& other);

    size_t size_x_;
    size_t size_y_;

    bool *board_;

};


#endif //GAME_OF_LIFE_BOARD_H
