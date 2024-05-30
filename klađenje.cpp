#include <iostream>
#include <string>
#include <ctime>
using namespace std;
template <typename T>

void kladenje(int kladjenje, int gol1, int gol2, T uplata, T koef0, T koef1, T koef2, T dobitak, T profit)
{
    cout << "Odaberite na sto se kladite pomocu prethodnih oznaka." << endl;
    cin >> kladjenje;
    if (kladjenje == 1)
    {
        cout << "Koliko uplacujete?" << endl;
        cin >> uplata;
        srand(time(NULL));
        gol1 = rand() % 4;
        gol2 = rand() % 4;
        cout << "Rezultat: " << gol1 << ":" << gol2 << endl;
        if (gol1 > gol2)
        {
            dobitak = uplata * koef1;
            profit = (uplata * koef1) - uplata;
            cout << "Pogodili ste ishod utakmice." << endl;
            cout << "Vas dobitak: " << dobitak << endl;
            cout << "Vas profit: " << profit << endl;
        }
        else if (gol1 == gol2 || gol1 < gol2)
            cout << ("Nazalost niste pogodili ishod utakmice.\n");
    }
    else if (kladjenje == 0)
    {
        cout << "Koliko uplacujete?" << endl;
        cin >> uplata;
        srand(time(NULL));
        gol1 = rand() % 4;
        gol2 = rand() % 4;
        cout << "Rezultat: " << gol1 << ":" << gol2 << endl;
        if (gol1 == gol2)
        {
            dobitak = uplata * koef0;
            profit = (uplata * koef0) - uplata;
            cout << "Ishod utakmice: Nerijeseno" << endl;
            cout << "Pogodili ste ishod utakmice." << endl;
            cout << "Vas dobitak: " << dobitak << endl;
            cout << "Vas profit: " << profit << endl;
        }
        else if (gol1 > gol2 || gol1 < gol2)
            cout << "Nazalost niste pogodili ishod utakmice." << endl;
    }
    else if (kladjenje == 2)
    {
        cout << "Koliko uplacujete?" << endl;
        cin >> uplata;
        srand(time(NULL));
        gol1 = rand() % 4;
        gol2 = rand() % 4;
        cout << "Rezultat: " << gol1 << ":" << gol2 << endl;
        if (gol1 < gol2)
        {
            dobitak = uplata * koef2;
            profit = (uplata * koef2) - uplata;
            cout << "Pogodili ste ishod utakmice." << endl;
            cout << "Vas dobitak: " << dobitak << endl;
            cout << "Vas profit: " << profit << endl;
        }
        else if (gol1 == gol2 || gol1 > gol2)
            cout << "Nazalost niste pogodili ishod utakmice." << endl;
    }
}

int main()
{
    int kladjenje, gol1, gol2;
    double uplata, koef0, koef1, koef2, dobitak, profit;
    kladenje(kladjenje, gol1, gol2, uplata, koef0, koef1, koef2, dobitak, profit);
    return 0;
}