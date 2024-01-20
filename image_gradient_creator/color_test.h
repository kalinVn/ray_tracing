#ifndef COLOR_TEST_H
#define COLOR_TEST_H

using namespace std;


#include "Vec3.h"

#include <iostream>

using color_test = vec3;

void write_color(std::ostream &out, vec3 pixel_color) {
    // Write the translated [0,255] value of each color component.

    // cout <<static_cast<int>(255.999 * pixel_color.x()) << endl;

    out << static_cast<int>(255.999 * pixel_color.x()) << ' '
        << static_cast<int>(255.999 * pixel_color.y()) << ' '
        << static_cast<int>(255.999 * pixel_color.z()) << '\n';
}

#endif