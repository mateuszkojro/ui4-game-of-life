//
// Created by mateu on 4/11/2021.
//

#include <iostream>

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)

#include <Windows.h>

#endif

#include "SimpleConsoleRenderer.h"

void SimpleConsoleRenderer::create_window(int size_x, int size_y) {
    width_ = size_x;
    height_ = size_y;
    video_buffer_ = new GrayscalePixel[width_ * height_];
}

void SimpleConsoleRenderer::draw_square(const Coord &position, int size_x, int size_y, const Color &fill) {
    throw std::exception("Not implemented");
}

void SimpleConsoleRenderer::clear_screen(const Color &fill) {

    memset(video_buffer_, color_to_pixel(fill), width_ * height_);
    clear_window();
}

void SimpleConsoleRenderer::set_pixel(const Coord &position, const Color &fill) {
    video_buffer_[translate(position)] = color_to_pixel(fill);
}

void SimpleConsoleRenderer::show_text_big(const Coord &position, const std::string &text) {

    auto draw_stared_line = [this, &text, &position](int y) {
        for (int i = position.x; i < position.x + text.size() + 4; i++) {
            video_buffer_[translate({i, y})] = '*';
        }
    };

    draw_stared_line(position.y);

    int x = position.x;
    video_buffer_[translate({x++, position.y + 1})] = '*';
    video_buffer_[translate({x++, position.y + 1})] = ' ';
    for (int i = position.x + 1; i < position.x + text.size() + 1; i++) {
        video_buffer_[translate({i, position.y + 1})] = (unsigned char) text[i];
        x++;
    }
    video_buffer_[translate({x++, position.y + 1})] = ' ';
    video_buffer_[translate({x++, position.y + 1})] = '*';

    draw_stared_line(position.y + 2);
}

void SimpleConsoleRenderer::show_text_medium(const Coord &position, const std::string &text) {
    int x = position.x;
    video_buffer_[translate({x++, position.y})] = '*';
    video_buffer_[translate({x++, position.y})] = ' ';
    for (char i : text) {
        video_buffer_[translate({x++, position.y})] = (unsigned char) i;
    }
    video_buffer_[translate({x++, position.y})] = ' ';
    video_buffer_[translate({x++, position.y})] = '*';
}

void SimpleConsoleRenderer::show_text_small(const Coord &position, const std::string &text) {
    for (int i = position.x; i < position.x + text.size(); i++) {
        video_buffer_[translate({i, position.y})] = (unsigned char) text[i];
    }
}

void SimpleConsoleRenderer::render() {
    clear_window();
    for (int y = 0; y < height_; y++) {
        for (int x = 0; x < width_; x++) {
            if (video_buffer_[translate({x, y})] > 300) {
                std::cout << '#';
            } else if (video_buffer_[translate({x, y})] < 256) {
                std::cout << (char) video_buffer_[translate({x, y})];
            } else {
                std::cout << ' ';
            }
            std::cout << " ";
        }
        std::cout << std::endl;
    }
}

unsigned SimpleConsoleRenderer::translate(Coord position) {
    return position.y * width_ + position.x;
}

GrayscalePixel SimpleConsoleRenderer::color_to_pixel(const Color &color) {
    GrayscalePixel pixel_color = 301;
    if (color == Color::Black) {
        pixel_color = 300;
    }
    return pixel_color;
}

void SimpleConsoleRenderer::clear_window() {
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    system("cls");
#else
    std::cout << "\x1B[2J\x1B[H";
#endif
}
