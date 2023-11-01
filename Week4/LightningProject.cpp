#include <iostream>
#include <cmath>
using namespace std;

class LightningStrike
{
private:
    int Io;
    unsigned int a, b;
public:
    void setIo(int Io);
    void setA(unsigned int a);
    void setB(unsigned int b);
    float getIo();
    float getA();
    float getB();
    float getCurrent(float time);
};

void LightningStrike::setIo(int Io){this->Io = Io;}
void LightningStrike::setA(unsigned int a){
    
    if (a<0)
    {
        cout << "Error: a cannot be negative" << endl;
        return;
    }
    this->a = a;
}
void LightningStrike::setB(unsigned int b){
    
    if (b<0)
    {
        cout << "Error: b cannot be negative" << endl;
        return;
    }
    this->b = b;
}


float LightningStrike::getIo(){return(this->Io);}
float LightningStrike::getA(){return(this->a);}
float LightningStrike::getB(){return(this->b);}


float LightningStrike::getCurrent(float t)
{
    return (Io * (exp(-a * t) - exp(-b * t)));
}


#include <fstream>

int main(){

      LightningStrike aStrike;

      aStrike.setIo(30000);
      aStrike.setA(20e3);
      aStrike.setB(10e3);

// Note can no longer do aStrike.Io=30000; // Private data says the compiler error

// Getting test data from a client can be a challenge - so guessed sensible values
// from the figure in the spec and checked the plot came out "roughly" as shown there

// Connect a stream to file

      ofstream outputFileStream("currentForPlot.txt");

      float time(0),timeStep(1e-5);

      do {
            // Choosing format to make it importable into excel for plotting

            // Note how the "file stream" is used as we would use "cout"

            outputFileStream<<"\n"<<time<<","<<aStrike.getCurrent(time);

            time+=timeStep;

      } while(time<1e-3); // Plot up to 1 ms

      outputFileStream.close(); // Don't forget this!

/// Note this might save you grief in the future. If you leave a file like
/// currentForPlot.txt open in Excel, then a rerun of this code cannot overwrite
/// it - but you don't get told!!! Close the excel file first

}