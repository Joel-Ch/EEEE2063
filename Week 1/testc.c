#include "stdio.h"
#include "stdlib.h"
#include "time.h"

int main(int argc, char const *argv[])
{
        srand(time(NULL));
        float randNum, y;
        for (size_t i = 0; i < 100; i++)
        {
        randNum = rand()%100;
        y=(randNum)/50 -1;
        printf("| %2.0f : %5.2f |\n", randNum, y);
        }
        

    return 0;
}
