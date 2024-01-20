#ifndef _Vector3D_H
#define _Vector3D_H

#include "math.h"

using std::sqrt;
using std::pow;

class Vector3D {

    double x, y, z;

    public:
        Vector3D();

        Vector3D(double, double, double);

        double getX () {
            return x;
        }

        double getY () {
            return y;
        }

        double getZ () {
            return z;
        }

        Vector3D negative() {
            return Vector3D(-x, -y, -z);
        }

        Vector3D mult(double scalar) {
            return Vector3D(x * scalar, y * scalar, z * scalar);
        }

        Vector3D devideByScalar(double scalar) {
            return Vector3D(x / scalar, y / scalar, z / scalar);
        }

        Vector3D addScalar(double scalar) {
            return Vector3D(x + scalar, y + scalar, z + scalar);
        }

        Vector3D unit() {
            return Vector3D(x / length() , y / length(), z / length());
        }

        Vector3D projectTo (Vector3D vector) {
            return Vector3D(vector.x + x, vector.y + y, vector.z + z);
        } 

        Vector3D substract (Vector3D vector) {
            return Vector3D(x - vector.x, y - vector.y , z - vector.z);
        } 

        Vector3D add (Vector3D vector) {
            return Vector3D(x + vector.x, y + vector.y, z + vector.z);
        } 

        double length () {
            return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
        } 
        

        Vector3D cross (Vector3D vector) {
            return Vector3D(y * vector.z - z * vector.y, z * vector.x - x * vector.z, x * vector.y - y * vector.x);
        } 

        double dot (Vector3D vector) {
            return x * vector.x + y * vector.y + z * vector.z;
        }

};

Vector3D::Vector3D () {
    x = 0;
    y = 0;
    z = 0;
}

Vector3D::Vector3D (double i, double j, double k) {
    x = i;
    y = j;
    z = k;
}

#endif
