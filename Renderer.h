//
// Created by mateu on 3/21/2021.
//

#ifndef GAME_OF_LIFE_RENDERER_H
#define GAME_OF_LIFE_RENDERER_H

/// \brief Struct containing coordinates of difrent objects
struct Coord {
    int x;
    int y;
};

/// \brief Colors used in renderer
enum class Color {
    Red,
    Green,
    Blue,
    Black,
    White
};

/// \brief Basic base class for all renderers.
class Renderer {
public:
    /// \brief Creates window of given size
    /// \param int Size in x dimention
    /// \param int Size in y dimention
    virtual void create_window(int size_x, int size_y) = 0;

    /// \brief Draws a square on position wit size and fill
    /// \param Coord position
    /// \param size in x axis
    /// \param size in y axis
    /// \param Color color to fill square with
    virtual void draw_square(const Coord &position, int size_x, int size_y, const Color &fill) = 0;

    /// \brief Fill all screan with defined color
    /// \param Color color to fill the screen with
    virtual void clear_screen(const Color &fill) = 0;
};


#endif //GAME_OF_LIFE_RENDERER_H
