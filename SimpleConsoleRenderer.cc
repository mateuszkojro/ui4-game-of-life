//
// Created by mateu on 4/11/2021.
//

#include <iostream>

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#include <Windows.h>
#endif

#include "SimpleConsoleRenderer.h"

void SimpleConsoleRenderer::create_window(int size_x, int size_y) {}

void SimpleConsoleRenderer::draw_square(const Coord &position, int size_x, int size_y, const Color &fill) {}

void SimpleConsoleRenderer::clear_screen(const Color &fill) {
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    system("cls");
#else
    std::cout << "\x1B[2J\x1B[H";
#endif
}

void SimpleConsoleRenderer::set_pixel(const Coord &position, const Color &fill) {}