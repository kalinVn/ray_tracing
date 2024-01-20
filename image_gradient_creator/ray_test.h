#ifndef RAY_TEST_H
#define RAY_TEST_H

#include "Vec3.h"

class ray_test {
  public:
    ray_test() {}

    ray_test(const point3& origin, const vec3& direction) : orig(origin), dir(direction) {}

    point3 origin() const  { return orig; }
    vec3 direction() const { return dir; }

    point3 at(double t) const {
        return orig + t*dir;
    }

  private:
    point3 orig;
    vec3 dir;
};

#endif