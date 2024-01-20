#ifndef Color_H
#define Color_H

using namespace std;


#include "Vector3D.h"

#include <iostream>

using color = Vector3D;

void write_color(std::ostream &out, Vector3D pixel_color) {
    // Write the translated [0,255] value of each color component.

    // cout <<static_cast<int>(255.999 * pixel_color.x()) << endl;

    out << static_cast<int>(255.999 * pixel_color.getX()) << ' '
        << static_cast<int>(255.999 * pixel_color.getY()) << ' '
        << static_cast<int>(255.999 * pixel_color.getZ()) << '\n';
}

#endif