//
// Created by mateu on 4/11/2021.
//

#ifndef GAME_OF_LIFE_SIMPLECONSOLERENDERER_H
#define GAME_OF_LIFE_SIMPLECONSOLERENDERER_H

#include "Renderer.h"

typedef uint16_t GrayscalePixel;

class SimpleConsoleRenderer : public Renderer {

    unsigned translate(Coord position);
    static GrayscalePixel color_to_pixel(const Color& color);

    void create_window(int size_x, int size_y) override;

    void draw_square(const Coord &position, int size_x, int size_y, const Color &fill) override;

    void clear_screen(const Color &fill) override;

    void set_pixel(const Coord &position, const Color &fill) override;

    void show_text_big(const Coord &position, const std::string &text) override;

    void show_text_medium(const Coord &position, const std::string &text) override;

    void show_text_small(const Coord &position, const std::string &text) override;

    void render() override;

    ~SimpleConsoleRenderer() override = default;

private:

    void clear_window();

    GrayscalePixel* video_buffer_;

};

#endif // GAME_OF_LIFE_SIMPLECONSOLERENDERER_H