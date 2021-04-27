//
// Created by mateu on 3/21/2021.
//

#ifndef GAME_OF_LIFE_RENDERER_H
#define GAME_OF_LIFE_RENDERER_H

#include <string>

/// \brief Struct containing coordinates of different objects
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

    /// Sets the position at given coordinate to given Color
    /// \param position const Coord& position of the pixels to be set
    /// \param fill The color to set the pixel to
    virtual void set_pixel(const Coord &position, const Color &fill) = 0;

    /// \brief Fill all screan with defined color
    /// \param Color color to fill the screen with
    virtual void clear_screen(const Color &fill) = 0;

    /// Show text in big letters on position
    /// \param position Coord of the beginning of the text
    /// \param text text to be printed
    virtual void show_text_big(const Coord &position, const std::string &text) = 0;

    /// Show text in medium letters on position
    /// \param position Coord of the beginning of the text
    /// \param text text to be printed
    virtual void show_text_medium(const Coord &position, const std::string &text) = 0;

    /// Show text in small letters on position
    /// \param position Coord of the beginning of the text
    /// \param text text to be printed
    virtual void show_text_small(const Coord &position, const std::string &text) = 0;

    virtual void render() = 0;

    virtual ~Renderer() = default;

protected:
    /// width of the render plane
    int width_;
    /// height of the render plane
    int height_;

};


#endif //GAME_OF_LIFE_RENDERER_H
