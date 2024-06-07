#include <iostream>
#include <ctime>
using namespace std;

void golovi(int &gol1, int &gol2)
{
    srand(time(NULL));
    gol1 = rand() % 4;
    gol2 = rand() % 4;
}

int main()
{
    int gol1, gol2;
    golovi(gol1, gol2);
    cout << gol1 << ":" << gol2;
    return 0;
}