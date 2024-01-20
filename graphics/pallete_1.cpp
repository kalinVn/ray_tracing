// Your First C++ Program

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

struct ImgOptions {
    string name;
    int rowCount;
    int colCount;
    string fileType;
};

struct RectOptions {
    int rectWidth;
    int rectHeight;
    int stepIncreaseRandomValuePerRect;
};


void savePPM (RectOptions rectOptions, ImgOptions imgOptions);


int main() {
    RectOptions rectOptions;
    rectOptions.rectWidth = 200;
    rectOptions.rectHeight = 200;
    rectOptions.stepIncreaseRandomValuePerRect = 12;

    ImgOptions imgOptions;
    imgOptions.rowCount = 5;
    imgOptions.colCount = 5;
    imgOptions.fileType = "P6";
    imgOptions.name = "pallete_1";
    
    savePPM(rectOptions, imgOptions);
    
    
    return 0;
}


void writePPM (string name, string fileType, int imgWidth, int imgHeight, float pixels[][2]) {
    int maxColorComponent = 255;
    std::ofstream ppmFileStream(name);
    ppmFileStream  << fileType;
    ppmFileStream << imgWidth << " " << imgHeight << "\n";
    ppmFileStream << maxColorComponent << "\n";
    int length = imgWidth * imgHeight;
    for (int i = 0; i < length; i++) {
        ppmFileStream << pixels[i][0] << " ";
        ppmFileStream << pixels[i][1]  << " ";
        ppmFileStream << 0 << " " << "\n";
    }
   

    ppmFileStream.close();

}

void savePPM (RectOptions rectOptions, ImgOptions imgOptions) {

    const int maxColorComponent = 255;
    const string fileType =  "P3\n";
    const string name = imgOptions.name + ".ppm";

    int image_width = 256;
    int image_height = 256;
    
    int length = image_height * image_width;
    float pixels[length][2];
    int current_pos = 0;
   
    for (int x = 0; x < image_height; ++x) {
        for (int y = 0; y < image_width; ++y) {
            
            auto r =  double(y) / (image_width-1);
            auto g = double(x) / (image_height-1);
            auto b = 0;
            
            int ir = static_cast<int>(255.999 * r);
            int ig = static_cast<int>(255.999 * g);
            int ib = 0;

            pixels[current_pos][0] = ir;
            pixels[current_pos][1] = ig;
            pixels[current_pos][2] = ib;

            current_pos++;
        }
        
    }
    
    writePPM(name, fileType, image_width, image_height, pixels);
}
