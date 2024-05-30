#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
using namespace std;

void koef1Manji(double koef0, double koef_1, double koef__1, double koef1, double koef_2, double koef__2, double koef2)
{
    do
    {
        koef_1 = rand() % 100;
        koef__1 = rand() % 100;
        koef1 = rand() % 2 + (koef_1 / koef__1);
    } while (koef1 <= 1 || koef1 > 2);
    do
    {
        koef_2 = rand() % 100;
        koef__2 = rand() % 100;
        koef2 = rand() % 7 + (koef_2 / koef__2);
    } while (koef2 <= 2 || koef2 >= 7);
    koef0 = (koef2 + koef1) / 2;
    cout << setprecision(3) << koef1 << endl;
    cout << setprecision(3) << koef0 << endl;
    cout << setprecision(3) << koef2 << endl;
}
int main()
{
    double koef0, koef_1, koef__1, koef1, koef_2, koef__2, koef2;
    koef1Manji(koef0, koef_1, koef__1, koef1, koef_2, koef__2, koef2);
    return 0;
}