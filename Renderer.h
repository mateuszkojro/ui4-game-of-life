//
// Created by mateu on 3/21/2021.
//

#ifndef GAME_OF_LIFE_RENDERER_H
#define GAME_OF_LIFE_RENDERER_H

struct Coord {
    int x;
    int y;
};

enum class Color{
    Red,
    Green,
    Blue,
    Black,
    White
};

class Renderer {
public:
    virtual void draw_square(const Coord& position, int size_x, int size_y, const Color& fill) = 0;
    virtual void clear_screen(const Color& fill) = 0;
};


#endif //GAME_OF_LIFE_RENDERER_H
