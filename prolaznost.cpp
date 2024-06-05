#include <iostream>
#include <string>
#include <ctime>
using namespace std;

template <typename T>
void prolaznost(int kladjenje, int gol1, int gol2, T prolaznost_listica)
{
    if (kladjenje == 1)
    {
        if (gol1 > gol2)
        {
            prolaznost_listica = true;
        }
        else if (gol1 == gol2 || gol1 < gol2)
            prolaznost_listica = false;
    }
    else if (kladjenje == 0)
    {
        if (gol1 == gol2)
        {
            prolaznost_listica = true;
        }
        else if (gol1 > gol2 || gol1 < gol2)
            prolaznost_listica = false;
    }
    else if (kladjenje == 2)
    {
        if (gol1 < gol2)
        {
            prolaznost_listica = true;
        }
        else if (gol1 == gol2 || gol1 > gol2)
            prolaznost_listica = false;
    }
}

int main()
{
    int kladjenje, gol1, gol2, prolaznost_listica;
    prolaznost(kladjenje, gol1, gol2, prolaznost_listica);
    return 0;
}