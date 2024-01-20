#include "Vec3.h"
#include "Vector3D.h"
// #include "Color.h"
#include "Ray.h"
#include "color_test.h"
#include "color_test_1.h"
#include "ray_test.h"
#include "Ray_Test_1.h"

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;


color_test ray_color( Ray_Test_1& r) {
    
    // cout<< unit_direction.getX() << "" <<  endl;
   
    Vector3D unit_direction = r.getDirection().unit();

    
    auto a = 0.5 * (unit_direction.getY() + 1.0);
    Vector3D vectorOnes = Vector3D(1.0, 1.0, 1.0);
    Vector3D vectorBlend = Vector3D(0.5, 0.7, 1.0);
    
    auto color_test_1 = (1.0-a)*color_test(1.0, 1.0, 1.0)  + a*color_test(0.5, 0.7, 1.0);
    // cout << color_test_1[2];
    return (1.0-a)*color_test(1.0, 1.0, 1.0)  + a*color_test(0.5, 0.7, 1.0);
    // return (1.0-a)*color_test(1.0, 1.0, 1.0) + a*color_test(0.5, 0.7, 1.0);
}


int main() {

    double aspect_ratio = 16.0 / 9.0;
    int image_width = 500;
    int image_height = static_cast<int>(image_width / aspect_ratio);
    auto focal_length = 1.0;
    auto viewport_height = 2.0;
   
    auto viewport_width = viewport_height * (static_cast<double>(image_width)/image_height);

    auto camera_center = Vector3D(0, 0, 0);

    auto viewport_u = Vector3D(viewport_width, 0, 0);
    auto viewport_v = Vector3D(0, -viewport_height, 0);

    auto pixel_delta_u = viewport_u.devideByScalar(image_width);
    auto pixel_delta_v = viewport_v.devideByScalar(image_height);

    auto camera_center_substacted = camera_center.substract(Vector3D(0, 0, focal_length));
    auto camera_center_substacted_viewport =  camera_center_substacted.substract(viewport_u.devideByScalar(2));
    auto viewport_upper_left = camera_center_substacted_viewport.substract(viewport_v.devideByScalar(2));
    
    auto pixel_00_loc = viewport_upper_left.add( (pixel_delta_u.add(pixel_delta_v)).mult(0.5) );
    
    int img_length = image_height * image_width;
    
    color_test pixels[img_length];
    int current_pos = 0;

    for (int j = 0; j < image_height; ++j) {
      
        for (int i = 0; i < image_width; ++i) {
            auto pixel_center = pixel_00_loc.add(pixel_delta_u.mult(i)).add(pixel_delta_u.mult(j));
            auto ray_direction = pixel_center.substract(camera_center);
           
            auto r_test_1 = Ray_Test_1(camera_center, ray_direction);
            auto pixel_color = ray_color(r_test_1);

            pixels[current_pos] = pixel_color;
            current_pos++;
        }
    }

    const int maxColorComponent = 255;
    const string fileType =  "P3\n";
    const string name = "test_img_114.ppm";
    
    std::ofstream ppmFileStream(name);
    
    ppmFileStream  << fileType;
    ppmFileStream << image_width << " " << image_height<< "\n";
    ppmFileStream << maxColorComponent << "\n";
   
    for (int i = 0; i < img_length; i++) {
        ppmFileStream << static_cast<int>(255.999 * pixels[i][0]) << " ";
        ppmFileStream << static_cast<int>(255.999 * pixels[i][1])  << " ";
        ppmFileStream << static_cast<int>(255.999 * pixels[i][2])  << " " << "\n";
    }
    

    ppmFileStream.close();

    return 0;
}


// void writeFILE(string name, string fileType, int imgWidth, int imgHeight, Vec3 pixels[]) {
//     int maxColorComponent = 255;
//     std::ofstream ppmFileStream(name);
//     ppmFileStream  << fileType;
//     ppmFileStream << imgWidth << " " << imgHeight << "\n";
//     ppmFileStream << maxColorComponent << "\n";
//     int length = imgWidth * imgHeight;
//     for (int i = 0; i < length; i++) {
//         ppmFileStream << pixels[i].y() << " ";
//         ppmFileStream << pixels[i].x()  << " ";
//         ppmFileStream << 0 << " " << "\n";
//     }
    

//     ppmFileStream.close();
// }

// void saveFILE() {

//     const int maxColorComponent = 255;
//     const string fileType =  "P3\n";
//     const string name = "pallete_2.ppm";

//     int image_width = 256;
//     int image_height = 256;
    
//     int length = image_height * image_width;
//     Vec3 pixels[length];
//     int current_pos = 0;
   
    
//     for (int x = 0; x < image_height; ++x) {
//         for (int y = 0; y < image_width; ++y) {
//             pixels[current_pos] = Vec3 (y, x, 0);
//             current_pos++;
//         }
//     }
    
//     writeFILE(name, fileType, image_width, image_height, pixels);
// }
