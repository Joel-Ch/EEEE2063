#include <iostream>

using namespace std;

// ----------------------------------------------------------------
//
//                     Radar Display Project
//
//              Including Pixel, Icon and Radar Display objects
//
//              (Along with rigorous test mains)
//
//              Copyright Joel Chiappetti
//
// ----------------------------------------------------------------

// NOTE TO MARKER: Sub Tasks 3 \& 6 have two separate implementations, both as member functions and external functions.

// ---------------------- Class Declarations ----------------------

// a simple class to represent a pixel, with x and y coordinates and brightness
// included are get and set functions to view and change the data held within
// requires <iostream>
// copyright Joel Chiappetti
class pixel
{
private:
    float xCoordinate;
    float yCoordinate;
    unsigned char brightness; // 0-20

public:
    pixel(const float _xCoordinate, const float _yCoordinate, const unsigned char _brightness); // constructor
    ~pixel();                                                                                   // destructor
    pixel(const pixel &other);                                                                  // copy constructor
    pixel &operator=(const pixel &other);                                                       // copy assignment operator
    pixel() : xCoordinate(0), yCoordinate(0), brightness(0) {}                                  // default constructor

    // getters
    float getXCoordinate();
    float getYCoordinate();
    unsigned char getBrightness();

    // setters
    void changeCoordinate(const float _xCoordinate, const float _yCoordinate);
    void changeBrightness(const unsigned char _brightness);

    // display function
    void showPixelDetail();
};

// a class to represent an icon, with an id and an array of 16 pixels
// functions include standard getters and setters, along with changing the icon and displaying the icon
// default icon is a diagonal line
// requires <iostream>
// copyright Joel Chiappetti
class icon
{
private:
    int id;
    pixel IconPixel[16];

    // a function to initialise the icon as a diagonal line
    void initialiseAsDefaultDiagonalLine();

public:
    icon(const int _id, pixel _IconPixel[16]);    // constructor
    ~icon();                                      // destructor
    icon(const icon &other);                      // copy constructor
    icon &operator=(const icon &other);           // copy assignment operator
    icon() { initialiseAsDefaultDiagonalLine(); } // default constructor - initialises as a diagonal line

    // getters
    int getId();
    pixel *getPixelArray();
    pixel getSpecifiedPixel(unsigned const char _pixelIndex);

    // setters
    void changeIcon(const int _id, pixel _IconPixel[16]);
    void changeSinglePixel(unsigned const char _pixelIndex, pixel *_IconPixel);

    // display functions
    void showIconDetail();
};

// a class to represent a radar display, with an array of pointers to icons
// functions include adding and removing icon pointers, and displaying an icon
// the display can hold up to 100 icons
// the display can only hold one icon with a given id
// featuring exhaustive error checking
// requires <iostream>
// copyright Joel Chiappetti
class radarDisplay
{
private:
    icon *iconsToDisplay[100];
    unsigned char noOfActiveIcons;

public:
    radarDisplay();                                     // constructor
    ~radarDisplay();                                    // destructor
    radarDisplay(const radarDisplay &other);            // copy constructor
    radarDisplay &operator=(const radarDisplay &other); // copy assignment operator

    // getters
    icon getIcon(const int _iconId);

    // setters
    void addIcon(icon *_iconToAdd);

    // display functions
    void displayIcon(const int _iconId);

    // other functions
    void removeIcon(const int _iconId);
};

// ---------------------- Functions ----------------------

// function to display a pixels values on screen
// inputs: the pixel to display
// outputs: prints xcoordinate, ycoordinate and brightness to the terminal
// requires: <iostream>
void showAPixelsDetail(pixel ThisPixel);

// function to initialise an icon with a diagonal line
// inputs: a pointer to the icon to initialise
// outputs: changes the icon
// requires: <iostream> (for debugging)
void InitialiseAsDefaultDiagonalLine(icon *_iconToInitialise);

// ---------------------- Big Fours ----------------------
pixel::pixel(const float _xCoordinate, const float _yCoordinate, const unsigned char _brightness)
{
    if (_brightness < 0 || _brightness > 20)
    {
        cout << "ERROR - CANNOT CHANGE BRIGHTNESS: Invalid brightness value" << endl;
        return;
    }
    else
    {
        brightness = _brightness;
    }
    xCoordinate = _xCoordinate;
    yCoordinate = _yCoordinate;
}

pixel::~pixel()
{
}

pixel::pixel(const pixel &other)
{
    xCoordinate = other.xCoordinate;
    yCoordinate = other.yCoordinate;
    brightness = other.brightness;
}

pixel &pixel::operator=(const pixel &other)
{
    xCoordinate = other.xCoordinate;
    yCoordinate = other.yCoordinate;
    brightness = other.brightness;
    return *this;
}

icon::icon(const int _id, pixel _IconPixel[16])
{
    id = _id;
    for (int i = 0; i < 16; i++)
    {
        IconPixel[i] = _IconPixel[i];
    }
}

icon::~icon()
{
}

icon::icon(const icon &other)
{
    id = other.id;
    for (int i = 0; i < 16; i++)
    {
        IconPixel[i] = other.IconPixel[i];
    }
}

icon &icon::operator=(const icon &other)
{
    id = other.id;
    for (int i = 0; i < 16; i++)
    {
        IconPixel[i] = other.IconPixel[i];
    }
    return *this;
}

radarDisplay::radarDisplay()
{
    noOfActiveIcons = 0;
    for (int i = 0; i < 100; i++)
    {
        iconsToDisplay[i] = NULL;
    }
}

radarDisplay::~radarDisplay()
{
}

radarDisplay::radarDisplay(const radarDisplay &other)
{
    noOfActiveIcons = other.noOfActiveIcons;
    for (int i = 0; i < 100; i++)
    {
        iconsToDisplay[i] = other.iconsToDisplay[i];
    }
}

radarDisplay &radarDisplay::operator=(const radarDisplay &other)
{
    noOfActiveIcons = other.noOfActiveIcons;
    for (int i = 0; i < 100; i++)
    {
        iconsToDisplay[i] = other.iconsToDisplay[i];
    }
    return *this;
}

// ---------------------- Implementation ----------------------

void pixel::changeCoordinate(const float _xCoordinate, const float _yCoordinate)
{
    xCoordinate = _xCoordinate;
    yCoordinate = _yCoordinate;
}

void pixel::changeBrightness(const unsigned char _brightness)
{
    if (_brightness < 0 || _brightness > 20)
    {
        cout << "ERROR - CANNOT CHANGE BRIGHTNESS: Invalid brightness value" << endl;
        return;
    }
    else
    {
        brightness = _brightness;
    }
}

float pixel::getXCoordinate()
{
    return xCoordinate;
}

float pixel::getYCoordinate()
{
    return yCoordinate;
}

unsigned char pixel::getBrightness()
{
    return brightness;
}

void pixel::showPixelDetail()
{
    cout << "xCoordinate: " << xCoordinate << endl;
    cout << "yCoordinate: " << yCoordinate << endl;
    cout << "brightness: " << (int)brightness << endl;
}

// ------------------------------------------------------

int icon::getId()
{
    return id;
}

pixel *icon::getPixelArray()
{
    return IconPixel;
}

pixel icon::getSpecifiedPixel(unsigned const char _pixelIndex)
{
    return IconPixel[_pixelIndex];
}

void icon::changeIcon(const int _id, pixel _IconPixel[16])
{
    id = _id;
    for (int i = 0; i < 16; i++)
    {
        IconPixel[i] = _IconPixel[i];
    }
}

void icon::changeSinglePixel(unsigned const char _pixelIndex, pixel *_IconPixel)
{
    IconPixel[_pixelIndex] = *_IconPixel;
}

void icon::showIconDetail()
{
    cout << "id: " << id << endl;
    for (int i = 0; i < 16; i++)
    {
        cout << "Pixel " << i << endl;
        IconPixel[i].showPixelDetail();
    }
}

void icon::initialiseAsDefaultDiagonalLine()
{
    id = 7;
    for (size_t i = 0; i < 16; i++)
    {
        IconPixel[i] = pixel(i, i, 15);
    }
}

// ------------------------------------------------------

void radarDisplay::addIcon(icon *_iconToAdd)
{
    // Check if there is space for the icon
    if (noOfActiveIcons >= 100)
    {
        cout << "ERROR - CANNOT ADD ICON   : No more space for icons" << endl;
        return;
    }

    // Check for duplicate icon IDs
    for (int i = 0; i < noOfActiveIcons; i++)
    {
        if (iconsToDisplay[i] != NULL && iconsToDisplay[i]->getId() == _iconToAdd->getId())
        {
            cout << "ERROR - CANNOT ADD ICON   : Duplicate icon ID: " << _iconToAdd->getId() << endl;
            return;
        }
    }

    // Add the icon to the display
    for (int i = 0; i < 100; i++)
    {
        if (iconsToDisplay[i] == NULL)
        {
            iconsToDisplay[i] = _iconToAdd;
            noOfActiveIcons++;
            break;
        }
    }
}

icon radarDisplay::getIcon(const int _iconId)
{
    // Check if there are any active icons
    if (noOfActiveIcons <= 0)
    {
        cout << "ERROR - CANNOT GET ICON    : No active icons" << endl;
        noOfActiveIcons = 0;
        return icon();
    }
    bool iconFound = false;

    // Find the icon
    for (int i = 0; i < 100; i++)
    {
        if (iconsToDisplay[i] != NULL && iconsToDisplay[i]->getId() == _iconId)
        {
            iconFound = true;
            return *iconsToDisplay[i];
        }
    }

    // If no icon is found
    if (!iconFound)
    {
        cout << "ERROR - CANNOT GET ICON    : Icon not found" << endl;
        return icon();
    }

    // unknown error
    cout << "ERROR - CANNOT GET ICON    : Unknown error" << endl;
    return icon();
}

void radarDisplay::removeIcon(const int _iconId)
{
    // Check if there are any active icons
    if (noOfActiveIcons <= 0)
    {
        cout << "ERROR - CANNOT REMOVE ICON : No active icons" << endl;
        noOfActiveIcons = 0;
        return;
    }
    bool iconFound = false;
    for (int i = 0; i < 100; i++)
    {
        if (iconsToDisplay[i] != NULL && iconsToDisplay[i]->getId() == _iconId)
        {
            iconsToDisplay[i] = NULL;
            iconFound = true;
            noOfActiveIcons--;
            break;
        }
    }

    // If no icon is found
    if (!iconFound)
    {
        cout << "ERROR - CANNOT REMOVE ICON : Icon not found" << endl;
    }
}

void radarDisplay::displayIcon(const int _iconId)
{
    // Check if there are any active icons
    if (noOfActiveIcons <= 0)
    {
        cout << "ERROR - CANNOT DISPLAY ICON: No active icons" << endl;
        noOfActiveIcons = 0;
        return;
    }
    bool iconFound = false;

    // Find the icon
    for (int i = 0; i < 100; i++)
    {
        if (iconsToDisplay[i] != NULL && iconsToDisplay[i]->getId() == _iconId)
        {
            iconsToDisplay[i]->showIconDetail();
            iconFound = true;
            break;
        }
    }

    // If no icon is found
    if (!iconFound)
    {
        cout << "ERROR - CANNOT DISPLAY ICON: Icon not found" << endl;
    }
}

// ---------------------- External Functions ----------------------

void showAPixelsDetail(pixel ThisPixel)
{
    cout << "xCoordinate: " << ThisPixel.getXCoordinate() << endl;
    cout << "yCoordinate: " << ThisPixel.getYCoordinate() << endl;
    cout << "brightness: " << (int)ThisPixel.getBrightness() << endl;
}

void InitialiseAsDefaultDiagonalLine(icon *_iconToInitialise)
{
    pixel *pixelArray = new pixel[16];
    for (size_t i = 0; i < 16; i++)
    {
        pixelArray[i] = pixel(i, i, 15);
    }
    _iconToInitialise->changeIcon(7, pixelArray);

    delete[] pixelArray;
    return;
}

// ---------------------- Main  For Sub-Task 2 ----------------------

// int main()
// {
//     pixel aPixel(3.9, 4.1, 7);
//     aPixel.showPixelDetail();
//     return 0;
// }

// ---------------------- Main  For Sub-Task 3 ----------------------

// (This version uses a member function)

// int main()
// {
//     pixel aPixel(3.9, 4.1, 7);
//     aPixel.showPixelDetail();             // as this is a member function, it doesn't need to be passed an instance of pixel
//     return 0;
// }

// ---------------------- Alternative Main for Sub-Task 3 -----------

// (This version uses an external function)

// int main()
// {
//     pixel aPixel(3.9, 4.1, 7);
//     showAPixelsDetail(aPixel);
//     return 0;
// }

// ---------------------- Main  For Sub-Task 4 ----------------------

// int main()
// {
//     icon myIcon;
//     pixel pixelOne(3.9, 4.1, 7);
//     myIcon.getPixelArray()[0] = pixelOne; // copy pixelOne into pixelArray[0]
//     // myIcon.changeSinglePixel(0,&pixelOne);    //alternatively
//     myIcon.showIconDetail();
//     return 0;
// }

// ---------------------- Main  For Sub-Task 5 ----------------------

// int main()
// {
//     pixel *pixelArray = new pixel[16];
//     for (size_t i = 0; i < 16; i++)
//     {
//         pixelArray[i] = pixel(i, i, 15);
//     }
//     icon myIcon(7, pixelArray);
//     delete[] pixelArray;
//     myIcon.showIconDetail();
//     return 0;
// }

// ---------------------- Main  For Sub-Task 6 ----------------------

// (This version uses a member function)

// int main()
// {
//     icon myIcon; // the default constructor calls a function 'initialiseAsDefaultDiagonalLine'
//     myIcon.showIconDetail();
//     return 0;
// }

// ---------------------- Alternative Main  For Sub-Task 6 ----------

// (This version uses an external function)

// int main()
// {
//     icon myIcon;
//     InitialiseAsDefaultDiagonal(&myIcon); // this is an external function, but achieves the same result as above
//     myIcon.showIconDetail();
//     return 0;
// }

// ---------------------- Main  For Sub-Task 7 ----------------------

int main()
{
    radarDisplay Display1;
    radarDisplay Display2;

    icon allTheIcons[500];

    cout << "-------------------" << endl; // set up the tests

    allTheIcons[0].showIconDetail(); // this shows the default icon

    Display1.addIcon(&allTheIcons[0]); // this adds the default icon to the display

    Display2.addIcon(&allTheIcons[0]);

    cout << "-------------------" << endl; // display the icons

    Display1.displayIcon(7); // this displays the default icon

    Display2.displayIcon(7);

    cout << "-------------------" << endl; // test the remove function

    Display1.removeIcon(7); // this removes the default icon from the display

    Display1.displayIcon(7); // this should give an error message

    Display1.removeIcon(7); // this should also give an error message

    cout << "-------------------" << endl; // make sure that changing an icon changes the icon within the display

    allTheIcons[0].changeIcon(4, allTheIcons[0].getPixelArray()); // this changes the icon id to 4

    Display2.displayIcon(7); // this should give an error as the id has been changed

    Display2.displayIcon(4); // this should display the icon

    return 0;
}