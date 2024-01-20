#ifndef RAY_TEST_1_H
#define RAY_TEST_1_H

#include "Vector3D.h"

class Ray_Test_1 {
  public:
    Ray_Test_1();

    Ray_Test_1(const Vector3D, const Vector3D);

    Vector3D getOrigin() const  { return orig; }
    Vector3D getDirection() const { return dir; }

    Vector3D at(double t) {
        return orig.add(dir.mult(t));
    }

  private:
    Vector3D orig;
    Vector3D dir;
};
Ray_Test_1::Ray_Test_1 () {
    orig = Vector3D(0, 0, 0);
    dir = Vector3D(0, 0, 0);
}

Ray_Test_1::Ray_Test_1 (Vector3D origin, Vector3D direction) {
    orig = origin;
    dir = direction;
}
#endif