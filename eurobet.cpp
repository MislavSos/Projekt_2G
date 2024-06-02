#include <iostream>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <string>

using namespace std;

void koef1Manji(double &koef0, double &koef_1, double &koef__1, double &koef1, double &koef_2, double &koef__2, double &koef2)
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
    koef0 = (koef1 + koef2) / 2;
}

void koef2Manji(double &koef0, double &koef_1, double &koef__1, double &koef1, double &koef_2, double &koef__2, double &koef2)
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
    koef0 = (koef1 + koef2) / 2;
}

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
            cout << "Vas dobitak: " << setprecision(3) << dobitak << "€" << endl;
            cout << "Vas profit: " << setprecision(3) << profit << "€" << endl;
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
            cout << "Vas dobitak: " << setprecision(3) << dobitak << "€" << endl;
            cout << "Vas profit: " << setprecision(3) << profit << "€" << endl;
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
            cout << "Vas dobitak: " << setprecision(3) << dobitak << "€" << endl;
            cout << "Vas profit: " << setprecision(3) << profit << "€" << endl;
        }
        else if (gol1 == gol2 || gol1 > gol2)
            cout << "Nazalost niste pogodili ishod utakmice." << endl;
    }
}

int main()
{
    cout << ".------. .------. .------. .------. .------. .------. .------." << endl;
    cout << "|E.--. | |U.--. | |R.--. | |O.--. | |B.--. | |E.--. | |T.--. |" << endl;
    cout << "| (\\/) | | (\\/) | | :(): | | :/\\: | | :(): | | (\\/) | | :/\\: |" << endl;
    cout << "| :\\/: | | :\\/: | | ()() | | :\\/: | | ()() | | :\\/: | | (__) |" << endl;
    cout << "| '--'E| | '--'U| | '--'R| | '--'O| | '--'B| | '--'E| | '--'T|" << endl;
    cout << "`------' `------' `------' `------' `------' `------' `------'" << endl;

    int izbor, tablica[10][3];
    double uplata = 0, koef, isplata;
    cout << "Kladite se odgovorno!  18+\n";
    cout << "Cijena uplate je 50c.\n";
    cout << "Izaberite ligu pomocu broja.\n";
    cout << "1. HNL\n";
    cout << "2. Premier League\n";
    cout << "3. La Liga\n";
    cout << "4. Bundesliga\n";
    cout << "5. Serie A\n";
    cout << "6. Ligue 1\n";
    cin >> izbor;
    if (izbor == 1)
    {
        cout << "\n";
        cout << "Trenutna tablica:\n"; // printanje live tablice
        cout << "HNL 2023/24\n";
        string momcadi[10] = {"GNK Dinamo Zagreb   ", "HNK Rijeka          ", "HNK Hajduk Split    ", "NK Osijek           ", "NK Lokomotiva Zagreb", "Nk Varazdin         ", "HNK Gorica          ", "NK Istra 1961       ", "NK Slaven Belupo    ", "NK Rudes             "};
        int bodovi[10] = {82, 74, 68, 57, 51, 42, 41, 41, 33, 9};
        for (int i = 0; i < 10; i++)
            cout << i + 1 << ".\t" << momcadi[i] << "\t" << bodovi[i] << endl;
        cout << "\n"; // printanje 5 random utakmica
        cout << "Utakmice ovog kola:\n";
#define br_timova 11
        char timovi[br_timova][21] = {"GNK Dinamo Zagreb", "HNK Rijeka", "HNK Hajduk Split", "NK Osijek", "NK Lokomotiva Zagreb", "NK Varazdin", "HNK Gorica", "NK Istra 1961", "NK Slaven Belupo", "NK Rudes", ""};
        char klub[br_timova][10];
        srand(time(NULL));
        int tim1, tim2, brojac = 0, tim[10];
        for (int i = 0; i < 5; i++)
        {
            cout << i + 1 << ". ";
            tim1 = rand() % br_timova;
            for (int i = 0; i < 200; i++)
                if (strcmp(timovi[tim1], "") == 0)
                    tim1 = rand() % br_timova;
            strcpy(klub[brojac], timovi[tim1]);
            tim[brojac] = tim1;
            brojac++;
            cout << timovi[tim1];
            strcpy(timovi[tim1], timovi[10]);
            cout << "\tvs\t";
            tim2 = rand() % br_timova;
            for (int i = 0; i < 200; i++)
                if (strcmp(timovi[tim2], "") == 0)
                    tim2 = rand() % br_timova;
            strcpy(klub[brojac], timovi[tim2]);
            tim[brojac] = tim2;
            brojac++;
            cout << timovi[tim2];
            strcpy(timovi[tim2], timovi[10]);
            cout << "\n";
        }
        int izbor_utk, kladjenje, rand_rez, gol1, gol2;
        double koef1, koef0, koef2, koef_1, koef__1, koef_2, koef__2, uplata, dobitak, profit;
        cout << "\n";
        cout << "Molimo unesite redni broj utakmice na koju se želite kladiti.\n";
        cin >> izbor_utk;
        if (izbor_utk == 1)
        {
            cout << "Odabrali ste utakmicu: " << klub[0] << "vs " << klub[1];
            cout << "\n";
            cout << "Kladite se prema sljedecim oznakama:\n";
            cout << "Pobjeda domaćina - 1\n";
            cout << "Neriješen rezultat - 0\n";
            cout << "Pobjeda gosta - 2\n";
            cout << "\n";
            cout << "Koeficijenti:\n";
            if (tim[0] < tim[1]) // random koef
            {
                koef1Manji(koef0, koef_1, koef__1, koef1, koef_2, koef__2, koef2);
            }
            else if (tim[1] < tim[0])
            {
                koef2Manji(koef0, koef_1, koef__1, koef1, koef_2, koef__2, koef2);
            }
            cout << "1\t" << klub[0] << ": " << setprecision(3) << koef1 << endl;
            cout << "0\tIzjednaceno/nerjeseno: " << setprecision(3) << koef0 << endl;
            cout << "2\t" << klub[1] << ": " << setprecision(3) << koef2 << endl;
            kladenje(kladjenje, gol1, gol2, uplata, koef0, koef1, koef2, dobitak, profit);
        }
        else if (izbor_utk == 2)
        {
            cout << "Odabrali ste utakmicu: " << klub[2] << "vs " << klub[3];
            cout << "\n";
            cout << "Kladite se prema sljedecim oznakama:\n";
            cout << "Pobjeda domaćina - 1\n";
            cout << "Neriješen rezultat - 0\n";
            cout << "Pobjeda gosta - 2\n";
            cout << "\n";
            cout << "Koeficijenti:\n";
            if (tim[2] < tim[3]) // random koef
            {
                koef1Manji(koef0, koef_1, koef__1, koef1, koef_2, koef__2, koef2);
            }
            else if (tim[3] < tim[2])
            {
                koef2Manji(koef0, koef_1, koef__1, koef1, koef_2, koef__2, koef2);
            }
            cout << "1\t" << klub[2] << ": " << setprecision(3) << koef1 << endl;
            cout << "0\tIzjednaceno/nerjeseno: " << setprecision(3) << koef0 << endl;
            cout << "2\t" << klub[3] << ": " << setprecision(3) << koef2 << endl;
            kladenje(kladjenje, gol1, gol2, uplata, koef0, koef1, koef2, dobitak, profit);
        }
        else if (izbor_utk == 3)
        {
            cout << "Odabrali ste utakmicu: " << klub[4] << "vs " << klub[5];
            cout << "\n";
            cout << "Kladite se prema sljedecim oznakama:\n";
            cout << "Pobjeda domaćina - 1\n";
            cout << "Neriješen rezultat - 0\n";
            cout << "Pobjeda gosta - 2\n";
            cout << "\n";
            cout << "Koeficijenti:\n";
            if (tim[4] < tim[5]) // random koef
            {
                koef1Manji(koef0, koef_1, koef__1, koef1, koef_2, koef__2, koef2);
            }
            else if (tim[5] < tim[4])
            {
                koef2Manji(koef0, koef_1, koef__1, koef1, koef_2, koef__2, koef2);
            }
            cout << "1\t" << klub[4] << ": " << setprecision(3) << koef1 << endl;
            cout << "0\tIzjednaceno/nerjeseno: " << setprecision(3) << koef0 << endl;
            cout << "2\t" << klub[5] << ": " << setprecision(3) << koef2 << endl;
            kladenje(kladjenje, gol1, gol2, uplata, koef0, koef1, koef2, dobitak, profit);
        }
        else if (izbor_utk == 4)
        {
            cout << "Odabrali ste utakmicu: " << klub[6] << "vs " << klub[7];
            cout << "\n";
            cout << "Kladite se prema sljedecim oznakama:\n";
            cout << "Pobjeda domaćina - 1\n";
            cout << "Neriješen rezultat - 0\n";
            cout << "Pobjeda gosta - 2\n";
            cout << "\n";
            cout << "Koeficijenti:\n";
            if (tim[6] < tim[7]) // random koef
            {
                koef1Manji(koef0, koef_1, koef__1, koef1, koef_2, koef__2, koef2);
            }
            else if (tim[7] < tim[6])
            {
                koef2Manji(koef0, koef_1, koef__1, koef1, koef_2, koef__2, koef2);
            }
            cout << "1\t" << klub[6] << ": " << setprecision(3) << koef1 << endl;
            cout << "0\tIzjednaceno/nerjeseno: " << setprecision(3) << koef0 << endl;
            cout << "2\t" << klub[7] << ": " << setprecision(3) << koef2 << endl;
            kladenje(kladjenje, gol1, gol2, uplata, koef0, koef1, koef2, dobitak, profit);
        }
        else if (izbor_utk == 5)
        {
            cout << "Odabrali ste utakmicu: " << klub[8] << "vs " << klub[9];
            cout << "\n";
            cout << "Kladite se prema sljedecim oznakama:\n";
            cout << "Pobjeda domaćina - 1\n";
            cout << "Neriješen rezultat - 0\n";
            cout << "Pobjeda gosta - 2\n";
            cout << "\n";
            cout << "Koeficijenti:\n";
            if (tim[8] < tim[9]) // random koef
            {
                koef1Manji(koef0, koef_1, koef__1, koef1, koef_2, koef__2, koef2);
            }
            else if (tim[9] < tim[8])
            {
                koef2Manji(koef0, koef_1, koef__1, koef1, koef_2, koef__2, koef2);
            }
            cout << "1\t" << klub[8] << ": " << setprecision(3) << koef1 << endl;
            cout << "0\tIzjednaceno/nerjeseno: " << setprecision(3) << koef0 << endl;
            cout << "2\t" << klub[9] << ": " << setprecision(3) << koef2 << endl;
            kladenje(kladjenje, gol1, gol2, uplata, koef0, koef1, koef2, dobitak, profit);
        }
    }
    return 0;
}