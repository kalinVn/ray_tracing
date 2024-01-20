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
    imgOptions.name = "test_image";
    
    savePPM(rectOptions, imgOptions);
    
    return 0;
}

int*** initPixelMatrixGrid(int rowCount, int colCount, int imgWidth, int imgHeight) {
    int defaultPixels[3] = {140, 110, 210};
    int totalRects = rowCount * colCount;
    int colors[totalRects][2];

    for (int i = 0; i < totalRects; i++) {
        colors[i][0] = (rand()%256);
        colors[i][1] = (rand()%256);
        colors[i][2] = (rand()%256);
    }
    
    int*** pixelMatrix = new int**[imgHeight];
    
    for (int yPos = 0; yPos < imgHeight; yPos++) {
        pixelMatrix[yPos] = new int*[imgWidth];
        for (int xPos = 0; xPos < imgWidth; xPos++) {
            pixelMatrix[yPos][xPos] = new int[2];
            pixelMatrix[yPos][xPos][0] = defaultPixels[0];
            pixelMatrix[yPos][xPos][1] = defaultPixels[1];
            pixelMatrix[yPos][xPos][2] = defaultPixels[2];

            int currentRectStartPosX = 0;
            int currentRectEndPosX = 200;
            int currentRectStartPosY = 200;
            int currentRectEndPosY = 0;
            int currentColorIndex = 0;
            for (int i = 0; i < rowCount; i++) {
                currentRectEndPosX = 200;
                currentRectStartPosX = 0;
                for (int j = 0; j < colCount; j++) {
                    if ( (xPos > currentRectStartPosX && xPos < currentRectEndPosX) && (yPos > currentRectEndPosY && yPos < currentRectStartPosY) ) {
                        pixelMatrix[yPos][xPos][0] = colors[currentColorIndex][0];
                        pixelMatrix[yPos][xPos][1] = colors[currentColorIndex][1];
                        pixelMatrix[yPos][xPos][2] = colors[currentColorIndex][2];
                    }

                    currentRectEndPosX += 200;
                    currentRectStartPosX += 200;
                    currentColorIndex++;
                }
                currentRectEndPosY += 200;
                currentRectStartPosY += 200;
            }
        }
    }

    return pixelMatrix;
}

int*** initPixelMatrixCircle(int rowCount, int colCount, int imgWidth, int imgHeight) {
    
    int defaultPixels[3] = {140, 110, 210};
    int circleColor[3] = {34, 123, 245};
    
    int circleDiameter =  90;

    int*** pixelMatrix = new int**[imgHeight];
    int centerX = 500;
    int centerY = 500;
    
    for (int yPos = 0; yPos < imgHeight; yPos++) {
        pixelMatrix[yPos] = new int*[imgWidth];
        for (int xPos = 0; xPos < imgWidth; xPos++) {
            pixelMatrix[yPos][xPos] = new int[2];
            pixelMatrix[yPos][xPos][0] = defaultPixels[0];
            pixelMatrix[yPos][xPos][1] = defaultPixels[1];
            pixelMatrix[yPos][xPos][2] = defaultPixels[2];

            int currentRectStartPosX = 0;
            int currentRectEndPosX = 200;
            int currentRectStartPosY = 200;
            int currentRectEndPosY = 0;
            int currentColorIndex = 0;
            int distance = sqrt(pow(yPos - centerY, 2) + pow(xPos - centerX, 2));
            if (distance <  circleDiameter) {
                pixelMatrix[yPos][xPos][0] = circleColor[0];
                pixelMatrix[yPos][xPos][1] = circleColor[1];
                pixelMatrix[yPos][xPos][2] = circleColor[2];
            }
        }
    }

    return pixelMatrix;
}

void writePPM (string name, string fileType, int imgWidth, int imgHeight, int*** pixelMatrix) {
    int maxColorComponent = 255;
    std::ofstream ppmFileStream(name);
    ppmFileStream  << fileType;
    ppmFileStream << imgWidth << " " << imgHeight << "\n";
    ppmFileStream << maxColorComponent << "\n";

    for (int yPos = 0; yPos < imgHeight; yPos++) {
        
        for (int xPos = 0; xPos < imgWidth; xPos++) {
            ppmFileStream << pixelMatrix[yPos][xPos][0] << " ";
            ppmFileStream << pixelMatrix[yPos][xPos][1] << " ";
            ppmFileStream << pixelMatrix[yPos][xPos][2]  << " ";
        }

    }

    ppmFileStream.close();

}

void savePPM (RectOptions rectOptions, ImgOptions imgOptions) {
    const int rowCount = imgOptions.rowCount;
    const int colCount = imgOptions.colCount;
    const int rectWidth = rectOptions.rectWidth;
    const int rectHeight = rectOptions.rectHeight;
    const int stepIncreaseRandomValuePerRect = rectOptions.stepIncreaseRandomValuePerRect;

    const int imgWidth = rowCount * rectWidth;
    const int imgHeight = colCount * rectHeight;
    const int maxColorComponent = 255;
    const string fileType =  "P3\n";
    const string name = imgOptions.name + ".ppm";

    int defaultPixelR = 140;
    int defaultPixelG = 110;
    int defaultPixelB = 210;
    int totalRects = rowCount * colCount;
    int colors[totalRects][2];

    for (int i = 0; i < totalRects; i++) {
        colors[i][0] = (rand()%256);
        colors[i][1] = (rand()%256);
        colors[i][2] = (rand()%256);
    }
    
    int*** pixelMatrix = initPixelMatrixGrid(rowCount, colCount, imgWidth, imgHeight);
    // int*** pixelMatrix = initPixelMatrixCircle(rowCount, colCount, imgWidth, imgHeight);
    
    writePPM(name, fileType, imgWidth, imgHeight, pixelMatrix);
}
