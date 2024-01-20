#ifndef COLOR_TEST_1_H
#define COLOR_TEST_1_H

using namespace std;


#include "Vector3D.h"

#include <iostream>

using color_test_1 = Vector3D;

void write_color(std::ostream &out, Vector3D pixel_color) {
  
    out << static_cast<int>(255.999 * pixel_color.getX()) << ' '
        << static_cast<int>(255.999 * pixel_color.getY()) << ' '
        << static_cast<int>(255.999 * pixel_color.getZ()) << '\n';
}

#endif