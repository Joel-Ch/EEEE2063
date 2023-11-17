#include <iostream>

using namespace std;

class pixel
{
private:
    float xCoordinate;
    float yCoordinate;
    char brightness;
public:
    pixel(float _xCoordinate,float _yCoordinate,char _brightness);
    ~pixel();
    pixel(const pixel& other);
    pixel& operator=(const pixel& other);
    
    pixel() : xCoordinate(0), yCoordinate(0), brightness(0) {}

    void changeCoordinate(float _xCoordinate,float _yCoordinate);

    void changeBrightness(char _brightness);

    float getXCoordinate();

    float getYCoordinate();

    char getBrightness();

    void printPixel();
};
// ---------------------- Big Four ----------------------
pixel::pixel(float _xCoordinate, float _yCoordinate,char _brightness)
{
    xCoordinate = _xCoordinate;
    yCoordinate = _yCoordinate;
    brightness = _brightness;
}

pixel::~pixel()
{
}

pixel::pixel(const pixel& other)
{
    xCoordinate = other.xCoordinate;
    yCoordinate = other.yCoordinate;
    brightness = other.brightness;
}

pixel& pixel::operator=(const pixel& other)
{
    xCoordinate = other.xCoordinate;
    yCoordinate = other.yCoordinate;
    brightness = other.brightness;
    return *this;
}

// ---------------------- Implementation ----------------------

void pixel::changeCoordinate(float _xCoordinate,float _yCoordinate)
{
    xCoordinate = _xCoordinate;
    yCoordinate = _yCoordinate;
}

void pixel::changeBrightness(char _brightness)
{
    brightness = _brightness;
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
class icon
{
private:
    int id;
    pixel IconPixel[16];
public:
    icon(int _id,pixel _IconPixel[16]);
    ~icon();
    icon(const icon& other);
    icon& operator=(const icon& other);

    icon() : id(0) {}
    

    int getId();

    pixel getSpecifiedPixel(int _pixelIndex);

    void changeIcon(int _id,pixel _IconPixel[16]);

    void changeSinglePixel(int _pixelIndex,pixel _IconPixel);

    void printIcon();

};

// ---------------------- Big Four ----------------------
icon::icon(int _id,pixel _IconPixel[16])
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

icon::icon(const icon& other)
{
    id = other.id;
    for (int i = 0; i < 16; i++)
    {
        IconPixel[i] = other.IconPixel[i];
    }
}

icon& icon::operator=(const icon& other)
{
    id = other.id;
    for (int i = 0; i < 16; i++)
    {
        IconPixel[i] = other.IconPixel[i];
    }
    return *this;
}

// ---------------------- Implementation ----------------------

int icon::getId()
{
    return id;
}

pixel icon::getSpecifiedPixel(int _pixelIndex)
{
    return IconPixel[_pixelIndex];
}

void icon::changeIcon(int _id,pixel _IconPixel[16])
{
    id = _id;
    for (int i = 0; i < 16; i++)
    {
        IconPixel[i] = _IconPixel[i];
    }
}

void icon::changeSinglePixel(int _pixelIndex,pixel _IconPixel)
{
    IconPixel[_pixelIndex] = _IconPixel;
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
class radarDisplay
{
private:

    icon* iconsToDisplay[100];

public:
    radarDisplay();
    ~radarDisplay();
    radarDisplay(const radarDisplay& other);
    radarDisplay& operator=(const radarDisplay& other);

    void addIcon(icon* _iconToAdd);

    void removeIcon(int _iconId);

    void displayIcon(int _iconId);    

};

// ---------------------- Big Four ----------------------

radarDisplay::radarDisplay()
{
}

radarDisplay::~radarDisplay()
{
}

radarDisplay::radarDisplay(const radarDisplay& other)
{
}

radarDisplay& radarDisplay::operator=(const radarDisplay& other)
{
}

// ---------------------- Implementation ----------------------

void radarDisplay::addIcon(icon* _iconToAdd)
{
    for (int i = 0; i < 100; i++)
    {
        if (iconsToDisplay[i] == NULL)
        {
            iconsToDisplay[i] = _iconToAdd;
            break;
        }
    }
}

void radarDisplay::removeIcon(int _iconId)
{
    for (int i = 0; i < 100; i++)
    {
        if (iconsToDisplay[i]->getId() == _iconId)
        {
            iconsToDisplay[i] = NULL;
            break;
        }
    }
}

void radarDisplay::displayIcon(int _iconId)
{
    for (int i = 0; i < 100; i++)
    {
        if (iconsToDisplay[i]->getId() == _iconId)
        {
            showIconDetail(iconsToDisplay[i]);
            break;
        }
    }
}




// ---------------------- Functions ----------------------

void showPixelDetail(pixel thisPixel)
{
    cout << "xCoordinate: " << thisPixel.getXCoordinate() << endl;
    cout << "yCoordinate: " << thisPixel.getYCoordinate() << endl;
    cout << "brightness: " << (int)thisPixel.getBrightness() << endl;
}

void showIconDetail(icon* thisIcon)
{
    cout << "id: " << thisIcon->getId() << endl;
    for (int i = 0; i < 16; i++)
    {
        cout << "Pixel " << i << endl;
        showPixelDetail(thisIcon->getSpecifiedPixel(i));
    }
}

void initialiseAsDefaultDiagonalLine(icon& thisIcon)
{
    pixel* pixelArray = new pixel[16];
    for (size_t i = 0; i < 16; i++)
    {
        pixelArray[i] = pixel(i,i,15);
    }
    
    thisIcon.changeIcon(7,pixelArray);
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
//     myIcon.changeSinglePixel(0, pixelOne);
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

int main() {
    radarDisplay myRadarDisplay;

    return 0;
}