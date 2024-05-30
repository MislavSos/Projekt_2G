#include <iostream>
#include <string>
#include <ctime>
using namespace std;

void koef2Manji(double koef0, double koef_1, double koef__1, double koef1, double koef_2, double koef__2, double koef2)
{
    do
    {
        koef_1 = rand() % 100;
        koef__1 = rand() % 100;
        koef1 = rand() % 7 + (koef_1 / koef__1);
    } while (koef1 <= 1 || koef1 > 2);
    do
    {
        koef2 = rand() % 10;
        koef_2 = rand() % 100;
        koef__2 = rand() % 100;
        koef2 = rand() % 2 + (koef_2 / koef__2);
    } while (koef2 <= 2 || koef2 >= 7);
    koef0 = (koef2 + koef1) / 2;
    cout << koef1 << endl<< koef0 <<endl<< koef2 << endl;
}
int main()
{
    double koef0, koef_1, koef__1, koef1, koef_2, koef__2, koef2;
    koef2Manji(koef0, koef_1, koef__1, koef1, koef_2, koef__2, koef2);
    return 0;
}