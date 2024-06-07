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
    srand(time(NULL));
    gol1 = rand() % 4;
    gol2 = rand() % 4;
}
template <typename T>
void prolaznost(int kladjenje, int gol1, int gol2, T& prolaznost_para)
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

    int izbor, tablica[10][3];
    bool nastaviKladenje = true;
    string nastavakKladenja;
    cout << "Kladite se odgovorno!  18+" << endl;
    cout << "Cijena uplate je 50c."<<endl;
    pocetak:
    cout << "Izaberite ligu pomocu broja." << endl;
    cout << "1. HNL"<<endl;
    cout << "2. Premier League" << endl;
    cout << "3. La Liga" << endl;
    cout << "4. Bundesliga" << endl;
    cout << "5. Serie A" << endl;
    cout << "6. Ligue 1" << endl;
    cin >> izbor;
    fstream utakmice, rezultat_tekmi;
    string ispis_tekmi, ispis_rezultata;
    int kladjenje;
    double koef_ukupno;

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
        cout << "Utakmice ovog kola:"<<endl;
        #define br_timova 11
        char timovi[br_timova][21] = {"GNK Dinamo Zagreb", "HNK Rijeka", "HNK Hajduk Split", "NK Osijek", "NK Lokomotiva Zagreb", "NK Varazdin", "HNK Gorica", "NK Istra 1961", "NK Slaven Belupo", "NK Rudes", ""};
        char klub[br_timova][21];
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
        int izbor_utk, rand_rez;
        double koef1, koef0, koef2, koef_1, koef__1, koef_2, koef__2;
        cout << endl;
        ovo_kolo:
        cout << "Molimo unesite redni broj utakmice na koju se želite kladiti."<<endl;
        cin >> izbor_utk;
        if (izbor_utk == 1)
        {
            utakmice.open("utakmice.txt", ios::app);
            utakmice <<klub[0]<<" vs "<<klub[1]<< endl;
            utakmice.close();
            cout << "Odabrali ste utakmicu: " << klub[0] << " vs " << klub[1];
            cout << endl;
            cout << "Kladite se prema sljedecim oznakama:"<<endl;
            cout << "Pobjeda domaćina - 1"<<endl;
            cout << "Neriješen rezultat - 0"<<endl;
            cout << "Pobjeda gosta - 2"<<endl;
            cout << endl;
            cout << "Koeficijenti:"<<endl;
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
            //kladenje(kladjenje, gol1, gol2, uplata, koef0, koef1, koef2, dobitak, profit);
        }
        else if (izbor_utk == 2)
        {
            utakmice.open("utakmice.txt", ios::app);
            utakmice << klub[2] << " vs " << klub[3] << endl;
            utakmice.close();
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
            //kladenje(kladjenje, gol1, gol2, uplata, koef0, koef1, koef2, dobitak, profit);
        }
        else if (izbor_utk == 3)
        {
            utakmice.open("utakmice.txt", ios::app);
            utakmice << klub[4] << " vs " << klub[5] << endl;
            utakmice.close();
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
            //kladenje(kladjenje, gol1, gol2, uplata, koef0, koef1, koef2, dobitak, profit);
        }
        else if (izbor_utk == 4)
        {
            utakmice.open("utakmice.txt", ios::app);
            utakmice << klub[6] << " vs " << klub[7] << endl;
            utakmice.close();
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
            rezultat_tekmi << klub[6] << " vs " << klub[7] << "\t" <<endl;
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
            if(kladjenje==1)
                koef_ukupno += koef1;
            else if(kladjenje==0)
                koef_ukupno += koef0;
            else if(kladjenje==2)
                koef_ukupno += koef2;
            utakmice.open("utakmice.txt", ios::app);
            utakmice << klub[8] << " vs " << klub[9] << "\t" << "Vas odabir: " << kladjenje << endl;
            utakmice.close();
            fstream odabrani_koef("odabrani_koef.bin", ios::binary | ios::out | ios::app);
            odabrani_koef.write((char*)&kladjenje, sizeof(kladjenje));
            odabrani_koef.close();
            rezultat_tekmi.open("rezultat_tekmi.txt", ios::app);
            rezultat_tekmi << klub[8] << " vs " << klub[9] << "\t" << endl;
            rezultat_tekmi.close();
        }
        cout << "Zelite li se nastaviti kladiti? Da/Ne" << endl;
        cin >> nastavakKladenja;
        int kolo_ili_liga;
        if(nastavakKladenja == "Da" || nastavakKladenja == "da")
        {
            cout << "Ako se zelite nastaviti kladiti na klubove u ovom kolu upisite 1, a ako se zelite nastaviti kladiti na klubove u drugim ligama upisite 2." << endl;
            cin >> kolo_ili_liga;
            if(kolo_ili_liga==1)
                goto ovo_kolo;
            else if(kolo_ili_liga==2)
                goto pocetak;
        }
        else
            cout << endl;
    }

    int gol1, gol2;
    double uplata, dobitak, profit;
    bool prolaznost_para = true, prolaznost_listica=true;
    cout << "Ovo je vas listic:" << endl;
    utakmice.open("utakmice.txt");
    while(getline(utakmice, ispis_tekmi))
    {
        cout << ispis_tekmi <<"\t"<< endl;
    }
    utakmice.close();
    cout << "Koliko uplacujete? ";
    cin >> uplata;
    cout<<endl<<"Ovo je listic poslije odigranih utakmica:"<<endl;
    rezultat_tekmi.open("rezultat_tekmi.txt");
    fstream odabrani_koef1("odabrani_koef.bin", ios::binary | ios::in);
    while(getline(rezultat_tekmi, ispis_rezultata) && odabrani_koef1.read((char *)&kladjenje, sizeof(kladjenje)))
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
        cout << "Uplata: " << uplata << "€" << endl<< "Dobitak: " << dobitak << "€" << endl << "Profit: " << profit << "€" << endl;
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