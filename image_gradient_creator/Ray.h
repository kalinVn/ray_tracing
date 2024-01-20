#ifndef Ray_H
#define Ray_H

#include <iostream>
#include "Vector3D.h"

class Ray {

   
    public:
        Ray();

        Ray(Vector3D, Vector3D);

        Vector3D getOrigin () {
            return origin;
        }

        Vector3D getDirection () {
            return directon;
        }

        Vector3D at (double t) {
            Vector3D directionMutled = directon.mult(t);
            return origin.projectTo(directionMutled);
        }

    private:
        Vector3D origin;
        Vector3D directon;

};

    Ray::Ray () {
        origin = Vector3D(0, 0, 0);
        directon = Vector3D(0, 0, 0);
        
    }

    Ray::Ray (Vector3D originArg, Vector3D directionArg) {
        origin = originArg;
        directon = directionArg;
    }
 
#endif