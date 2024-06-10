#include <iostream>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

void krivi_unos(int kladjenje)
{
    while (kladjenje > 2 || kladjenje < 0)
    {
        cout << "Krivi unos." << endl;
        cin >> kladjenje;
    }
}
void ocistiTerminal()
{
    cout << "\033[2J\033[1;1H";
}
void koef1Manji(double &koef0, double &koef_1, double &koef__1, double &koef1, double &koef_2, double &koef__2, double &koef2)
{
    do
    {
        koef_1 = rand() % 100;
        koef__1 = rand() % 100;
        koef1 = rand() % 2 + (koef_1 / koef__1);
    } while (koef1 <= 1.15 || koef1 > 2.5);
    do
    {
        koef_2 = rand() % 100;
        koef__2 = rand() % 100;
        koef2 = rand() % 7 + (koef_2 / koef__2);
    } while (koef2 <= 2.5 || koef2 >= 7);
    koef0 = (koef1 + koef2) / 2;
}
void koef2Manji(double &koef0, double &koef_1, double &koef__1, double &koef1, double &koef_2, double &koef__2, double &koef2)
{
    do
    {
        koef_2 = rand() % 100;
        koef__2 = rand() % 100;
        koef2 = rand() % 2 + (koef_2 / koef__2);
    } while (koef2 <= 1.15 || koef2 > 2.5);
    do
    {
        koef_1 = rand() % 100;
        koef__1 = rand() % 100;
        koef1 = rand() % 7 + (koef_1 / koef__1);
    } while (koef1 <= 2.5 || koef1 >= 7);
    koef0 = (koef1 + koef2) / 2;
}
void golovi(int &gol1, int &gol2)
{
    gol1 = rand() % 5;
    gol2 = rand() % 5;
}
template <typename T>
void prolaznost(int kladjenje, int gol1, int gol2, T &prolaznost_para)
{
    if (kladjenje == 1)
    {
        if (gol1 > gol2)
        {
            prolaznost_para = true;
        }
        else if (gol1 == gol2 || gol1 < gol2)
        {
            prolaznost_para = false;
        }
    }
    else if (kladjenje == 0)
    {
        if (gol1 == gol2)
        {
            prolaznost_para = true;
        }
        else if (gol1 > gol2 || gol1 < gol2)
        {
            prolaznost_para = false;
        }
    }
    else if (kladjenje == 2)
    {
        if (gol1 < gol2)
        {
            prolaznost_para = true;
        }
        else if (gol1 == gol2 || gol1 > gol2)
        {
            prolaznost_para = false;
        }
    }
}

int main()
{
    ocistiTerminal();
    cout << ".------. .------. .------. .------. .------. .------. .------." << endl;
    cout << "|E.--. | |U.--. | |R.--. | |O.--. | |B.--. | |E.--. | |T.--. |" << endl;
    cout << "| (\\/) | | (\\/) | | :(): | | :/\\: | | :(): | | (\\/) | | :/\\: |" << endl;
    cout << "| :\\/: | | :\\/: | | ()() | | :\\/: | | ()() | | :\\/: | | (__) |" << endl;
    cout << "| '--'E| | '--'U| | '--'R| | '--'O| | '--'B| | '--'E| | '--'T|" << endl;
    cout << "`------' `------' `------' `------' `------' `------' `------'" << endl;

    srand(time(NULL));
    int izbor, tablica[10][3];
    bool nastaviKladenje = true;
    string nastavakKladenja;
    cout << "Kladite se odgovorno!  18+" << endl;
    cout << "Cijena uplate je 50c." << endl;
pocetak:
    cout << "Izaberite ligu pomocu broja." << endl;
    cout << "1. HNL" << endl;
    cout << "2. Premier League" << endl;
    cout << "3. La Liga" << endl;
    cout << "4. Bundesliga" << endl;
    cout << "5. Serie A" << endl;
    cout << "6. Ligue 1" << endl;
    cin >> izbor;
    fstream utakmice, rezultat_tekmi;
    string ispis_tekmi, ispis_rezultata;
    int kladjenje, izbor_utk;
    double koef_ukupno, koef1, koef0, koef2, koef_1, koef__1, koef_2, koef__2;

    if (izbor == 1)
    {
        cout << "\n";
        cout << "Trenutna tablica:\n"; // printanje live tablice
        cout << "HNL 2023/24\n";
        string momcadi[10] = {"GNK Dinamo Zagreb   ", "HNK Rijeka          ", "HNK Hajduk Split    ", "NK Osijek           ", "NK Lokomotiva Zagreb", "Nk Varazdin         ", "HNK Gorica          ", "NK Istra 1961       ", "NK Slaven Belupo    ", "NK Rudes             "};
        int bodovi[10] = {82, 74, 68, 57, 51, 42, 41, 41, 33, 9};
        for (int i = 0; i < 10; i++)
            cout << i + 1 << ".\t" << momcadi[i] << "\t" << bodovi[i] << endl;
        cout << endl; // printanje 5 random utakmica
        cout << "Utakmice ovog kola:" << endl;
        char timovi[11][21] = {"GNK Dinamo Zagreb", "HNK Rijeka", "HNK Hajduk Split", "NK Osijek", "NK Lokomotiva Zagreb", "NK Varazdin", "HNK Gorica", "NK Istra 1961", "NK Slaven Belupo", "NK Rudes", ""};
        char klub[11][21];
        srand(time(NULL));
        int tim1, tim2, brojac = 0, tim[10];
        for (int i = 0; i < 5; i++)
        {
            cout << i + 1 << ". ";
            tim1 = rand() % 11;
            for (int i = 0; i < 200; i++)
                if (strcmp(timovi[tim1], "") == 0)
                    tim1 = rand() % 11;
            strcpy(klub[brojac], timovi[tim1]);
            tim[brojac] = tim1;
            brojac++;
            cout << timovi[tim1];
            strcpy(timovi[tim1], timovi[10]);
            cout << "\tvs\t";
            tim2 = rand() % 11;
            for (int i = 0; i < 200; i++)
                if (strcmp(timovi[tim2], "") == 0)
                    tim2 = rand() % 11;
            strcpy(klub[brojac], timovi[tim2]);
            tim[brojac] = tim2;
            brojac++;
            cout << timovi[tim2];
            strcpy(timovi[tim2], timovi[10]);
            cout << "\n";
        }
        int izbor_utk, rand_rez;
        double koef1, koef0, koef2, koef_1, koef__1, koef_2, koef__2;
        cout << endl;
    ovo_koloHNL:
        cout << "Molimo unesite redni broj utakmice na koju se želite kladiti." << endl;
        cin >> izbor_utk;
        if (izbor_utk == 1)
        {
            cout << "Odabrali ste utakmicu: " << klub[0] << " vs " << klub[1];
            cout << endl;
            cout << "Kladite se prema sljedecim oznakama:" << endl;
            cout << "Pobjeda domaćina - 1" << endl;
            cout << "Neriješen rezultat - 0" << endl;
            cout << "Pobjeda gosta - 2" << endl;
            cout << endl;
            cout << "Koeficijenti:" << endl;
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
            cin >> kladjenje;
            krivi_unos(kladjenje);
            if (kladjenje == 1)
                koef_ukupno += koef1;
            else if (kladjenje == 0)
                koef_ukupno += koef0;
            else if (kladjenje == 2)
                koef_ukupno += koef2;
            utakmice.open("utakmice.txt", ios::app);
            utakmice << klub[0] << " vs " << klub[1] << "\t" << "Vas odabir: " << kladjenje << endl;
            utakmice.close();
            fstream odabrani_koef("odabrani_koef.bin", ios::binary | ios::out | ios::app);
            odabrani_koef.write((char *)&kladjenje, sizeof(kladjenje));
            odabrani_koef.close();
            rezultat_tekmi.open("rezultat_tekmi.txt", ios::app);
            rezultat_tekmi << klub[0] << " vs " << klub[1] << "\t" << endl;
            rezultat_tekmi.close();
        }
        else if (izbor_utk == 2)
        {
            cout << "Odabrali ste utakmicu: " << klub[2] << " vs " << klub[3];
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
            cin >> kladjenje;
            krivi_unos(kladjenje);
            if (kladjenje == 1)
                koef_ukupno += koef1;
            else if (kladjenje == 0)
                koef_ukupno += koef0;
            else if (kladjenje == 2)
                koef_ukupno += koef2;
            utakmice.open("utakmice.txt", ios::app);
            utakmice << klub[2] << " vs " << klub[3] << "\t" << "Vas odabir: " << kladjenje << endl;
            utakmice.close();
            fstream odabrani_koef("odabrani_koef.bin", ios::binary | ios::out | ios::app);
            odabrani_koef.write((char *)&kladjenje, sizeof(kladjenje));
            odabrani_koef.close();
            rezultat_tekmi.open("rezultat_tekmi.txt", ios::app);
            rezultat_tekmi << klub[2] << " vs " << klub[3] << "\t" << endl;
            rezultat_tekmi.close();
        }
        else if (izbor_utk == 3)
        {
            cout << "Odabrali ste utakmicu: " << klub[4] << " vs " << klub[5];
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
            cin >> kladjenje;
            krivi_unos(kladjenje);
            if (kladjenje == 1)
                koef_ukupno += koef1;
            else if (kladjenje == 0)
                koef_ukupno += koef0;
            else if (kladjenje == 2)
                koef_ukupno += koef2;
            utakmice.open("utakmice.txt", ios::app);
            utakmice << klub[4] << " vs " << klub[5] << "\t" << "Vas odabir: " << kladjenje << endl;
            utakmice.close();
            fstream odabrani_koef("odabrani_koef.bin", ios::binary | ios::out | ios::app);
            odabrani_koef.write((char *)&kladjenje, sizeof(kladjenje));
            odabrani_koef.close();
            rezultat_tekmi.open("rezultat_tekmi.txt", ios::app);
            rezultat_tekmi << klub[4] << " vs " << klub[5] << "\t" << endl;
            rezultat_tekmi.close();
        }
        else if (izbor_utk == 4)
        {
            cout << "Odabrali ste utakmicu: " << klub[6] << " vs " << klub[7];
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
            cin >> kladjenje;
            krivi_unos(kladjenje);
            if (kladjenje == 1)
                koef_ukupno += koef1;
            else if (kladjenje == 0)
                koef_ukupno += koef0;
            else if (kladjenje == 2)
                koef_ukupno += koef2;
            utakmice.open("utakmice.txt", ios::app);
            utakmice << klub[6] << " vs " << klub[7] << "\t" << "Vas odabir: " << kladjenje << endl;
            utakmice.close();
            fstream odabrani_koef("C:/Users/Gb-gama/Documents/GitHub/Projekt_2G/odabrani_koef.bin", ios::binary | ios::out | ios::app);
            odabrani_koef.write((char *)&kladjenje, sizeof(kladjenje));
            odabrani_koef.close();
            rezultat_tekmi.open("rezultat_tekmi.txt", ios::app);
            rezultat_tekmi << klub[6] << " vs " << klub[7] << "\t" << endl;
            rezultat_tekmi.close();
        }
        else if (izbor_utk == 5)
        {
            cout << "Odabrali ste utakmicu: " << klub[8] << " vs " << klub[9];
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
            cin >> kladjenje;
            krivi_unos(kladjenje);
            if (kladjenje == 1)
                koef_ukupno += koef1;
            else if (kladjenje == 0)
                koef_ukupno += koef0;
            else if (kladjenje == 2)
                koef_ukupno += koef2;
            utakmice.open("utakmice.txt", ios::app);
            utakmice << klub[8] << " vs " << klub[9] << "\t" << "Vas odabir: " << kladjenje << endl;
            utakmice.close();
            fstream odabrani_koef("odabrani_koef.bin", ios::binary | ios::out | ios::app);
            odabrani_koef.write((char *)&kladjenje, sizeof(kladjenje));
            odabrani_koef.close();
            rezultat_tekmi.open("rezultat_tekmi.txt", ios::app);
            rezultat_tekmi << klub[8] << " vs " << klub[9] << "\t" << endl;
            rezultat_tekmi.close();
        }
        cout << "Zelite li se nastaviti kladiti? Da/Ne" << endl;
        cin >> nastavakKladenja;
        int kolo_ili_liga;
        if (nastavakKladenja == "Da" || nastavakKladenja == "da")
        {
            cout << "Ako se zelite nastaviti kladiti na klubove u ovom kolu upisite 1, a ako se zelite nastaviti kladiti na klubove u drugim ligama upisite 2." << endl;
            cin >> kolo_ili_liga;
            if (kolo_ili_liga == 1)
                goto ovo_koloHNL;
            else if (kolo_ili_liga == 2)
                goto pocetak;
        }
        else
            cout << endl;
    }
    else if (izbor == 2)
    {
        cout << "\n";
        cout << "Trenutna tablica:\n"; // printanje live tablice
        cout << "Premier League 2023/24\n";
        string momcadi[20] = {"Manchester City       ", "Arsenal               ", "Liverpool             ", "Aston Villa           ", "Tottenham Hotspur     ", "Chelsea               ", "Newcastle United      ", "Manchester United     ", "West Ham United       ", "Crystal Palace        ", "Brighton & Hove Albion", "Bournemouth           ", "Fulham                ", "Wolverhampton         ", "Everton               ", "Brentford             ", "Nottingham Forest     ", "Luton Town            ", "Burnley               ", "Sheffield United      "};
        int bodovi[20] = {91, 89, 82, 68, 66, 63, 60, 60, 52, 49, 48, 48, 47, 46, 40, 39, 32, 26, 24, 16};
        for (int i = 0; i < 20; i++)
            cout << i + 1 << ".\t" << momcadi[i] << "\t" << bodovi[i] << endl;
        cout << endl; // printanje 10 random utakmica
        cout << "Utakmice ovog kola:" << endl;
        char timovi[21][23] = {"Manchester City", "Arsenal", "Liverpool", "Aston Villa", "Tottenham Hotspur", "Chelsea", "Newcastle United", "Manchester United", "West Ham United", "Crystal Palace", "Brighton & Hove Albion", "Bournemouth", "Fulham", "Wolverhampton", "Everton", "Brentford", "Nottingham Forest", "Luton Town", "Burnley", "Sheffield United", ""};
        char klub[21][23];
        srand(time(NULL));
        int tim1, tim2, brojac = 0, tim[20];
        for (int i = 0; i < 10; i++)
        {
            cout << i + 1 << ". ";
            tim1 = rand() % 21;
            for (int i = 0; i < 200; i++)
                if (strcmp(timovi[tim1], "") == 0)
                    tim1 = rand() % 21;
            strcpy(klub[brojac], timovi[tim1]);
            tim[brojac] = tim1;
            brojac++;
            cout << timovi[tim1];
            strcpy(timovi[tim1], timovi[20]);
            cout << "\tvs\t";
            tim2 = rand() % 21;
            for (int i = 0; i < 200; i++)
                if (strcmp(timovi[tim2], "") == 0)
                    tim2 = rand() % 21;
            strcpy(klub[brojac], timovi[tim2]);
            tim[brojac] = tim2;
            brojac++;
            cout << timovi[tim2];
            strcpy(timovi[tim2], timovi[20]);
            cout << "\n";
        }
        ovo_koloPL:
        cout << "Molimo unesite redni broj utakmice na koju se želite kladiti." << endl;
        cin >> izbor_utk;
        if (izbor_utk == 1)
        {
            cout << "Odabrali ste utakmicu: " << klub[0] << " vs " << klub[1];
            cout << endl;
            cout << "Kladite se prema sljedecim oznakama:" << endl;
            cout << "Pobjeda domaćina - 1" << endl;
            cout << "Neriješen rezultat - 0" << endl;
            cout << "Pobjeda gosta - 2" << endl;
            cout << endl;
            cout << "Koeficijenti:" << endl;
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
            cin >> kladjenje;
            krivi_unos(kladjenje);
            if (kladjenje == 1)
                koef_ukupno += koef1;
            else if (kladjenje == 0)
                koef_ukupno += koef0;
            else if (kladjenje == 2)
                koef_ukupno += koef2;
            utakmice.open("utakmice.txt", ios::app);
            utakmice << klub[0] << " vs " << klub[1] << "\t" << "Vas odabir: " << kladjenje << endl;
            utakmice.close();
            fstream odabrani_koef("odabrani_koef.bin", ios::binary | ios::out | ios::app);
            odabrani_koef.write((char *)&kladjenje, sizeof(kladjenje));
            odabrani_koef.close();
            rezultat_tekmi.open("rezultat_tekmi.txt", ios::app);
            rezultat_tekmi << klub[0] << " vs " << klub[1] << "\t" << endl;
            rezultat_tekmi.close();
        }
        else if (izbor_utk == 2)
        {
            cout << "Odabrali ste utakmicu: " << klub[2] << " vs " << klub[3];
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
            cin >> kladjenje;
            krivi_unos(kladjenje);
            if (kladjenje == 1)
                koef_ukupno += koef1;
            else if (kladjenje == 0)
                koef_ukupno += koef0;
            else if (kladjenje == 2)
                koef_ukupno += koef2;
            utakmice.open("utakmice.txt", ios::app);
            utakmice << klub[2] << " vs " << klub[3] << "\t" << "Vas odabir: " << kladjenje << endl;
            utakmice.close();
            fstream odabrani_koef("odabrani_koef.bin", ios::binary | ios::out | ios::app);
            odabrani_koef.write((char *)&kladjenje, sizeof(kladjenje));
            odabrani_koef.close();
            rezultat_tekmi.open("rezultat_tekmi.txt", ios::app);
            rezultat_tekmi << klub[2] << " vs " << klub[3] << "\t" << endl;
            rezultat_tekmi.close();
        }
        else if (izbor_utk == 3)
        {
            cout << "Odabrali ste utakmicu: " << klub[4] << " vs " << klub[5];
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
            cin >> kladjenje;
            krivi_unos(kladjenje);
            if (kladjenje == 1)
                koef_ukupno += koef1;
            else if (kladjenje == 0)
                koef_ukupno += koef0;
            else if (kladjenje == 2)
                koef_ukupno += koef2;
            utakmice.open("utakmice.txt", ios::app);
            utakmice << klub[4] << " vs " << klub[5] << "\t" << "Vas odabir: " << kladjenje << endl;
            utakmice.close();
            fstream odabrani_koef("odabrani_koef.bin", ios::binary | ios::out | ios::app);
            odabrani_koef.write((char *)&kladjenje, sizeof(kladjenje));
            odabrani_koef.close();
            rezultat_tekmi.open("rezultat_tekmi.txt", ios::app);
            rezultat_tekmi << klub[4] << " vs " << klub[5] << "\t" << endl;
            rezultat_tekmi.close();
        }
        else if (izbor_utk == 4)
        {
            cout << "Odabrali ste utakmicu: " << klub[6] << " vs " << klub[7];
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
            cin >> kladjenje;
            krivi_unos(kladjenje);
            if (kladjenje == 1)
                koef_ukupno += koef1;
            else if (kladjenje == 0)
                koef_ukupno += koef0;
            else if (kladjenje == 2)
                koef_ukupno += koef2;
            utakmice.open("utakmice.txt", ios::app);
            utakmice << klub[6] << " vs " << klub[7] << "\t" << "Vas odabir: " << kladjenje << endl;
            utakmice.close();
            fstream odabrani_koef("C:/Users/Gb-gama/Documents/GitHub/Projekt_2G/odabrani_koef.bin", ios::binary | ios::out | ios::app);
            odabrani_koef.write((char *)&kladjenje, sizeof(kladjenje));
            odabrani_koef.close();
            rezultat_tekmi.open("rezultat_tekmi.txt", ios::app);
            rezultat_tekmi << klub[6] << " vs " << klub[7] << "\t" << endl;
            rezultat_tekmi.close();
        }
        else if (izbor_utk == 5)
        {
            cout << "Odabrali ste utakmicu: " << klub[8] << " vs " << klub[9];
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
            cin >> kladjenje;
            krivi_unos(kladjenje);
            if (kladjenje == 1)
                koef_ukupno += koef1;
            else if (kladjenje == 0)
                koef_ukupno += koef0;
            else if (kladjenje == 2)
                koef_ukupno += koef2;
            utakmice.open("utakmice.txt", ios::app);
            utakmice << klub[8] << " vs " << klub[9] << "\t" << "Vas odabir: " << kladjenje << endl;
            utakmice.close();
            fstream odabrani_koef("odabrani_koef.bin", ios::binary | ios::out | ios::app);
            odabrani_koef.write((char *)&kladjenje, sizeof(kladjenje));
            odabrani_koef.close();
            rezultat_tekmi.open("rezultat_tekmi.txt", ios::app);
            rezultat_tekmi << klub[8] << " vs " << klub[9] << "\t" << endl;
            rezultat_tekmi.close();
        }
        if (izbor_utk == 6)
        {
            cout << "Odabrali ste utakmicu: " << klub[10] << " vs " << klub[11];
            cout << endl;
            cout << "Kladite se prema sljedecim oznakama:" << endl;
            cout << "Pobjeda domaćina - 1" << endl;
            cout << "Neriješen rezultat - 0" << endl;
            cout << "Pobjeda gosta - 2" << endl;
            cout << endl;
            cout << "Koeficijenti:" << endl;
            if (tim[10] < tim[11]) // random koef
            {
                koef1Manji(koef0, koef_1, koef__1, koef1, koef_2, koef__2, koef2);
            }
            else if (tim[11] < tim[10])
            {
                koef2Manji(koef0, koef_1, koef__1, koef1, koef_2, koef__2, koef2);
            }
            cout << "1\t" << klub[0] << ": " << setprecision(3) << koef1 << endl;
            cout << "0\tIzjednaceno/nerjeseno: " << setprecision(3) << koef0 << endl;
            cout << "2\t" << klub[1] << ": " << setprecision(3) << koef2 << endl;
            cin >> kladjenje;
            krivi_unos(kladjenje);
            if (kladjenje == 1)
                koef_ukupno += koef1;
            else if (kladjenje == 0)
                koef_ukupno += koef0;
            else if (kladjenje == 2)
                koef_ukupno += koef2;
            utakmice.open("utakmice.txt", ios::app);
            utakmice << klub[10] << " vs " << klub[11] << "\t" << "Vas odabir: " << kladjenje << endl;
            utakmice.close();
            fstream odabrani_koef("odabrani_koef.bin", ios::binary | ios::out | ios::app);
            odabrani_koef.write((char *)&kladjenje, sizeof(kladjenje));
            odabrani_koef.close();
            rezultat_tekmi.open("rezultat_tekmi.txt", ios::app);
            rezultat_tekmi << klub[10] << " vs " << klub[11] << "\t" << endl;
            rezultat_tekmi.close();
        }
        else if (izbor_utk == 7)
        {
            cout << "Odabrali ste utakmicu: " << klub[12] << " vs " << klub[13];
            cout << "\n";
            cout << "Kladite se prema sljedecim oznakama:\n";
            cout << "Pobjeda domaćina - 1\n";
            cout << "Neriješen rezultat - 0\n";
            cout << "Pobjeda gosta - 2\n";
            cout << "\n";
            cout << "Koeficijenti:\n";
            if (tim[12] < tim[13]) // random koef
            {
                koef1Manji(koef0, koef_1, koef__1, koef1, koef_2, koef__2, koef2);
            }
            else if (tim[13] < tim[12])
            {
                koef2Manji(koef0, koef_1, koef__1, koef1, koef_2, koef__2, koef2);
            }
            cout << "1\t" << klub[12] << ": " << setprecision(3) << koef1 << endl;
            cout << "0\tIzjednaceno/nerjeseno: " << setprecision(3) << koef0 << endl;
            cout << "2\t" << klub[13] << ": " << setprecision(3) << koef2 << endl;
            cin >> kladjenje;
            krivi_unos(kladjenje);
            if (kladjenje == 1)
                koef_ukupno += koef1;
            else if (kladjenje == 0)
                koef_ukupno += koef0;
            else if (kladjenje == 2)
                koef_ukupno += koef2;
            utakmice.open("utakmice.txt", ios::app);
            utakmice << klub[12] << " vs " << klub[13] << "\t" << "Vas odabir: " << kladjenje << endl;
            utakmice.close();
            fstream odabrani_koef("odabrani_koef.bin", ios::binary | ios::out | ios::app);
            odabrani_koef.write((char *)&kladjenje, sizeof(kladjenje));
            odabrani_koef.close();
            rezultat_tekmi.open("rezultat_tekmi.txt", ios::app);
            rezultat_tekmi << klub[12] << " vs " << klub[13] << "\t" << endl;
            rezultat_tekmi.close();
        }
        else if (izbor_utk == 8)
        {
            cout << "Odabrali ste utakmicu: " << klub[14] << " vs " << klub[15];
            cout << "\n";
            cout << "Kladite se prema sljedecim oznakama:\n";
            cout << "Pobjeda domaćina - 1\n";
            cout << "Neriješen rezultat - 0\n";
            cout << "Pobjeda gosta - 2\n";
            cout << "\n";
            cout << "Koeficijenti:\n";
            if (tim[14] < tim[15]) // random koef
            {
                koef1Manji(koef0, koef_1, koef__1, koef1, koef_2, koef__2, koef2);
            }
            else if (tim[15] < tim[14])
            {
                koef2Manji(koef0, koef_1, koef__1, koef1, koef_2, koef__2, koef2);
            }
            cout << "1\t" << klub[14] << ": " << setprecision(3) << koef1 << endl;
            cout << "0\tIzjednaceno/nerjeseno: " << setprecision(3) << koef0 << endl;
            cout << "2\t" << klub[15] << ": " << setprecision(3) << koef2 << endl;
            cin >> kladjenje;
            krivi_unos(kladjenje);
            if (kladjenje == 1)
                koef_ukupno += koef1;
            else if (kladjenje == 0)
                koef_ukupno += koef0;
            else if (kladjenje == 2)
                koef_ukupno += koef2;
            utakmice.open("utakmice.txt", ios::app);
            utakmice << klub[14] << " vs " << klub[15] << "\t" << "Vas odabir: " << kladjenje << endl;
            utakmice.close();
            fstream odabrani_koef("odabrani_koef.bin", ios::binary | ios::out | ios::app);
            odabrani_koef.write((char *)&kladjenje, sizeof(kladjenje));
            odabrani_koef.close();
            rezultat_tekmi.open("rezultat_tekmi.txt", ios::app);
            rezultat_tekmi << klub[14] << " vs " << klub[15] << "\t" << endl;
            rezultat_tekmi.close();
        }
        else if (izbor_utk == 9)
        {
            cout << "Odabrali ste utakmicu: " << klub[16] << " vs " << klub[17];
            cout << "\n";
            cout << "Kladite se prema sljedecim oznakama:\n";
            cout << "Pobjeda domaćina - 1\n";
            cout << "Neriješen rezultat - 0\n";
            cout << "Pobjeda gosta - 2\n";
            cout << "\n";
            cout << "Koeficijenti:\n";
            if (tim[16] < tim[17]) // random koef
            {
                koef1Manji(koef0, koef_1, koef__1, koef1, koef_2, koef__2, koef2);
            }
            else if (tim[17] < tim[16])
            {
                koef2Manji(koef0, koef_1, koef__1, koef1, koef_2, koef__2, koef2);
            }
            cout << "1\t" << klub[16] << ": " << setprecision(3) << koef1 << endl;
            cout << "0\tIzjednaceno/nerjeseno: " << setprecision(3) << koef0 << endl;
            cout << "2\t" << klub[17] << ": " << setprecision(3) << koef2 << endl;
            cin >> kladjenje;
            krivi_unos(kladjenje);
            if (kladjenje == 1)
                koef_ukupno += koef1;
            else if (kladjenje == 0)
                koef_ukupno += koef0;
            else if (kladjenje == 2)
                koef_ukupno += koef2;
            utakmice.open("utakmice.txt", ios::app);
            utakmice << klub[16] << " vs " << klub[17] << "\t" << "Vas odabir: " << kladjenje << endl;
            utakmice.close();
            fstream odabrani_koef("C:/Users/Gb-gama/Documents/GitHub/Projekt_2G/odabrani_koef.bin", ios::binary | ios::out | ios::app);
            odabrani_koef.write((char *)&kladjenje, sizeof(kladjenje));
            odabrani_koef.close();
            rezultat_tekmi.open("rezultat_tekmi.txt", ios::app);
            rezultat_tekmi << klub[16] << " vs " << klub[17] << "\t" << endl;
            rezultat_tekmi.close();
        }
        else if (izbor_utk == 10)
        {
            cout << "Odabrali ste utakmicu: " << klub[18] << " vs " << klub[19];
            cout << "\n";
            cout << "Kladite se prema sljedecim oznakama:\n";
            cout << "Pobjeda domaćina - 1\n";
            cout << "Neriješen rezultat - 0\n";
            cout << "Pobjeda gosta - 2\n";
            cout << "\n";
            cout << "Koeficijenti:\n";
            if (tim[18] < tim[19]) // random koef
            {
                koef1Manji(koef0, koef_1, koef__1, koef1, koef_2, koef__2, koef2);
            }
            else if (tim[19] < tim[18])
            {
                koef2Manji(koef0, koef_1, koef__1, koef1, koef_2, koef__2, koef2);
            }
            cout << "1\t" << klub[18] << ": " << setprecision(3) << koef1 << endl;
            cout << "0\tIzjednaceno/nerjeseno: " << setprecision(3) << koef0 << endl;
            cout << "2\t" << klub[19] << ": " << setprecision(3) << koef2 << endl;
            cin >> kladjenje;
            krivi_unos(kladjenje);
            if (kladjenje == 1)
                koef_ukupno += koef1;
            else if (kladjenje == 0)
                koef_ukupno += koef0;
            else if (kladjenje == 2)
                koef_ukupno += koef2;
            utakmice.open("utakmice.txt", ios::app);
            utakmice << klub[18] << " vs " << klub[19] << "\t" << "Vas odabir: " << kladjenje << endl;
            utakmice.close();
            fstream odabrani_koef("odabrani_koef.bin", ios::binary | ios::out | ios::app);
            odabrani_koef.write((char *)&kladjenje, sizeof(kladjenje));
            odabrani_koef.close();
            rezultat_tekmi.open("rezultat_tekmi.txt", ios::app);
            rezultat_tekmi << klub[18] << " vs " << klub[19] << "\t" << endl;
            rezultat_tekmi.close();
        }
        cout << "Zelite li se nastaviti kladiti? Da/Ne" << endl;
        cin >> nastavakKladenja;
        int kolo_ili_liga;
        if (nastavakKladenja == "Da" || nastavakKladenja == "da")
        {
            cout << "Ako se zelite nastaviti kladiti na klubove u ovom kolu upisite 1, a ako se zelite nastaviti kladiti na klubove u drugim ligama upisite 2." << endl;
            cin >> kolo_ili_liga;
            if (kolo_ili_liga == 1)
                goto ovo_koloPL;
            else if (kolo_ili_liga == 2)
                goto pocetak;
        }
        else
            cout << endl;
    }
    else if(izbor == 3)
    {
        cout << "\n";
        cout << "Trenutna tablica:\n"; // printanje live tablice
        cout << "La Liga 2023/24\n";
        string momcadi[20] = {
            "Real Madrid     ", "Barcelona      ", "Girona FC      ",
            "Atletico Madrid ", "Athletic Club  ", "Real Sociedad  ",
            "Real Betis      ", "Villareal      ", "Valencia       ",
            "Deportivo Alaves", "Osasuna        ", "Getafe         ",
            "Celta Vigo      ", "Sevilla        ", "Mallorca       ",
            "Las Palmas      ", "Rayo Vallecano ", "Cadiz          ",
            "Almeria         ", "Granada        "};
        int bodovi[20] = {95, 85, 81, 76, 68, 60, 57, 53, 49, 46, 45, 43, 41, 41, 40, 40, 38, 33, 21, 21};
        for (int i = 0; i < 20; i++)
            cout << i + 1 << ".\t" << momcadi[i] << "\t" << bodovi[i] << endl;
        cout << endl; // printanje 10 random utakmica
        cout << "Utakmice ovog kola:" << endl;
        char timovi[21][17] = {"Real Madrid", "Barcelona", "Girona FC", "Atletico Madrid", "Athletic Club", "Real Sociedad", "Real Betis", "Villareal", "Valencia", "Deportivo Alaves", "Osasuna", "Getafe", "Celta Vigo", "Sevilla", "Mallorca", "Las Palmas", "Rayo Vallecano", "Cadiz", "Almeria", "Granada", ""};
        char klub[21][17];
        srand(time(NULL));
        int tim1, tim2, brojac = 0, tim[20];
        for (int i = 0; i < 10; i++)
        {
            cout << i + 1 << ". ";
            tim1 = rand() % 21;
            for (int i = 0; i < 200; i++)
                if (strcmp(timovi[tim1], "") == 0)
                    tim1 = rand() % 21;
            strcpy(klub[brojac], timovi[tim1]);
            tim[brojac] = tim1;
            brojac++;
            cout << timovi[tim1];
            strcpy(timovi[tim1], timovi[20]);
            cout << "\tvs\t";
            tim2 = rand() % 21;
            for (int i = 0; i < 200; i++)
                if (strcmp(timovi[tim2], "") == 0)
                    tim2 = rand() % 21;
            strcpy(klub[brojac], timovi[tim2]);
            tim[brojac] = tim2;
            brojac++;
            cout << timovi[tim2];
            strcpy(timovi[tim2], timovi[20]);
            cout << "\n";
        }
    ovo_koloLL:
        cout << "Molimo unesite redni broj utakmice na koju se želite kladiti." << endl;
        cin >> izbor_utk;
        if (izbor_utk == 1)
        {
            cout << "Odabrali ste utakmicu: " << klub[0] << " vs " << klub[1];
            cout << endl;
            cout << "Kladite se prema sljedecim oznakama:" << endl;
            cout << "Pobjeda domaćina - 1" << endl;
            cout << "Neriješen rezultat - 0" << endl;
            cout << "Pobjeda gosta - 2" << endl;
            cout << endl;
            cout << "Koeficijenti:" << endl;
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
            cin >> kladjenje;
            krivi_unos(kladjenje);
            if (kladjenje == 1)
                koef_ukupno += koef1;
            else if (kladjenje == 0)
                koef_ukupno += koef0;
            else if (kladjenje == 2)
                koef_ukupno += koef2;
            utakmice.open("utakmice.txt", ios::app);
            utakmice << klub[0] << " vs " << klub[1] << "\t" << "Vas odabir: " << kladjenje << endl;
            utakmice.close();
            fstream odabrani_koef("odabrani_koef.bin", ios::binary | ios::out | ios::app);
            odabrani_koef.write((char *)&kladjenje, sizeof(kladjenje));
            odabrani_koef.close();
            rezultat_tekmi.open("rezultat_tekmi.txt", ios::app);
            rezultat_tekmi << klub[0] << " vs " << klub[1] << "\t" << endl;
            rezultat_tekmi.close();
        }
        else if (izbor_utk == 2)
        {
            cout << "Odabrali ste utakmicu: " << klub[2] << " vs " << klub[3];
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
            cin >> kladjenje;
            krivi_unos(kladjenje);
            if (kladjenje == 1)
                koef_ukupno += koef1;
            else if (kladjenje == 0)
                koef_ukupno += koef0;
            else if (kladjenje == 2)
                koef_ukupno += koef2;
            utakmice.open("utakmice.txt", ios::app);
            utakmice << klub[2] << " vs " << klub[3] << "\t" << "Vas odabir: " << kladjenje << endl;
            utakmice.close();
            fstream odabrani_koef("odabrani_koef.bin", ios::binary | ios::out | ios::app);
            odabrani_koef.write((char *)&kladjenje, sizeof(kladjenje));
            odabrani_koef.close();
            rezultat_tekmi.open("rezultat_tekmi.txt", ios::app);
            rezultat_tekmi << klub[2] << " vs " << klub[3] << "\t" << endl;
            rezultat_tekmi.close();
        }
        else if (izbor_utk == 3)
        {
            cout << "Odabrali ste utakmicu: " << klub[4] << " vs " << klub[5];
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
            cin >> kladjenje;
            krivi_unos(kladjenje);
            if (kladjenje == 1)
                koef_ukupno += koef1;
            else if (kladjenje == 0)
                koef_ukupno += koef0;
            else if (kladjenje == 2)
                koef_ukupno += koef2;
            utakmice.open("utakmice.txt", ios::app);
            utakmice << klub[4] << " vs " << klub[5] << "\t" << "Vas odabir: " << kladjenje << endl;
            utakmice.close();
            fstream odabrani_koef("odabrani_koef.bin", ios::binary | ios::out | ios::app);
            odabrani_koef.write((char *)&kladjenje, sizeof(kladjenje));
            odabrani_koef.close();
            rezultat_tekmi.open("rezultat_tekmi.txt", ios::app);
            rezultat_tekmi << klub[4] << " vs " << klub[5] << "\t" << endl;
            rezultat_tekmi.close();
        }
        else if (izbor_utk == 4)
        {
            cout << "Odabrali ste utakmicu: " << klub[6] << " vs " << klub[7];
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
            cin >> kladjenje;
            krivi_unos(kladjenje);
            if (kladjenje == 1)
                koef_ukupno += koef1;
            else if (kladjenje == 0)
                koef_ukupno += koef0;
            else if (kladjenje == 2)
                koef_ukupno += koef2;
            utakmice.open("utakmice.txt", ios::app);
            utakmice << klub[6] << " vs " << klub[7] << "\t" << "Vas odabir: " << kladjenje << endl;
            utakmice.close();
            fstream odabrani_koef("C:/Users/Gb-gama/Documents/GitHub/Projekt_2G/odabrani_koef.bin", ios::binary | ios::out | ios::app);
            odabrani_koef.write((char *)&kladjenje, sizeof(kladjenje));
            odabrani_koef.close();
            rezultat_tekmi.open("rezultat_tekmi.txt", ios::app);
            rezultat_tekmi << klub[6] << " vs " << klub[7] << "\t" << endl;
            rezultat_tekmi.close();
        }
        else if (izbor_utk == 5)
        {
            cout << "Odabrali ste utakmicu: " << klub[8] << " vs " << klub[9];
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
            cin >> kladjenje;
            krivi_unos(kladjenje);
            if (kladjenje == 1)
                koef_ukupno += koef1;
            else if (kladjenje == 0)
                koef_ukupno += koef0;
            else if (kladjenje == 2)
                koef_ukupno += koef2;
            utakmice.open("utakmice.txt", ios::app);
            utakmice << klub[8] << " vs " << klub[9] << "\t" << "Vas odabir: " << kladjenje << endl;
            utakmice.close();
            fstream odabrani_koef("odabrani_koef.bin", ios::binary | ios::out | ios::app);
            odabrani_koef.write((char *)&kladjenje, sizeof(kladjenje));
            odabrani_koef.close();
            rezultat_tekmi.open("rezultat_tekmi.txt", ios::app);
            rezultat_tekmi << klub[8] << " vs " << klub[9] << "\t" << endl;
            rezultat_tekmi.close();
        }
        if (izbor_utk == 6)
        {
            cout << "Odabrali ste utakmicu: " << klub[10] << " vs " << klub[11];
            cout << endl;
            cout << "Kladite se prema sljedecim oznakama:" << endl;
            cout << "Pobjeda domaćina - 1" << endl;
            cout << "Neriješen rezultat - 0" << endl;
            cout << "Pobjeda gosta - 2" << endl;
            cout << endl;
            cout << "Koeficijenti:" << endl;
            if (tim[10] < tim[11]) // random koef
            {
                koef1Manji(koef0, koef_1, koef__1, koef1, koef_2, koef__2, koef2);
            }
            else if (tim[11] < tim[10])
            {
                koef2Manji(koef0, koef_1, koef__1, koef1, koef_2, koef__2, koef2);
            }
            cout << "1\t" << klub[0] << ": " << setprecision(3) << koef1 << endl;
            cout << "0\tIzjednaceno/nerjeseno: " << setprecision(3) << koef0 << endl;
            cout << "2\t" << klub[1] << ": " << setprecision(3) << koef2 << endl;
            cin >> kladjenje;
            krivi_unos(kladjenje);
            if (kladjenje == 1)
                koef_ukupno += koef1;
            else if (kladjenje == 0)
                koef_ukupno += koef0;
            else if (kladjenje == 2)
                koef_ukupno += koef2;
            utakmice.open("utakmice.txt", ios::app);
            utakmice << klub[10] << " vs " << klub[11] << "\t" << "Vas odabir: " << kladjenje << endl;
            utakmice.close();
            fstream odabrani_koef("odabrani_koef.bin", ios::binary | ios::out | ios::app);
            odabrani_koef.write((char *)&kladjenje, sizeof(kladjenje));
            odabrani_koef.close();
            rezultat_tekmi.open("rezultat_tekmi.txt", ios::app);
            rezultat_tekmi << klub[10] << " vs " << klub[11] << "\t" << endl;
            rezultat_tekmi.close();
        }
        else if (izbor_utk == 7)
        {
            cout << "Odabrali ste utakmicu: " << klub[12] << " vs " << klub[13];
            cout << "\n";
            cout << "Kladite se prema sljedecim oznakama:\n";
            cout << "Pobjeda domaćina - 1\n";
            cout << "Neriješen rezultat - 0\n";
            cout << "Pobjeda gosta - 2\n";
            cout << "\n";
            cout << "Koeficijenti:\n";
            if (tim[12] < tim[13]) // random koef
            {
                koef1Manji(koef0, koef_1, koef__1, koef1, koef_2, koef__2, koef2);
            }
            else if (tim[13] < tim[12])
            {
                koef2Manji(koef0, koef_1, koef__1, koef1, koef_2, koef__2, koef2);
            }
            cout << "1\t" << klub[12] << ": " << setprecision(3) << koef1 << endl;
            cout << "0\tIzjednaceno/nerjeseno: " << setprecision(3) << koef0 << endl;
            cout << "2\t" << klub[13] << ": " << setprecision(3) << koef2 << endl;
            cin >> kladjenje;
            krivi_unos(kladjenje);
            if (kladjenje == 1)
                koef_ukupno += koef1;
            else if (kladjenje == 0)
                koef_ukupno += koef0;
            else if (kladjenje == 2)
                koef_ukupno += koef2;
            utakmice.open("utakmice.txt", ios::app);
            utakmice << klub[12] << " vs " << klub[13] << "\t" << "Vas odabir: " << kladjenje << endl;
            utakmice.close();
            fstream odabrani_koef("odabrani_koef.bin", ios::binary | ios::out | ios::app);
            odabrani_koef.write((char *)&kladjenje, sizeof(kladjenje));
            odabrani_koef.close();
            rezultat_tekmi.open("rezultat_tekmi.txt", ios::app);
            rezultat_tekmi << klub[12] << " vs " << klub[13] << "\t" << endl;
            rezultat_tekmi.close();
        }
        else if (izbor_utk == 8)
        {
            cout << "Odabrali ste utakmicu: " << klub[14] << " vs " << klub[15];
            cout << "\n";
            cout << "Kladite se prema sljedecim oznakama:\n";
            cout << "Pobjeda domaćina - 1\n";
            cout << "Neriješen rezultat - 0\n";
            cout << "Pobjeda gosta - 2\n";
            cout << "\n";
            cout << "Koeficijenti:\n";
            if (tim[14] < tim[15]) // random koef
            {
                koef1Manji(koef0, koef_1, koef__1, koef1, koef_2, koef__2, koef2);
            }
            else if (tim[15] < tim[14])
            {
                koef2Manji(koef0, koef_1, koef__1, koef1, koef_2, koef__2, koef2);
            }
            cout << "1\t" << klub[14] << ": " << setprecision(3) << koef1 << endl;
            cout << "0\tIzjednaceno/nerjeseno: " << setprecision(3) << koef0 << endl;
            cout << "2\t" << klub[15] << ": " << setprecision(3) << koef2 << endl;
            cin >> kladjenje;
            krivi_unos(kladjenje);
            if (kladjenje == 1)
                koef_ukupno += koef1;
            else if (kladjenje == 0)
                koef_ukupno += koef0;
            else if (kladjenje == 2)
                koef_ukupno += koef2;
            utakmice.open("utakmice.txt", ios::app);
            utakmice << klub[14] << " vs " << klub[15] << "\t" << "Vas odabir: " << kladjenje << endl;
            utakmice.close();
            fstream odabrani_koef("odabrani_koef.bin", ios::binary | ios::out | ios::app);
            odabrani_koef.write((char *)&kladjenje, sizeof(kladjenje));
            odabrani_koef.close();
            rezultat_tekmi.open("rezultat_tekmi.txt", ios::app);
            rezultat_tekmi << klub[14] << " vs " << klub[15] << "\t" << endl;
            rezultat_tekmi.close();
        }
        else if (izbor_utk == 9)
        {
            cout << "Odabrali ste utakmicu: " << klub[16] << " vs " << klub[17];
            cout << "\n";
            cout << "Kladite se prema sljedecim oznakama:\n";
            cout << "Pobjeda domaćina - 1\n";
            cout << "Neriješen rezultat - 0\n";
            cout << "Pobjeda gosta - 2\n";
            cout << "\n";
            cout << "Koeficijenti:\n";
            if (tim[16] < tim[17]) // random koef
            {
                koef1Manji(koef0, koef_1, koef__1, koef1, koef_2, koef__2, koef2);
            }
            else if (tim[17] < tim[16])
            {
                koef2Manji(koef0, koef_1, koef__1, koef1, koef_2, koef__2, koef2);
            }
            cout << "1\t" << klub[16] << ": " << setprecision(3) << koef1 << endl;
            cout << "0\tIzjednaceno/nerjeseno: " << setprecision(3) << koef0 << endl;
            cout << "2\t" << klub[17] << ": " << setprecision(3) << koef2 << endl;
            cin >> kladjenje;
            krivi_unos(kladjenje);
            if (kladjenje == 1)
                koef_ukupno += koef1;
            else if (kladjenje == 0)
                koef_ukupno += koef0;
            else if (kladjenje == 2)
                koef_ukupno += koef2;
            utakmice.open("utakmice.txt", ios::app);
            utakmice << klub[16] << " vs " << klub[17] << "\t" << "Vas odabir: " << kladjenje << endl;
            utakmice.close();
            fstream odabrani_koef("C:/Users/Gb-gama/Documents/GitHub/Projekt_2G/odabrani_koef.bin", ios::binary | ios::out | ios::app);
            odabrani_koef.write((char *)&kladjenje, sizeof(kladjenje));
            odabrani_koef.close();
            rezultat_tekmi.open("rezultat_tekmi.txt", ios::app);
            rezultat_tekmi << klub[16] << " vs " << klub[17] << "\t" << endl;
            rezultat_tekmi.close();
        }
        else if (izbor_utk == 10)
        {
            cout << "Odabrali ste utakmicu: " << klub[18] << " vs " << klub[19];
            cout << "\n";
            cout << "Kladite se prema sljedecim oznakama:\n";
            cout << "Pobjeda domaćina - 1\n";
            cout << "Neriješen rezultat - 0\n";
            cout << "Pobjeda gosta - 2\n";
            cout << "\n";
            cout << "Koeficijenti:\n";
            if (tim[18] < tim[19]) // random koef
            {
                koef1Manji(koef0, koef_1, koef__1, koef1, koef_2, koef__2, koef2);
            }
            else if (tim[19] < tim[18])
            {
                koef2Manji(koef0, koef_1, koef__1, koef1, koef_2, koef__2, koef2);
            }
            cout << "1\t" << klub[18] << ": " << setprecision(3) << koef1 << endl;
            cout << "0\tIzjednaceno/nerjeseno: " << setprecision(3) << koef0 << endl;
            cout << "2\t" << klub[19] << ": " << setprecision(3) << koef2 << endl;
            cin >> kladjenje;
            krivi_unos(kladjenje);
            if (kladjenje == 1)
                koef_ukupno += koef1;
            else if (kladjenje == 0)
                koef_ukupno += koef0;
            else if (kladjenje == 2)
                koef_ukupno += koef2;
            utakmice.open("utakmice.txt", ios::app);
            utakmice << klub[18] << " vs " << klub[19] << "\t" << "Vas odabir: " << kladjenje << endl;
            utakmice.close();
            fstream odabrani_koef("odabrani_koef.bin", ios::binary | ios::out | ios::app);
            odabrani_koef.write((char *)&kladjenje, sizeof(kladjenje));
            odabrani_koef.close();
            rezultat_tekmi.open("rezultat_tekmi.txt", ios::app);
            rezultat_tekmi << klub[18] << " vs " << klub[19] << "\t" << endl;
            rezultat_tekmi.close();
        }
        cout << "Zelite li se nastaviti kladiti? Da/Ne" << endl;
        cin >> nastavakKladenja;
        int kolo_ili_liga;
        if (nastavakKladenja == "Da" || nastavakKladenja == "da")
        {
            cout << "Ako se zelite nastaviti kladiti na klubove u ovom kolu upisite 1, a ako se zelite nastaviti kladiti na klubove u drugim ligama upisite 2." << endl;
            cin >> kolo_ili_liga;
            if (kolo_ili_liga == 1)
                goto ovo_koloLL;
            else if (kolo_ili_liga == 2)
                goto pocetak;
        }
        else
            cout << endl;
    }
    else if(izbor == 4)
    {
        cout << "\n";
        cout << "Trenutna tablica:\n"; // printanje live tablice
        cout << "Bundesliga 2023/24\n";
        string momcadi[18] = {
            "Bayer 04 Leverkusen", "VfB Stuttgart      ", "FC Bayern Munchen  ",
            "RB Leipzig         ", "Borussia Dortmund  ", "Eintracht Frankfurt",
            "TSG Hoffenheim     ", "1. FC Heidenheim   ", "SV Werder Bremen   ",
            "SC Freiburg        ", "FC Augsburg        ", "VfL Wolfsburg      ",
            "1. FSV Mainz 05    ", "Borussia M'gladbach", "1. FC Union Berlin ",
            "VfL Bochum 1848    ", "1. FC Koln         ", "Darmstadt 98       "};
        int bodovi[18] = {90, 73, 72, 65, 63, 47, 46, 42, 42, 42, 39, 37, 35, 34, 33, 33, 27, 17};
        for (int i = 0; i < 18; i++)
            cout << i + 1 << ".\t" << momcadi[i] << "\t" << bodovi[i] << endl;
        cout << endl; // printanje 10 random utakmica
        cout << "Utakmice ovog kola:" << endl;
        char timovi[19][30] = {"Bayer 04 Leverkusen", "VfB Stuttgart", "FC Bayern Munchen", "RB Leipzig", "Borussia Dortmund", "Eintracht Frankfurt", "TSG Hoffenheim", "1. FC Heidenheim", "SV Werder Bremen", "SC Freiburg", "FC Augsburg", "VfL Wolfsburg", "1. FSV Mainz 05", "Borussia M'gladbach", "1. FC Union Berlin", "VfL Bochum 1848", "1. FC Koln", "Darmstadt 98", ""};
        char klub[19][30];
        srand(time(NULL));
        int tim1, tim2, brojac = 0, tim[18];
        for (int i = 0; i < 9; i++)
        {
            cout << i + 1 << ". ";
            tim1 = rand() % 19;
            for (int i = 0; i < 200; i++)
                if (strcmp(timovi[tim1], "") == 0)
                    tim1 = rand() % 19;
            strcpy(klub[brojac], timovi[tim1]);
            tim[brojac] = tim1;
            brojac++;
            cout << timovi[tim1];
            strcpy(timovi[tim1], timovi[18]);
            cout << "\tvs\t";
            tim2 = rand() % 19;
            for (int i = 0; i < 200; i++)
                if (strcmp(timovi[tim2], "") == 0)
                    tim2 = rand() % 19;
            strcpy(klub[brojac], timovi[tim2]);
            tim[brojac] = tim2;
            brojac++;
            cout << timovi[tim2];
            strcpy(timovi[tim2], timovi[18]);
            cout << "\n";
        }
    ovo_koloBL:
        cout << "Molimo unesite redni broj utakmice na koju se želite kladiti." << endl;
        cin >> izbor_utk;
        if (izbor_utk == 1)
        {
            cout << "Odabrali ste utakmicu: " << klub[0] << " vs " << klub[1];
            cout << endl;
            cout << "Kladite se prema sljedecim oznakama:" << endl;
            cout << "Pobjeda domaćina - 1" << endl;
            cout << "Neriješen rezultat - 0" << endl;
            cout << "Pobjeda gosta - 2" << endl;
            cout << endl;
            cout << "Koeficijenti:" << endl;
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
            cin >> kladjenje;
            krivi_unos(kladjenje);
            if (kladjenje == 1)
                koef_ukupno += koef1;
            else if (kladjenje == 0)
                koef_ukupno += koef0;
            else if (kladjenje == 2)
                koef_ukupno += koef2;
            utakmice.open("utakmice.txt", ios::app);
            utakmice << klub[0] << " vs " << klub[1] << "\t" << "Vas odabir: " << kladjenje << endl;
            utakmice.close();
            fstream odabrani_koef("odabrani_koef.bin", ios::binary | ios::out | ios::app);
            odabrani_koef.write((char *)&kladjenje, sizeof(kladjenje));
            odabrani_koef.close();
            rezultat_tekmi.open("rezultat_tekmi.txt", ios::app);
            rezultat_tekmi << klub[0] << " vs " << klub[1] << "\t" << endl;
            rezultat_tekmi.close();
        }
        else if (izbor_utk == 2)
        {
            cout << "Odabrali ste utakmicu: " << klub[2] << " vs " << klub[3];
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
            cin >> kladjenje;
            krivi_unos(kladjenje);
            if (kladjenje == 1)
                koef_ukupno += koef1;
            else if (kladjenje == 0)
                koef_ukupno += koef0;
            else if (kladjenje == 2)
                koef_ukupno += koef2;
            utakmice.open("utakmice.txt", ios::app);
            utakmice << klub[2] << " vs " << klub[3] << "\t" << "Vas odabir: " << kladjenje << endl;
            utakmice.close();
            fstream odabrani_koef("odabrani_koef.bin", ios::binary | ios::out | ios::app);
            odabrani_koef.write((char *)&kladjenje, sizeof(kladjenje));
            odabrani_koef.close();
            rezultat_tekmi.open("rezultat_tekmi.txt", ios::app);
            rezultat_tekmi << klub[2] << " vs " << klub[3] << "\t" << endl;
            rezultat_tekmi.close();
        }
        else if (izbor_utk == 3)
        {
            cout << "Odabrali ste utakmicu: " << klub[4] << " vs " << klub[5];
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
            cin >> kladjenje;
            krivi_unos(kladjenje);
            if (kladjenje == 1)
                koef_ukupno += koef1;
            else if (kladjenje == 0)
                koef_ukupno += koef0;
            else if (kladjenje == 2)
                koef_ukupno += koef2;
            utakmice.open("utakmice.txt", ios::app);
            utakmice << klub[4] << " vs " << klub[5] << "\t" << "Vas odabir: " << kladjenje << endl;
            utakmice.close();
            fstream odabrani_koef("odabrani_koef.bin", ios::binary | ios::out | ios::app);
            odabrani_koef.write((char *)&kladjenje, sizeof(kladjenje));
            odabrani_koef.close();
            rezultat_tekmi.open("rezultat_tekmi.txt", ios::app);
            rezultat_tekmi << klub[4] << " vs " << klub[5] << "\t" << endl;
            rezultat_tekmi.close();
        }
        else if (izbor_utk == 4)
        {
            cout << "Odabrali ste utakmicu: " << klub[6] << " vs " << klub[7];
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
            cin >> kladjenje;
            krivi_unos(kladjenje);
            if (kladjenje == 1)
                koef_ukupno += koef1;
            else if (kladjenje == 0)
                koef_ukupno += koef0;
            else if (kladjenje == 2)
                koef_ukupno += koef2;
            utakmice.open("utakmice.txt", ios::app);
            utakmice << klub[6] << " vs " << klub[7] << "\t" << "Vas odabir: " << kladjenje << endl;
            utakmice.close();
            fstream odabrani_koef("C:/Users/Gb-gama/Documents/GitHub/Projekt_2G/odabrani_koef.bin", ios::binary | ios::out | ios::app);
            odabrani_koef.write((char *)&kladjenje, sizeof(kladjenje));
            odabrani_koef.close();
            rezultat_tekmi.open("rezultat_tekmi.txt", ios::app);
            rezultat_tekmi << klub[6] << " vs " << klub[7] << "\t" << endl;
            rezultat_tekmi.close();
        }
        else if (izbor_utk == 5)
        {
            cout << "Odabrali ste utakmicu: " << klub[8] << " vs " << klub[9];
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
            cin >> kladjenje;
            krivi_unos(kladjenje);
            if (kladjenje == 1)
                koef_ukupno += koef1;
            else if (kladjenje == 0)
                koef_ukupno += koef0;
            else if (kladjenje == 2)
                koef_ukupno += koef2;
            utakmice.open("utakmice.txt", ios::app);
            utakmice << klub[8] << " vs " << klub[9] << "\t" << "Vas odabir: " << kladjenje << endl;
            utakmice.close();
            fstream odabrani_koef("odabrani_koef.bin", ios::binary | ios::out | ios::app);
            odabrani_koef.write((char *)&kladjenje, sizeof(kladjenje));
            odabrani_koef.close();
            rezultat_tekmi.open("rezultat_tekmi.txt", ios::app);
            rezultat_tekmi << klub[8] << " vs " << klub[9] << "\t" << endl;
            rezultat_tekmi.close();
        }
        if (izbor_utk == 6)
        {
            cout << "Odabrali ste utakmicu: " << klub[10] << " vs " << klub[11];
            cout << endl;
            cout << "Kladite se prema sljedecim oznakama:" << endl;
            cout << "Pobjeda domaćina - 1" << endl;
            cout << "Neriješen rezultat - 0" << endl;
            cout << "Pobjeda gosta - 2" << endl;
            cout << endl;
            cout << "Koeficijenti:" << endl;
            if (tim[10] < tim[11]) // random koef
            {
                koef1Manji(koef0, koef_1, koef__1, koef1, koef_2, koef__2, koef2);
            }
            else if (tim[11] < tim[10])
            {
                koef2Manji(koef0, koef_1, koef__1, koef1, koef_2, koef__2, koef2);
            }
            cout << "1\t" << klub[0] << ": " << setprecision(3) << koef1 << endl;
            cout << "0\tIzjednaceno/nerjeseno: " << setprecision(3) << koef0 << endl;
            cout << "2\t" << klub[1] << ": " << setprecision(3) << koef2 << endl;
            cin >> kladjenje;
            krivi_unos(kladjenje);
            if (kladjenje == 1)
                koef_ukupno += koef1;
            else if (kladjenje == 0)
                koef_ukupno += koef0;
            else if (kladjenje == 2)
                koef_ukupno += koef2;
            utakmice.open("utakmice.txt", ios::app);
            utakmice << klub[10] << " vs " << klub[11] << "\t" << "Vas odabir: " << kladjenje << endl;
            utakmice.close();
            fstream odabrani_koef("odabrani_koef.bin", ios::binary | ios::out | ios::app);
            odabrani_koef.write((char *)&kladjenje, sizeof(kladjenje));
            odabrani_koef.close();
            rezultat_tekmi.open("rezultat_tekmi.txt", ios::app);
            rezultat_tekmi << klub[10] << " vs " << klub[11] << "\t" << endl;
            rezultat_tekmi.close();
        }
        else if (izbor_utk == 7)
        {
            cout << "Odabrali ste utakmicu: " << klub[12] << " vs " << klub[13];
            cout << "\n";
            cout << "Kladite se prema sljedecim oznakama:\n";
            cout << "Pobjeda domaćina - 1\n";
            cout << "Neriješen rezultat - 0\n";
            cout << "Pobjeda gosta - 2\n";
            cout << "\n";
            cout << "Koeficijenti:\n";
            if (tim[12] < tim[13]) // random koef
            {
                koef1Manji(koef0, koef_1, koef__1, koef1, koef_2, koef__2, koef2);
            }
            else if (tim[13] < tim[12])
            {
                koef2Manji(koef0, koef_1, koef__1, koef1, koef_2, koef__2, koef2);
            }
            cout << "1\t" << klub[12] << ": " << setprecision(3) << koef1 << endl;
            cout << "0\tIzjednaceno/nerjeseno: " << setprecision(3) << koef0 << endl;
            cout << "2\t" << klub[13] << ": " << setprecision(3) << koef2 << endl;
            cin >> kladjenje;
            krivi_unos(kladjenje);
            if (kladjenje == 1)
                koef_ukupno += koef1;
            else if (kladjenje == 0)
                koef_ukupno += koef0;
            else if (kladjenje == 2)
                koef_ukupno += koef2;
            utakmice.open("utakmice.txt", ios::app);
            utakmice << klub[12] << " vs " << klub[13] << "\t" << "Vas odabir: " << kladjenje << endl;
            utakmice.close();
            fstream odabrani_koef("odabrani_koef.bin", ios::binary | ios::out | ios::app);
            odabrani_koef.write((char *)&kladjenje, sizeof(kladjenje));
            odabrani_koef.close();
            rezultat_tekmi.open("rezultat_tekmi.txt", ios::app);
            rezultat_tekmi << klub[12] << " vs " << klub[13] << "\t" << endl;
            rezultat_tekmi.close();
        }
        else if (izbor_utk == 8)
        {
            cout << "Odabrali ste utakmicu: " << klub[14] << " vs " << klub[15];
            cout << "\n";
            cout << "Kladite se prema sljedecim oznakama:\n";
            cout << "Pobjeda domaćina - 1\n";
            cout << "Neriješen rezultat - 0\n";
            cout << "Pobjeda gosta - 2\n";
            cout << "\n";
            cout << "Koeficijenti:\n";
            if (tim[14] < tim[15]) // random koef
            {
                koef1Manji(koef0, koef_1, koef__1, koef1, koef_2, koef__2, koef2);
            }
            else if (tim[15] < tim[14])
            {
                koef2Manji(koef0, koef_1, koef__1, koef1, koef_2, koef__2, koef2);
            }
            cout << "1\t" << klub[14] << ": " << setprecision(3) << koef1 << endl;
            cout << "0\tIzjednaceno/nerjeseno: " << setprecision(3) << koef0 << endl;
            cout << "2\t" << klub[15] << ": " << setprecision(3) << koef2 << endl;
            cin >> kladjenje;
            krivi_unos(kladjenje);
            if (kladjenje == 1)
                koef_ukupno += koef1;
            else if (kladjenje == 0)
                koef_ukupno += koef0;
            else if (kladjenje == 2)
                koef_ukupno += koef2;
            utakmice.open("utakmice.txt", ios::app);
            utakmice << klub[14] << " vs " << klub[15] << "\t" << "Vas odabir: " << kladjenje << endl;
            utakmice.close();
            fstream odabrani_koef("odabrani_koef.bin", ios::binary | ios::out | ios::app);
            odabrani_koef.write((char *)&kladjenje, sizeof(kladjenje));
            odabrani_koef.close();
            rezultat_tekmi.open("rezultat_tekmi.txt", ios::app);
            rezultat_tekmi << klub[14] << " vs " << klub[15] << "\t" << endl;
            rezultat_tekmi.close();
        }
        else if (izbor_utk == 9)
        {
            cout << "Odabrali ste utakmicu: " << klub[16] << " vs " << klub[17];
            cout << "\n";
            cout << "Kladite se prema sljedecim oznakama:\n";
            cout << "Pobjeda domaćina - 1\n";
            cout << "Neriješen rezultat - 0\n";
            cout << "Pobjeda gosta - 2\n";
            cout << "\n";
            cout << "Koeficijenti:\n";
            if (tim[16] < tim[17]) // random koef
            {
                koef1Manji(koef0, koef_1, koef__1, koef1, koef_2, koef__2, koef2);
            }
            else if (tim[17] < tim[16])
            {
                koef2Manji(koef0, koef_1, koef__1, koef1, koef_2, koef__2, koef2);
            }
            cout << "1\t" << klub[16] << ": " << setprecision(3) << koef1 << endl;
            cout << "0\tIzjednaceno/nerjeseno: " << setprecision(3) << koef0 << endl;
            cout << "2\t" << klub[17] << ": " << setprecision(3) << koef2 << endl;
            cin >> kladjenje;
            krivi_unos(kladjenje);
            if (kladjenje == 1)
                koef_ukupno += koef1;
            else if (kladjenje == 0)
                koef_ukupno += koef0;
            else if (kladjenje == 2)
                koef_ukupno += koef2;
            utakmice.open("utakmice.txt", ios::app);
            utakmice << klub[16] << " vs " << klub[17] << "\t" << "Vas odabir: " << kladjenje << endl;
            utakmice.close();
            fstream odabrani_koef("C:/Users/Gb-gama/Documents/GitHub/Projekt_2G/odabrani_koef.bin", ios::binary | ios::out | ios::app);
            odabrani_koef.write((char *)&kladjenje, sizeof(kladjenje));
            odabrani_koef.close();
            rezultat_tekmi.open("rezultat_tekmi.txt", ios::app);
            rezultat_tekmi << klub[16] << " vs " << klub[17] << "\t" << endl;
            rezultat_tekmi.close();
        }
        cout << "Zelite li se nastaviti kladiti? Da/Ne" << endl;
        cin >> nastavakKladenja;
        int kolo_ili_liga;
        if (nastavakKladenja == "Da" || nastavakKladenja == "da")
        {
            cout << "Ako se zelite nastaviti kladiti na klubove u ovom kolu upisite 1, a ako se zelite nastaviti kladiti na klubove u drugim ligama upisite 2." << endl;
            cin >> kolo_ili_liga;
            if (kolo_ili_liga == 1)
                goto ovo_koloBL;
            else if (kolo_ili_liga == 2)
                goto pocetak;
        }
        else
            cout << endl;
    }
    
    int gol1, gol2;
    double uplata, dobitak, profit;
    bool prolaznost_para = true, prolaznost_listica = true;
    cout << "Ovo je vas listic:" << endl;
    utakmice.open("utakmice.txt");
    while (getline(utakmice, ispis_tekmi))
    {
        cout << ispis_tekmi << "\t" << endl;
    }
    utakmice.close();
    cout << "Koliko uplacujete? ";
    cin >> uplata;
    cout << endl
         << "Ovo je listic poslije odigranih utakmica:" << endl;
    rezultat_tekmi.open("rezultat_tekmi.txt");
    fstream odabrani_koef1("odabrani_koef.bin", ios::binary | ios::in);
    while (getline(rezultat_tekmi, ispis_rezultata) && odabrani_koef1.read((char *)&kladjenje, sizeof(kladjenje)))
    {
        golovi(gol1, gol2);
        cout << ispis_rezultata << "\t" << gol1 << ":" << gol2 << endl;
        prolaznost(kladjenje, gol1, gol2, prolaznost_para);
        if (prolaznost_para == false)
            prolaznost_listica = false;
    }
    rezultat_tekmi.close();
    odabrani_koef1.close();
    if (prolaznost_listica == true)
    {
        dobitak = uplata * koef_ukupno;
        profit = dobitak - uplata;
        cout << "Uplata: " << uplata << "€" << endl
             << "Dobitak: " << dobitak << "€" << endl
             << "Profit: " << profit << "€" << endl;
    }
    else
    {
        cout << "Nazalost, listic Vam nije prosao." << endl;
    }
    cout << "Hvala na kladenju!" << endl;
    ofstream odabrani_koef("odabrani_koef.bin", ios::binary | ios::trunc);
    odabrani_koef.close();
    ofstream utakmice1("utakmice.txt", ios::trunc);
    utakmice1.close();
    ofstream rezultat_tekmi1("rezultat_tekmi.txt", ios::trunc);
    rezultat_tekmi1.close();
    return 0;
}