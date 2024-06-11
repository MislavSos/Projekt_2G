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
    #define br_timova 11
    char klub[br_timova][21];
    int izbor_utk, kladjenje, rand_rez, gol1, gol2, tim[10];
    double koef1, koef0, koef2, koef_1, koef__1, koef_2, koef__2, uplata, dobitak, profit;
    char timovi[br_timova][21] = {"GNK Dinamo Zagreb ",
                                  "HNK Hajduk Split ",
                                  "NK Osijek ",
                                  "HNK Rijeka ",
                                  "NK Istra 1961 ",
                                  "NK Varazdin ",
                                  "NK Lokomotiva Zagreb",
                                  "NK Slaven Belupo ",
                                  "HNK Gorica ",
                                  "HNK Sibenik ",
                                  ""};
    if (izbor_utk == 1)
    {
        cout << "Odabrali ste utakmicu: " << klub[0] << "vs " << klub[1];
        cout << "\n";
        cout << "Kladite se prema sljedecim oznakama:\n";
        cout << "Pobjeda domaćina - 1\n";
        cout << "Neriješen rezultat - X\n";
        cout << "Pobjeda gosta - 2\n";
        cout << "\n";
        cout << "Koeficijenti:\n";
        if (tim[0] < tim[1]) // random koef
        {
            do
            {
                koef_1 = rand() % 100;
                koef__1 = rand() % 100;
                koef1 = rand() % 2 + (koef_1 / koef__1);
            } while (koef1 <= 1 || koef1 > 2);
            do
            {
                koef2 = rand() % 10;
                koef_2 = rand() % 100;
                koef__2 = rand() % 100;
                koef2 = rand() % 7 + (koef_2 / koef__2);
            } while (koef2 <= 2 || koef2 >= 7);
        }
        else if (tim[1] < tim[0])
        {
            do
            {
                koef_2 = rand() % 100;
                koef__2 = rand() % 100;
                koef2 = rand() % 2 + (koef_2 / koef__2);
            } while (koef2 <= 1 || koef2 > 2);
            do
            {
                koef_1 = rand() % 100;
                koef__1 = rand() % 100;
                koef1 = rand() % 7 + (koef_1 / koef__1);
            } while (koef1 <= 2 || koef1 >= 7);
        }
        koef0 = (koef2 + koef1) / 2;
        cout << "1\t" << klub[0] << ": " << koef1 << endl;
        cout << "X\tIzjednaceno/nerjeseno: " << koef0 << endl;
        cout << "2\t" << klub[1] << ": " << koef2 << endl;
    }
    kladenje(kladjenje, gol1, gol2, uplata, koef0, koef1, koef2, dobitak, profit);
    return 0;
}