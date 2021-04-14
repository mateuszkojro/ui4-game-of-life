//
// Created by mateu on 4/11/2021.
//

#ifndef GAME_OF_LIFE_SIMPLECONSOLERENDERER_H
#define GAME_OF_LIFE_SIMPLECONSOLERENDERER_H

#include "Renderer.h"

class SimpleConsoleRenderer : Renderer {
    void create_window(int size_x, int size_y) override;

    void draw_square(const Coord &position, int size_x, int size_y, const Color &fill) override;

    void clear_screen(const Color &fill) override;

    void set_pixel(const Coord &position, const Color &fill) override;

    ~SimpleConsoleRenderer() override = default;

private:
};


#endif //GAME_OF_LIFE_SIMPLECONSOLERENDERER_H
