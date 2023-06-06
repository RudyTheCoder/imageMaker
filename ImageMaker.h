//
// Assignment Created by Varick Erickson
//

#ifndef IMAGEMAKER_H
#define IMAGEMAKER_H

#include <string>
#include <cmath>
#include <fstream>
#include <iostream>

const int MAX_WIDTH = 800;
const int MAX_HEIGHT = 800;
const int MAX_COLOR = 255;
enum COLOR { RED, GREEN, BLUE };

using namespace std;

//  Please put your pre and post comments in this file. See page 139 in the textbook.

class ImageMaker
{
public:

/*
Function: The default constructor initializes all the private variables. It also initializes the image
 matrix to white.

Precondition: N/a

Postcondition: The private variables are set to zero and the image matrix is set to white.

*/
    ImageMaker();

/*
Function: This second constructor sets the image matrix to white and handles basic error checking.

Precondition: This function requires the implementation of the LoadImage function.

Postcondition: The image matrix is set to white and the default pen is black. Basic error checking is also done.

*/
    ImageMaker(string filename);

    // Opens image with filename and stores information into

/*
Function: This function loads an image into an image matrix while doing some basic error checking.

Precondition: Must have a file to read. The values read into the private variables must be within
 specific boundaries.

Postcondition: The file has been loaded and the image matrix contains the header and body information.

*/
    void LoadImage(string filename);

/*
Function: This function writes to a file the header and body information of an image.

Precondition: Must have a file to pass in. The image must have non-zero dimensions.

Postcondition: The image has been written to a file. This function will throw and error
 message if the width or height have non-zero dimensions.

*/
    void SaveImage(string filename);

    // Size functions

/*
Function: Returns the width of the object.

Precondition: None.

Postcondition: The width of the object has been returned.

*/
    int GetWidth();

/*
Function: Returns the height of the object.

Precondition: None.

Postcondition: The height of the object has been returned.

*/

    int GetHeight();

/*
Function: This function sets the width of the object.

Precondition: The width cannot be less than zero or more than MAX_WIDTH.

Postcondition: The width has been set or will throw an error message if the width
 was set to less than zero or greater than MAX_WIDTH.

*/
    void SetWidth(int width);

/*
Function: This function sets the height of the object.

Precondition: The height cannot be less than zero or more than MAX_HEIGHT.

Postcondition: The height has been set or will throw an error message if the height
was set to less than zero or greater than MAX_HEIGHT.

*/
    void SetHeight(int height);

    // Color functions

/*
Function: This function will return the red color of the pen.

Precondition: None.

Postcondition: The red color of the pen has been returned.

*/
    int GetPenRed();

/*
Function: This function will return the green color of the pen.

Precondition: None.

Postcondition: The green color of the pen has been returned.

*/
    int GetPenGreen();

/*
Function: This function will return the blue color of the pen.

Precondition: None.

Postcondition: The blue color of the pen has been returned.

*/
    int GetPenBlue();

/*
Function: Function will set the red value of the pen object.

Precondition: The red value of the pen object cannot be less than zero or greater than MAX_COLOR.

Postcondition: The red value of the pen object has been set. This will throw an
 error message if the red value is set to less than zero or greater than MAX_COLOR.

*/
    void SetPenRed(int newR);
/*
Function: Function will set the green value of the pen object.

Precondition: The green value of the pen object cannot be less than zero or greater than MAX_COLOR.

Postcondition: The green value of the pen object has been set. This will throw an
    error message if the green value is set to less than zero or greater than MAX_COLOR.

*/
    void SetPenGreen(int newG);

/*
Function: Function will set the blue value of the pen object.

Precondition: The blue value of the pen object cannot be less than zero or greater than MAX_COLOR.

Postcondition: The blue value of the pen object has been set. This will throw an
     error message if the blue value is set to less than zero or greater than MAX_COLOR.

*/
    void SetPenBlue(int newB);

    // Drawing methods
    // These methods will use the current red, green, blue values of the pen

/*
Function: Function will color the coordinate x,y according to the specified pen color.

Precondition: The coordinate must be in bounds.

Postcondition: The coordinate will be colored with the specified color. An error message will
 pop up if the coordinate is out of bounds.

*/
    void DrawPixel(int x, int y);

/*
Function: Function will draw a rectangle with the color that was specified by the user.


Precondition: The coordinate must be within the bounds according to the width and height
 of the image file.

Postcondition: A rectangle will be drawn using the current red, blue and green colors. If
 a coordinate is not within bounds of the image matrix, an error message will be displayed.

*/
    void DrawRectangle(int x1, int y1, int x2, int y2);

    /*
Function: DrawLine draws a line using the current values of the red, green, and blue.

Precondition: The coordinates must be within the bounds of the image file.

Postcondition: A line will be drawn using the current red, blue and green colors. If
 a coordinate is not within bounds of the image matrix, an error message will be displayed.

*/
    void DrawLine(int x1, int y1, int x2, int y2);

private:
    string magic;
    int width;
    int height;
    int pen_red;    // Used by draw functions
    int pen_green;  // Used by draw functions
    int pen_blue;   // Used by draw functions

/*
Function: This function returns true or false whether the coordinate is in bounds or not.

Precondition: The coordinate must be within bounds.

Postcondition: Returns true if the coordinate is within bounds and false otherwise.

*/
    bool PointInBounds(int x, int y);  // Not a bad idea to implement

               //   x          y
    short image[MAX_WIDTH][MAX_HEIGHT][3];
};

#endif //IMAGEMAKER_H
