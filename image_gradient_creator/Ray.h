#ifndef Ray_H
#define Ray_H

#include "Vector3D.h"

class Ray {
  public:
    Ray();

    Ray(const Vector3D, const Vector3D);

    Vector3D getOrigin() const  { return orig; }
    Vector3D getDirection() const { return dir; }

    Vector3D at(double t) {
        return orig.add(dir.mult(t));
    }

  private:
    Vector3D orig;
    Vector3D dir;
};
Ray::Ray () {
    orig = Vector3D(0, 0, 0);
    dir = Vector3D(0, 0, 0);
}

Ray::Ray (Vector3D origin, Vector3D direction) {
    orig = origin;
    dir = direction;
}
#endif