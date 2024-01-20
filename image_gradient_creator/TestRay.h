#ifndef TestRay_H
#define TestRay_H

#include "Vec3.h"

class TestRay {
    
  public:
    TestRay() {}

    TestRay(const point3& origin, const vec3& direction) : orig(origin), dir(direction) {}

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