#include "ImageMaker.h"

// Your code goes here...


ImageMaker::ImageMaker() {
    height = 0;
    width = 0;
    pen_blue = 0;
    pen_red = 0;
    pen_green = 0;


    for(int x = 0; x < MAX_HEIGHT; x++){
        for(int y = 0; y < MAX_WIDTH; y++){
            image [x][y][RED]= 255;
            image [x][y][GREEN]= 255;
            image [x][y][BLUE]= 255;
        }
    }
}


ImageMaker::ImageMaker(string filename) {

    //sets the image to all white
    for(int j = 0; j < MAX_HEIGHT; j++){
        for(int i =0; i < MAX_WIDTH; i++){

            image[i][j][RED] = 255;
            image[i][j][GREEN] = 255;
            image[i][j][BLUE] = 255;
        }
    }

    LoadImage(filename);

    pen_blue = 0;
    pen_red = 0;
    pen_green = 0;
}


void ImageMaker::LoadImage(string filename) {

    ifstream inputFile;
    inputFile.open(filename);
    string magicNumber;
    if(!inputFile){
        throw "File failed to open";
    }
    int maxColor;
    inputFile >> magicNumber >> width >> height >> maxColor;
    if(magicNumber != "P3"){
        throw "Bad magic number";
    }
    if(width > MAX_WIDTH || width < 0){
        throw "Width out of bounds";
    }
    if(height > MAX_HEIGHT || height <0){
        throw "Height out of bounds";
    }
    if(maxColor > MAX_COLOR){
        throw "Max color range not 255";
    }


    for(int j =0; j < height; j++){
        for(int i = 0; i < width; i++){

            inputFile >> image[i][j][RED];

            if(image[i][j][RED] < 0 || image[i][j][RED] > MAX_COLOR){
                throw "Color value invalid";
            }

            inputFile >> image[i][j][GREEN];

            if(image[i][j][GREEN] < 0|| image[i][j][GREEN] > MAX_COLOR ){
                throw "Color value invalid";
            }

            inputFile >> image[i][j][BLUE];

            if(image[i][j][BLUE] < 0|| image[i][j][BLUE] > MAX_COLOR ){
                throw "Color value invalid";
            }
        }
    }
}


void ImageMaker::SaveImage(string filename) {
    ofstream outFile;
    string magicNumber = "P3"; // assuming magic number is p3
    outFile.open(filename);

    outFile << magicNumber << "\n" << width << "\n" << height << "\n" << MAX_COLOR << "\n";
    if(width <= 0 || height <= 0){
        throw "Image must have non-zero dimensions";
    }

    for(int j =0; j < height; j++){
        for(int i = 0; i < width; i++){

            outFile << image[i][j][RED] << endl;
            outFile << image[i][j][GREEN] << endl;
            outFile << image[i][j][BLUE] << endl;
        }
    }
}
int ImageMaker::GetWidth() {
    return width;
}

int ImageMaker::GetHeight() {
    return height;
}

void ImageMaker::SetWidth(int width) {
    if(width <0 || width > MAX_WIDTH){
        throw "Width out of bounds";
    }
    this->width = width;
}

void ImageMaker::SetHeight(int height) {
    if(height <0 || height > MAX_HEIGHT){
        throw "Height out of bounds";
    }
    this->height = height;
}

int ImageMaker::GetPenRed() {
    return pen_red;
}

int ImageMaker::GetPenGreen() {
    return pen_green;
}

int ImageMaker::GetPenBlue() {
    return pen_blue;
}

void ImageMaker::SetPenRed(int newR) {
    if(newR < 0 || newR >255){
        throw "Color value invalid";
    }
    pen_red = newR;
}

void ImageMaker::SetPenGreen(int newG) {
    if(newG < 0 || newG >255){
        throw "Color value invalid";
    }
    pen_green = newG;
}

void ImageMaker::SetPenBlue(int newB) {
    if(newB < 0 || newB >255){
        throw "Color value invalid";
    }
    pen_blue = newB;
}

bool ImageMaker::PointInBounds(int x, int y) {
    return x >= 0 && y >= 0 && x < width && y < height;
}

void ImageMaker::DrawPixel(int x, int y) {

    // if width and height are 0 and the x and y
    // should x and y be the arguments??
    if(PointInBounds(x,y)){
        //throw "Point out of bounds";


        //if(width< x || height < y)
        // This is from the image maker video hint
        image[x][y][RED] = GetPenRed();
        image[x][y][GREEN] = GetPenGreen();
        image[x][y][BLUE] = GetPenBlue();
    }else
        throw "Point out of bounds";
}
void ImageMaker::DrawLine(int x1, int y1, int x2, int y2) {

    if(!PointInBounds(x1,y1) || !PointInBounds(x2,y2)) {
        throw "Point out of bounds";
    }

    double slope;
    double bIntercept;
    double y3;
    int beginX =0;
    int endX=0;
    int beginY= 0;
    int endY = 0;
    if(x2 > x1){
        x2 = endX;
        x1 = beginX;
    }
    if(x2 < x1){
        x1 = endX;
        x2 = beginX;
    }

    if(y2 > y1){
        y2 =  endY;
        y1 = beginY;
    }
    if(y1>y2){
        y1=endY;
        y2 = beginY;
    }

    // vertical line
    if (x1 == x2) {
        for(int y = beginY; y <= endY; y++){
            DrawPixel(x1,y);
        }
        return;
    }

    // need additional code to handle when dividing by zero.
    slope = double(y2 - y1) / double(x2 - x1);
    bIntercept = double(y2 - slope * x2);

    for(int x = beginX; x <= endX ; x++){
        y3 = round(slope*x + bIntercept);
        DrawPixel(x1, y3);
    }

}
void ImageMaker::DrawRectangle(int x1, int y1, int x2, int y2) {

    // Calls draw line four times to draw each side of the rectangle.
    DrawLine(x1,y2,x1,y1);
    DrawLine(x2,y1,x1,y1);
    DrawLine(x2,y2,x2,y1);
    DrawLine(x2,y2,x1,y2);

}


