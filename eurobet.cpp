#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
using namespace std;
int main()
{
    cout << "███████   ██   ██   ██████     █████    ██████    ███████   ████████" << endl;
    cout << "██        ██   ██   ██   ██   ██   ██   ██   ██   ██           ██" << endl;
    cout << "███████   ██   ██   ███████   ██   ██   ██████    ███████      ██" << endl;
    cout << "██        ██   ██   ██  ██    ██   ██   ██   ██   ██           ██" << endl;
    cout << "███████    █████    ██   ██    █████    ██████    ███████      ██" << endl;
        
    int uplata = 0, koef, izbor, isplata tablica[10][3];
    cout<<"Kladite se odgovorno!  18+\n";
    cout<<"Cijena uplate je 50c.\n";
    cout<<"Izaberite ligu pomocu broja.\n";
    cout<<"1. HNL\n";
    cout<<"2. Premier League\n";
    cout<<"3. La Liga\n";
    cout<<"4. Bundesliga\n";
    cout<<"5. Serie A\n";
    cout<<"6. Ligue 1\n";
    cin>>izbor;
    if (izbor == 1)
    {
        cout<<"\n";
        cout<<"Trenutna tablica:\n"; // printanje live tablice
        cout<<"HNL 2022/23\n";
        char momcadi[10][30] = {"GNK Dinamo Zagreb   ", "HNK Hajduk Split    ",
                                "NK Osijek           ", "HNK Rijeka          ",
                                "NK Istra 1961       ", "NK Varazdin         ",
                                "NK Lokomotiva Zagreb", "NK Slaven Belupo    ",
                                "HNK Gorica          ", "HNK Sibenik         "};
        int bodovi[10] = {81, 71, 50, 49, 46, 46, 43, 43, 32, 27};
        for (int i = 0; i < 10; i++)
            cout<<"%d.\t%s\t%d\n"<<i + 1<<momcadi[i]<< bodovi[i];
        cout<<"\n"; // printanje 5 random utakmica
        cout<<"Utakmice ovog kola:\n";
#define br_timova 11
        char timovi[br_timova][21] = {"GNK Dinamo Zagreb",
                                        "HNK Hajduk Split",
                                        "NK Osijek",
                                        "HNK Rijeka",
                                        "NK Istra 1961",
                                        "NK Varazdin",
                                        "NK Lokomotiva Zagreb",
                                        "NK Slaven Belupo",
                                        "HNK Gorica",
                                        "HNK Sibenik",
                                        ""};
            char klub[br_timova][21];
            srand(time(NULL));
            int tim1, tim2, brojac = 0, tim[10];
            for (int i = 0; i < 5; i++)
            {
                cout<<("%d.\t", i + 1);
                tim1 = rand() % br_timova;
                for (int i = 0; i < 200; i++)
                    if (strcmp(timovi[tim1], "") == 0)
                        tim1 = rand() % br_timova;
                strcpy(klub[brojac], timovi[tim1]);
                tim[brojac] = tim1;
                brojac++;
                cout<<("%s\t", timovi[tim1]);
                strcpy(timovi[tim1], timovi[10]);
                cout<<("vs\t");
                tim2 = rand() % br_timova;
                for (int i = 0; i < 200; i++)
                    if (strcmp(timovi[tim2], "") == 0)
                        tim2 = rand() % br_timova;
                strcpy(klub[brojac], timovi[tim2]);
                tim[brojac] = tim2;
                brojac++;
                cout<<("%s", timovi[tim2]);
                strcpy(timovi[tim2], timovi[10]);
                cout<<("\n");
            }
            int izbor_utk, kladjenje, rand_rez, gol1, gol2;
            double koef1, koef0, koef2, koef_1, koef__1, koef_2, koef__2, uplata,
                dobitak, profit;
                cout<<("\n");
                cout<<("Molimo unesite redni broj utakmice na koju se želite kladiti.\n");
                cin>>"%d">> &izbor_utk;
                if (izbor_utk == 1)
                {
                    cout<<"Odabrali ste utakmicu:\n%s vs %s\n"<< klub[0]<< klub[1];
                    cout<<"\n";
                    cout<<"Kladite se prema sljedecim oznakama:\n";
                    cout<<"Pobjeda domaćina - 1\n";
                    cout<<"Neriješen rezultat - 0\n";
                    cout<<"Pobjeda gosta - 2\n";
                    cout<<"\n";
                    cout<<"Koeficijenti:\n";
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
                    cout<<("1\t%s: %.2f\n", klub[0], koef1);
                    cout<<("0\tIzjednaceno/nerjeseno: %.2f\n", koef0);
                    cout<<("2\t%s: %.2f\n\n", klub[1], koef2);
                    cout<<("Odaberite na sto se kladite pomocu prethodnih oznaka.\n");
                    cin>>("%d", &kladjenje);
                    if (kladjenje == 1)
                    {
                        cout<<("Koliko uplacujete?\n");
                        cin>>("%lf", &uplata);
                        srand(time(NULL));
                        gol1 = rand() % 4;
                        gol2 = rand() % 4;
                        cout<<("Rezultat: %d:%d\n", gol1, gol2);
                        if (gol1 > gol2)
                        {
                            dobitak = uplata * koef1;
                            profit = (uplata * koef1) - uplata;
                            cout<<("Ishod utakmice: Pobjeda %s\n", klub[0]);
                            cout<<("Pogodili ste ishod utakmice.\n");
                            cout<<("Vas dobitak: %.2f\n", dobitak);
                            cout<<("Vas profit: %.2f\n", profit);
                        }
                        else if (gol1 == gol2 || gol1 < gol2)
                            cout<<("Nazalost niste pogodili ishod utakmice.\n");
                    }
                    else if (kladjenje == 0)
                    {
                        cout<<("Koliko uplacujete?\n");
                        cin>>("%lf", &uplata);
                        srand(time(NULL));
                        gol1 = rand() % 4;
                        gol2 = rand() % 4;
                        cout<<("Rezultat: %d:%d\n", gol1, gol2);
                        if (gol1 == gol2)
                        {
                            dobitak = uplata * koef0;
                            profit = (uplata * koef0) - uplata;
                            cout<<("Ishod utakmice: Nerijeseno\n");
                            cout<<("Pogodili ste ishod utakmice.\n");
                            cout<<("Vas dobitak: %.2f\n", dobitak);
                            cout<<("Vas profit: %.2f\n", profit);
                        }
                        else if (gol1 > gol2 || gol1 < gol2)
                            cout<<("Nazalost niste pogodili ishod utakmice.\n");
                    }
                    else if (kladjenje == 2)
                    {
                        cout<<("Koliko uplacujete?\n");
                        cin>>("%lf", &uplata);
                        srand(time(NULL));
                        gol1 = rand() % 4;
                        gol2 = rand() % 4;
                        cout<<("Rezultat: %d:%d\n", gol1, gol2);
                        if (gol1 < gol2)
                        {
                            dobitak = uplata * koef2;
                            profit = (uplata * koef2) - uplata;
                            cout<<("Ishod utakmice: Pobjeda %s\n", klub[1]);
                            cout<<("Pogodili ste ishod utakmice.\n");
                            cout<<("Vas dobitak: %.2f\n", dobitak);
                            cout<<("Vas profit: %.2f\n", profit);
                        }
                        else if (gol1 == gol2 || gol1 > gol2)
                            cout<<("Nazalost niste pogodili ishod utakmice.\n");
                    }
                }
        }
    return 0;
}