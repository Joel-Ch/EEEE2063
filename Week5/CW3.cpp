#include <iostream>

using namespace std;

class pixel
{
private:
    float xCoordinate;
    float yCoordinate;
    char brightness;

public:
    pixel(float _xCoordinate, float _yCoordinate, char _brightness); // constructor
    ~pixel();                                                        // destructor
    pixel(const pixel &other);                                       // copy constructor
    pixel &operator=(const pixel &other);                            // copy assignment operator

    pixel() : xCoordinate(0), yCoordinate(0), brightness(0) {}

    void changeCoordinate(float _xCoordinate, float _yCoordinate);

    void changeBrightness(char _brightness);

    float getXCoordinate();

    float getYCoordinate();

    char getBrightness();

    void printPixel();
};

class icon
{
private:
    int id;
    pixel IconPixel[16];

public:
    icon(int _id, pixel _IconPixel[16]); // constructor
    ~icon();                             // destructor
    icon(const icon &other);             // copy constructor
    icon &operator=(const icon &other);  // copy assignment operator

    icon() : id(0) {} // default constructor

    int getId();

    pixel getSpecifiedPixel(int _pixelIndex);

    void changeIcon(int _id, pixel _IconPixel[16]);

    void changeSinglePixel(int _pixelIndex, pixel *_IconPixel);

    void printIcon();
};

class radarDisplay
{
private:
    icon *iconsToDisplay[100];
    int noOfActiveIcons;

public:
    radarDisplay();                                     // constructor
    ~radarDisplay();                                    // destructor
    radarDisplay(const radarDisplay &other);            // copy constructor
    radarDisplay &operator=(const radarDisplay &other); // copy assignment operator

    void addIcon(icon *_iconToAdd);

    void removeIcon(int _iconId);

    void displayIcon(int _iconId);
};

// ---------------------- Function Prototypes ----------------------
void showPixelDetail(pixel thisPixel);
void showIconDetail(icon *thisIcon);
void initialiseAsDefaultDiagonalLine(icon &thisIcon);

// ---------------------- Big Fours ----------------------
pixel::pixel(float _xCoordinate, float _yCoordinate, char _brightness)
{
    xCoordinate = _xCoordinate;
    yCoordinate = _yCoordinate;
    brightness = _brightness;
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

icon::icon(int _id, pixel _IconPixel[16])
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

void pixel::changeCoordinate(float _xCoordinate, float _yCoordinate)
{
    xCoordinate = _xCoordinate;
    yCoordinate = _yCoordinate;
}

void pixel::changeBrightness(char _brightness)
{
    if (_brightness < 0 || _brightness > 15)
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

char pixel::getBrightness()
{
    return brightness;
}

void pixel::printPixel()
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

pixel icon::getSpecifiedPixel(int _pixelIndex)
{
    if (_pixelIndex < 0 || _pixelIndex > 15)
    {
        cout << "ERROR - CANNOT GET SPECIFIED PIXEL: Invalid pixel index" << endl;
        return pixel();
    }

    return IconPixel[_pixelIndex];
}

void icon::changeIcon(int _id, pixel _IconPixel[16])
{
    id = _id;
    for (int i = 0; i < 16; i++)
    {
        IconPixel[i] = _IconPixel[i];
    }
}

void icon::changeSinglePixel(int _pixelIndex, pixel *_IconPixel)
{
    IconPixel[_pixelIndex] = *_IconPixel;
}

void icon::printIcon()
{
    cout << "id: " << id << endl;
    for (int i = 0; i < 16; i++)
    {
        cout << "Pixel " << i << endl;
        IconPixel[i].printPixel();
    }
}

// ------------------------------------------------------

void radarDisplay::addIcon(icon *_iconToAdd)
{
    // Check if there is space for the icon
    if (noOfActiveIcons >= 100)
    {
        cout << "ERROR - CANNOT ADD ICON: No more space for icons" << endl;
        return;
    }

    // Check for duplicate icon IDs
    for (int i = 0; i < noOfActiveIcons; i++)
    {
        if (iconsToDisplay[i] != NULL && iconsToDisplay[i]->getId() == _iconToAdd->getId())
        {
            cout << "ERROR - CANNOT ADD ICON: Duplicate icon ID: " << _iconToAdd->getId() << endl;
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

void radarDisplay::removeIcon(int _iconId)
{
    // Check if there are any active icons
    if (noOfActiveIcons <= 0)
    {
        cout << "ERROR - CANNOT REMOVE ICON: No active icons" << endl;
        noOfActiveIcons = 0;
        return;
    }
    bool iconFound = false;
    for (int i = 0; i < 100; i++)
    {
        if (iconsToDisplay != NULL && iconsToDisplay[i]->getId() == _iconId)
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
        cout << "ERROR - CANNOT REMOVE ICON: Icon not found" << endl;
    }
}

void radarDisplay::displayIcon(int _iconId)
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
            showIconDetail(iconsToDisplay[i]);
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

// ---------------------- Functions ----------------------

void showPixelDetail(pixel thisPixel)
{
    cout << "xCoordinate: " << thisPixel.getXCoordinate() << endl;
    cout << "yCoordinate: " << thisPixel.getYCoordinate() << endl;
    cout << "brightness: " << (int)thisPixel.getBrightness() << endl;
}

void showIconDetail(icon *thisIcon)
{
    cout << "id: " << thisIcon->getId() << endl;
    for (int i = 0; i < 16; i++)
    {
        cout << "Pixel " << i << endl;
        showPixelDetail(thisIcon->getSpecifiedPixel(i));
    }
}

void initialiseAsDefaultDiagonalLine(icon &thisIcon)
{
    pixel *pixelArray = new pixel[16];
    for (size_t i = 0; i < 16; i++)
    {
        pixelArray[i] = pixel(i, i, 15);
    }

    thisIcon.changeIcon(0, pixelArray);
    delete[] pixelArray;
}

// ---------------------- Main  For Sub-Task 2 ----------------------

// int main() {
//     pixel aPixel(3.9,4.1,7);
//     aPixel.printPixel();
//     return 0;
// }

// ---------------------- Main  For Sub-Task 3 ----------------------

// int main() {
//     pixel aPixel(3.9,4.1,7);
//     showPixelDetail(aPixel);
// }

// ---------------------- Main  For Sub-Task 4 ----------------------

// int main() {
//     pixel* pixelArray = new pixel[16];
//     icon myIcon(7, pixelArray);
//     pixel pixelOne(3.9,4.1,7);
//     myIcon.changeSinglePixel(0, &pixelOne);
//     myIcon.printIcon();
//     delete[] pixelArray;
//     return 0;
// }

// ---------------------- Main  For Sub-Task 5 ----------------------

// int main() {
//     pixel* pixelArray = new pixel[16];
//     for (size_t i = 0; i < 16; i++)
//     {
//         pixelArray[i] = pixel(i,i,15);
//     }
//     icon myIcon(7,pixelArray);
//     delete[] pixelArray;
//     showIconDetail(&myIcon);
//     return 0;
// }

// ---------------------- Main  For Sub-Task 6 ----------------------

// int main() {
//     icon myIcon;
//     initialiseAsDefaultDiagonalLine(myIcon);
//     showIconDetail(&myIcon);
//     return 0;
// }

// ---------------------- Main  For Sub-Task 7 ----------------------

int main()
{
    radarDisplay Display1;
    radarDisplay Display2;

    icon allTheIcons[500];

    initialiseAsDefaultDiagonalLine(allTheIcons[0]);

    // allTheIcons[0].printIcon();

    Display1.addIcon(&allTheIcons[0]);

    Display2.addIcon(&allTheIcons[0]);

    Display1.displayIcon(0);

    Display2.displayIcon(0);

    cout << "-------------------" << endl;

    Display1.removeIcon(0);

    Display1.displayIcon(0);

    Display1.removeIcon(1);

    Display1.addIcon(&allTheIcons[0]);

    return 0;
}