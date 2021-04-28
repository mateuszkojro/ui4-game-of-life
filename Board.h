//
// Created by mateu on 4/1/2021.
//

#ifndef GAME_OF_LIFE_BOARD_H
#define GAME_OF_LIFE_BOARD_H

#include <array>
#include <string>
#include <fstream>

/// Class containing board (bool array) with functions useful for
/// the implementation of the game of life
class Board {
public:

    Board() = delete;

    /// Accesses element of underlying arr
    /// \param x x coordinate
    /// \param y y coordinate
    /// \return reference to given field
    bool &operator()(int x, int y);
    bool &operator()(int i);

    bool &operator()(int x, int y) const;
    bool &operator()(int i) const;

    /// Returns array of pairs to neighbours Some might be null
    /// \param x x coordinate
    /// \param y y coordinate
    /// \return array of pointers to neighbour cells (some might be null)
    std::array<bool *, 9> get_neighbours(int x, int y);
    std::array<bool *, 9> get_neighbours(int i);

    /// Load board from the file
    /// Path to the file containing the Board
    static Board load_board(const std::string &path);

    /// Save board state to the file
    /// \param Board to be saved
    /// \param Path to the file that bord should be saved to default: "board.save"
    static void save_board(const Board &, const std::string &path);

    /// Return size in x axis
    /// \return width of the Board
    size_t get_size_x() const;

    /// Return size in y axis
    /// \return height in y axis
    size_t get_size_y() const;

    /// Get the ptr to bool array
    /// \return ptr to bool array containing board data
    bool *get_board() const;



public:


    Board(bool *board, size_t x, size_t y);

    Board(const Board &other);

    Board(Board &&other) noexcept ;

    Board &operator=(const Board &);

    /// Return the size of the underlying array (width * height)
    int size() const;

    virtual ~Board();


private:
    /// Internal: Translate from x y coordinates to one dimensional arr
    /// \param x x coordinate
    /// \param y y coordinate
    /// \return address in underlying arr
    int translate_adress(int x, int y) const;

    /// Helper function to copy the raw ptr
    /// \param other board being copied
    void copy(const Board& other);

    size_t size_x_;
    size_t size_y_;

    /// raw bool data true means alive and false dead
    bool *board_;

};


#endif //GAME_OF_LIFE_BOARD_H
