#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int main()
{
    int uplata = 0, koef, isplata, izbor, tablica[10][3];
    printf("EUROBET\n");
    printf("Kladite se odgovorno!  18+\n");
    printf("Cijena uplate je 50c.\n");
    printf("Izaberite ligu pomocu broja.\n");
    printf("1. HNL\n");
    printf("2. Premier League\n");
    printf("3. La Liga\n");
    printf("4. Bundesliga\n");
    printf("5. Serie A\n");
    printf("6. Ligue 1\n");
    scanf("%d", &izbor);
    if (izbor == 1)
    {
        printf("\n");
        printf("Trenutna tablica:\n"); // printanje live tablice
        printf("HNL 2022/23\n");
        char momcadi[10][30] = {"GNK Dinamo Zagreb   ", "HNK Hajduk Split    ",
                                "NK Osijek           ", "HNK Rijeka          ",
                                "NK Istra 1961       ", "NK Varazdin         ",
                                "NK Lokomotiva Zagreb", "NK Slaven Belupo    ",
                                "HNK Gorica          ", "HNK Sibenik         "};
        int bodovi[10] = {81, 71, 50, 49, 46, 46, 43, 43, 32, 27};
        for (int i = 0; i < 10; i++)
            printf("%d.\t%s\t%d\n", i + 1, momcadi[i], bodovi[i]);
        printf("\n"); // printanje 5 random utakmica
        printf("Utakmice ovog kola:\n");
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
            printf("%d.\t", i + 1);
            tim1 = rand() % br_timova;
            for (int i = 0; i < 200; i++)
                if (strcmp(timovi[tim1], "") == 0)
                    tim1 = rand() % br_timova;
            strcpy(klub[brojac], timovi[tim1]);
            tim[brojac] = tim1;
            brojac++;
            printf("%s\t", timovi[tim1]);
            strcpy(timovi[tim1], timovi[10]);
            printf("vs\t");
            tim2 = rand() % br_timova;
            for (int i = 0; i < 200; i++)
                if (strcmp(timovi[tim2], "") == 0)
                    tim2 = rand() % br_timova;
            strcpy(klub[brojac], timovi[tim2]);
            tim[brojac] = tim2;
            brojac++;
            printf("%s", timovi[tim2]);
            strcpy(timovi[tim2], timovi[10]);
            printf("\n");
        }
        int izbor_utk, kladjenje, rand_rez, gol1, gol2;
        double koef1, koef0, koef2, koef_1, koef__1, koef_2, koef__2, uplata,
            dobitak, profit;
        {
            printf("\n");
            printf("Molimo unesite redni broj utakmice na koju se želite kladiti.\n");
            scanf("%d", &izbor_utk);
            if (izbor_utk == 1)
            {
                printf("Odabrali ste utakmicu:\n%s vs %s\n", klub[0], klub[1]);
                printf("\n");
                printf("Kladite se prema sljedecim oznakama:\n");
                printf("Pobjeda domaćina - 1\n");
                printf("Neriješen rezultat - 0\n");
                printf("Pobjeda gosta - 2\n");
                printf("\n");
                printf("Koeficijenti:\n");
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
                printf("1\t%s: %.2f\n", klub[0], koef1);
                printf("0\tIzjednaceno/nerjeseno: %.2f\n", koef0);
                printf("2\t%s: %.2f\n\n", klub[1], koef2);
                printf("Odaberite na sto se kladite pomocu prethodnih oznaka.\n");
                scanf("%d", &kladjenje);
                if (kladjenje == 1)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 > gol2)
                    {
                        dobitak = uplata * koef1;
                        profit = (uplata * koef1) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[0]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 0)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 == gol2)
                    {
                        dobitak = uplata * koef0;
                        profit = (uplata * koef0) - uplata;
                        printf("Ishod utakmice: Nerijeseno\n");
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 > gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 2)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 < gol2)
                    {
                        dobitak = uplata * koef2;
                        profit = (uplata * koef2) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[1]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
            }
            else if (izbor_utk == 2)
            {
                printf("Odabrali ste utakmicu:\n%s vs %s\n", klub[2], klub[3]);
                printf("\n");
                printf("Kladite se prema sljedecim oznakama:\n");
                printf("Pobjeda domaćina - 1\n");
                printf("Neriješen rezultat - 0\n");
                printf("Pobjeda gosta - 2\n");
                printf("\n");
                printf("Koeficijenti:\n");
                if (tim[2] < tim[3])
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
                else if (tim[3] < tim[2])
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
                printf("1\t%s: %.2f\n", klub[2], koef1);
                printf("0\tIzjednaceno/nerjeseno: %.2f\n", koef0);
                printf("2\t%s: %.2f\n\n", klub[3], koef2);
                printf("Odaberite na sto se kladite pomocu prethodnih oznaka.\n");
                scanf("%d", &kladjenje);
                if (kladjenje == 1)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 > gol2)
                    {
                        dobitak = uplata * koef1;
                        profit = (uplata * koef1) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[2]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 0)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 == gol2)
                    {
                        dobitak = uplata * koef0;
                        profit = (uplata * koef0) - uplata;
                        printf("Ishod utakmice: Nerijeseno\n");
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 < gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 2)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 < gol2)
                    {
                        dobitak = uplata * koef2;
                        profit = (uplata * koef2) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[3]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
            }
            else if (izbor_utk == 3)
            {
                printf("Odabrali ste utakmicu:\n%s vs %s\n", klub[4], klub[5]);
                printf("\n");
                printf("Kladite se prema sljedecim oznakama:\n");
                printf("Pobjeda domaćina - 1\n");
                printf("Neriješen rezultat - 0\n");
                printf("Pobjeda gosta - 2\n");
                printf("\n");
                printf("Koeficijenti:\n");
                if (tim[4] < tim[5])
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
                else if (tim[5] < tim[4])
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
                printf("1\t%s: %.2f\n", klub[4], koef1);
                printf("0\tIzjednaceno/nerjeseno: %.2f\n", koef0);
                printf("2\t%s: %.2f\n\n", klub[5], koef2);
                printf("Odaberite na sto se kladite pomocu prethodnih oznaka.\n");
                scanf("%d", &kladjenje);
                if (kladjenje == 1)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 > gol2)
                    {
                        dobitak = uplata * koef1;
                        profit = (uplata * koef1) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[4]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 0)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 == gol2)
                    {
                        dobitak = uplata * koef0;
                        profit = (uplata * koef0) - uplata;
                        printf("Ishod utakmice: Nerijeseno\n");
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 < gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.");
                }
                else if (kladjenje == 2)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 < gol2)
                    {
                        dobitak = uplata * koef2;
                        profit = (uplata * koef2) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[5]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
            }
            else if (izbor_utk == 4)
            {
                printf("Odabrali ste utakmicu:\n%s vs %s\n", klub[6], klub[7]);
                printf("\n");
                printf("Kladite se prema sljedecim oznakama:\n");
                printf("Pobjeda domaćina - 1\n");
                printf("Neriješen rezultat - 0\n");
                printf("Pobjeda gosta - 2\n");
                printf("\n");
                printf("Koeficijenti:\n");
                if (tim[6] < tim[7])
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
                else if (tim[7] < tim[6])
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
                printf("1\t%s: %.2f\n", klub[6], koef1);
                printf("0\tIzjednaceno/nerjeseno: %.2f\n", koef0);
                printf("2\t%s: %.2f\n\n", klub[7], koef2);
                printf("Odaberite na sto se kladite pomocu prethodnih oznaka.\n");
                scanf("%d", &kladjenje);
                if (kladjenje == 1)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 > gol2)
                    {
                        dobitak = uplata * koef1;
                        profit = (uplata * koef1) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[6]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 0)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 == gol2)
                    {
                        dobitak = uplata * koef0;
                        profit = (uplata * koef0) - uplata;
                        printf("Ishod utakmice: Nerijeseno\n");
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 < gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 2)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 < gol2)
                    {
                        dobitak = uplata * koef2;
                        profit = (uplata * koef2) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[7]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
            }
            else if (izbor_utk == 5)
            {
                printf("Odabrali ste utakmicu:\n%s vs %s\n", klub[8], klub[9]);
                printf("\n");
                printf("Kladite se prema sljedecim oznakama:\n");
                printf("Pobjeda domaćina - 1\n");
                printf("Neriješen rezultat - 0\n");
                printf("Pobjeda gosta - 2\n");
                printf("\n");
                printf("Koeficijenti:\n");
                if (tim[8] < tim[9])
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
                else if (tim[9] < tim[8])
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
                printf("1\t%s: %.2f\n", klub[8], koef1);
                printf("0\tIzjednaceno/nerjeseno: %.2f\n", koef0);
                printf("2\t%s: %.2f\n\n", klub[9], koef2);
                printf("Odaberite na sto se kladite pomocu prethodnih oznaka.\n");
                scanf("%d", &kladjenje);
                if (kladjenje == 1)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 > gol2)
                    {
                        dobitak = uplata * koef1;
                        profit = (uplata * koef1) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[8]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 0)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 < gol2)
                    {
                        dobitak = uplata * koef0;
                        profit = (uplata * koef0) - uplata;
                        printf("Ishod utakmice: Nerijeseno\n");
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 < gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 2)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 < gol2)
                    {
                        dobitak = uplata * koef2;
                        profit = (uplata * koef2) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[9]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
            }
        }
    }
    else if (izbor == 2)
    {
        printf("\n");
        printf("Trenutna tablica:\n"); // printanje live tablice
        printf("Premier League 2022/23\n");
        char momcadi[20][30] = {"Manchester City       ", "Arsenal               ",
                                "Manchester United     ", "Newcastle United      ",
                                "Liverpool             ", "Brighton & Hove Albion",
                                "Aston Villa           ", "Tottenham Hotspur     ",
                                "Brentford             ", "Fulham                ",
                                "Crystal Palace        ", "Chelsea               ",
                                "Wolverhampton         ", "West Ham United       ",
                                "Bournemouth           ", "Nottingham Forest     ",
                                "Everton               ", "Leicester City        ",
                                "Leeds United          ", "Southampton           "};
        int bodovi[20] = {89, 84, 75, 71, 67, 62, 61, 60, 59, 52,
                          45, 44, 41, 40, 39, 38, 36, 34, 31, 25};
        for (int i = 0; i < 20; i++)
            printf("%d.\t%s\t%d\n", i + 1, momcadi[i], bodovi[i]);
        printf("\n"); // printanje 10 random utakmica
        printf("Utakmice ovog kola:\n");
#define br_timova 21
        char timovi[br_timova][23] = {"Manchester City",
                                      "Arsenal",
                                      "Manchester United",
                                      "Newcastle United",
                                      "Liverpool",
                                      "Brighton & Hove Albion",
                                      "Aston Villa",
                                      "Tottenham Hotspur",
                                      "Brentford",
                                      "Fulham",
                                      "Crystal Palace",
                                      "Chelsea",
                                      "Wolverhampton",
                                      "West Ham United",
                                      "Bournemouth",
                                      "Nottingham Forest",
                                      "Everton",
                                      "Leicester City",
                                      "Leeds United",
                                      "Southampton",
                                      ""};
        char klub[br_timova][23];
        srand(time(NULL));
        int tim1, tim2, brojac = 0, tim[20];
        for (int i = 0; i < 10; i++)
        {
            printf("%d.\t", i + 1);
            tim1 = rand() % br_timova;
            for (int i = 0; i < 200; i++)
                if (strcmp(timovi[tim1], "") == 0)
                    tim1 = rand() % br_timova;
            strcpy(klub[brojac], timovi[tim1]);
            tim[brojac] = tim1;
            brojac++;
            printf("%s\t", timovi[tim1]);
            strcpy(timovi[tim1], timovi[20]);
            printf("vs\t");
            tim2 = rand() % br_timova;
            for (int i = 0; i < 200; i++)
                if (strcmp(timovi[tim2], "") == 0)
                    tim2 = rand() % br_timova;
            strcpy(klub[brojac], timovi[tim2]);
            tim[brojac] = tim2;
            brojac++;
            printf("%s", timovi[tim2]);
            strcpy(timovi[tim2], timovi[20]);
            printf("\n");
        }
        int izbor_utk, kladjenje, gol1, gol2;
        double koef1, koef0, koef2, koef_1, koef__1, koef_2, koef__2, uplata,
            dobitak, profit;
        while (1)
        {
            printf("\n");
            printf("Molimo unesite redni broj utakmice na koju se želite kladiti.\n");
            scanf("%d", &izbor_utk);
            if (izbor_utk == 1)
            {
                printf("Odabrali ste utakmicu: %s vs %s\n", klub[0], klub[1]);
                printf("\n");
                printf("Kladite se prema sljedecim oznakama:\n");
                printf("Pobjeda domaćina - 1\n");
                printf("Neriješen rezultat - 0\n");
                printf("Pobjeda gosta - 2\n");
                printf("\n");
                printf("Koeficijenti:\n");
                if (tim[0] < tim[1])
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
                printf("1\t%s: %.2f\n", klub[0], koef1);
                printf("0\tIzjednaceno/nerjeseno: %.2f\n", koef0);
                printf("2\t%s: %.2f\n\n", klub[1], koef2);
                printf("Odaberite na sto se kladite pomocu prethodnih oznaka.\n");
                scanf("%d", &kladjenje);
                if (kladjenje == 1)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 > gol2)
                    {
                        dobitak = uplata * koef1;
                        profit = (uplata * koef1) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[0]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 0)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 == gol2)
                    {
                        dobitak = uplata * koef0;
                        profit = (uplata * koef0) - uplata;
                        printf("Ishod utakmice: Nerijeseno\n");
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 < gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 2)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 < gol2)
                    {
                        dobitak = uplata * koef2;
                        profit = (uplata * koef2) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[1]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
            }
            else if (izbor_utk == 2)
            {
                printf("Odabrali ste utakmicu: %s vs %s\n", klub[2], klub[3]);
                printf("\n");
                printf("Kladite se prema sljedecim oznakama:\n");
                printf("Pobjeda domaćina - 1\n");
                printf("Neriješen rezultat - 0\n");
                printf("Pobjeda gosta - 2\n");
                printf("\n");
                printf("Koeficijenti:\n");
                if (tim[2] < tim[3])
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
                else if (tim[3] < tim[2])
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
                printf("1\t%s: %.2f\n", klub[2], koef1);
                printf("0\tIzjednaceno/nerjeseno: %.2f\n", koef0);
                printf("2\t%s: %.2f\n\n", klub[3], koef2);
                printf("Odaberite na sto se kladite pomocu prethodnih oznaka.\n");
                scanf("%d", &kladjenje);
                if (kladjenje == 1)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 > gol2)
                    {
                        dobitak = uplata * koef1;
                        profit = (uplata * koef1) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[2]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 0)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 == gol2)
                    {
                        dobitak = uplata * koef0;
                        profit = (uplata * koef0) - uplata;
                        printf("Ishod utakmice: Nerijeseno\n");
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 < gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 2)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 < gol2)
                    {
                        dobitak = uplata * koef2;
                        profit = (uplata * koef2) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[3]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
            }
            else if (izbor_utk == 3)
            {
                printf("Odabrali ste utakmicu: %s vs %s\n", klub[4], klub[5]);
                printf("\n");
                printf("Kladite se prema sljedecim oznakama:\n");
                printf("Pobjeda domaćina - 1\n");
                printf("Neriješen rezultat - 0\n");
                printf("Pobjeda gosta - 2\n");
                printf("\n");
                printf("Koeficijenti:\n");
                if (tim[4] < tim[5])
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
                else if (tim[5] < tim[4])
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
                printf("1\t%s: %.2f\n", klub[4], koef1);
                printf("0\tIzjednaceno/nerjeseno: %.2f\n", koef0);
                printf("2\t%s: %.2f\n\n", klub[5], koef2);
                printf("Odaberite na sto se kladite pomocu prethodnih oznaka.\n");
                scanf("%d", &kladjenje);
                if (kladjenje == 1)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 > gol2)
                    {
                        dobitak = uplata * koef1;
                        profit = (uplata * koef1) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[4]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 0)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 == gol2)
                    {
                        dobitak = uplata * koef0;
                        profit = (uplata * koef0) - uplata;
                        printf("Ishod utakmice: Nerijeseno\n");
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 < gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 2)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 < gol2)
                    {
                        dobitak = uplata * koef2;
                        profit = (uplata * koef2) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[5]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
            }
            else if (izbor_utk == 4)
            {
                printf("Odabrali ste utakmicu: %s vs %s\n", klub[6], klub[7]);
                printf("\n");
                printf("Kladite se prema sljedecim oznakama:\n");
                printf("Pobjeda domaćina - 1\n");
                printf("Neriješen rezultat - 0\n");
                printf("Pobjeda gosta - 2\n");
                printf("\n");
                printf("Koeficijenti:\n");
                if (tim[6] < tim[7])
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
                else if (tim[7] < tim[6])
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
                printf("1\t%s: %.2f\n", klub[6], koef1);
                printf("0\tIzjednaceno/nerjeseno: %.2f\n", koef0);
                printf("2\t%s: %.2f\n\n", klub[7], koef2);
                printf("Odaberite na sto se kladite pomocu prethodnih oznaka.\n");
                scanf("%d", &kladjenje);
                if (kladjenje == 1)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 > gol2)
                    {
                        dobitak = uplata * koef1;
                        profit = (uplata * koef1) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[6]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 0)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 == gol2)
                    {
                        dobitak = uplata * koef0;
                        profit = (uplata * koef0) - uplata;
                        printf("Ishod utakmice: Nerijeseno\n");
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 < gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 2)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 < gol2)
                    {
                        dobitak = uplata * koef2;
                        profit = (uplata * koef2) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[7]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
            }
            else if (izbor_utk == 5)
            {
                printf("Odabrali ste utakmicu: %s vs %s\n", klub[8], klub[9]);
                printf("\n");
                printf("Kladite se prema sljedecim oznakama:\n");
                printf("Pobjeda domaćina - 1\n");
                printf("Neriješen rezultat - 0\n");
                printf("Pobjeda gosta - 2\n");
                printf("\n");
                printf("Koeficijenti:\n");
                if (tim[8] < tim[9])
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
                else if (tim[9] < tim[8])
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
                printf("1\t%s: %.2f\n", klub[8], koef1);
                printf("0\tIzjednaceno/nerjeseno: %.2f\n", koef0);
                printf("2\t%s: %.2f\n\n", klub[9], koef2);
                printf("Odaberite na sto se kladite pomocu prethodnih oznaka.\n");
                scanf("%d", &kladjenje);
                if (kladjenje == 1)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 > gol2)
                    {
                        dobitak = uplata * koef1;
                        profit = (uplata * koef1) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[8]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 0)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 == gol2)
                    {
                        dobitak = uplata * koef0;
                        profit = (uplata * koef0) - uplata;
                        printf("Ishod utakmice: Nerijeseno\n");
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 > gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 2)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 < gol2)
                    {
                        dobitak = uplata * koef2;
                        profit = (uplata * koef2) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[9]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
            }
            else if (izbor_utk == 6)
            {
                printf("Odabrali ste utakmicu: %s vs %s\n", klub[10], klub[11]);
                printf("\n");
                printf("Kladite se prema sljedecim oznakama:\n");
                printf("Pobjeda domaćina - 1\n");
                printf("Neriješen rezultat - 0\n");
                printf("Pobjeda gosta - 2\n");
                printf("\n");
                printf("Koeficijenti:\n");
                if (tim[10] < tim[11])
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
                else if (tim[11] < tim[10])
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
                printf("1\t%s: %.2f\n", klub[10], koef1);
                printf("0\tIzjednaceno/nerjeseno: %.2f\n", koef0);
                printf("2\t%s: %.2f\n\n", klub[11], koef2);
                printf("Odaberite na sto se kladite pomocu prethodnih oznaka.\n");
                scanf("%d", &kladjenje);
                if (kladjenje == 1)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 > gol2)
                    {
                        dobitak = uplata * koef1;
                        profit = (uplata * koef1) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[10]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 0)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 == gol2)
                    {
                        dobitak = uplata * koef0;
                        profit = (uplata * koef0) - uplata;
                        printf("Ishod utakmice: Nerijeseno\n");
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 > gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 2)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 < gol2)
                    {
                        dobitak = uplata * koef2;
                        profit = (uplata * koef2) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[11]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
            }
            else if (izbor_utk == 7)
            {
                printf("Odabrali ste utakmicu: %s vs %s\n", klub[12], klub[13]);
                printf("\n");
                printf("Kladite se prema sljedecim oznakama:\n");
                printf("Pobjeda domaćina - 1\n");
                printf("Neriješen rezultat - 0\n");
                printf("Pobjeda gosta - 2\n");
                printf("\n");
                printf("Koeficijenti:\n");
                if (tim[12] < tim[13])
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
                else if (tim[13] < tim[12])
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
                printf("1\t%s: %.2f\n", klub[12], koef1);
                printf("0\tIzjednaceno/nerjeseno: %.2f\n", koef0);
                printf("2\t%s: %.2f\n\n", klub[13], koef2);
                printf("Odaberite na sto se kladite pomocu prethodnih oznaka.\n");
                scanf("%d", &kladjenje);
                if (kladjenje == 1)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 > gol2)
                    {
                        dobitak = uplata * koef1;
                        profit = (uplata * koef1) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[12]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 0)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 == gol2)
                    {
                        dobitak = uplata * koef0;
                        profit = (uplata * koef0) - uplata;
                        printf("Ishod utakmice: Nerijeseno\n");
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 > gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 2)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 < gol2)
                    {
                        dobitak = uplata * koef2;
                        profit = (uplata * koef2) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[13]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
            }
            else if (izbor_utk == 8)
            {
                printf("Odabrali ste utakmicu: %s vs %s\n", klub[14], klub[15]);
                printf("\n");
                printf("Kladite se prema sljedecim oznakama:\n");
                printf("Pobjeda domaćina - 1\n");
                printf("Neriješen rezultat - 0\n");
                printf("Pobjeda gosta - 2\n");
                printf("\n");
                printf("Koeficijenti:\n");
                if (tim[14] < tim[15])
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
                else if (tim[15] < tim[14])
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
                printf("1\t%s: %.2f\n", klub[14], koef1);
                printf("0\tIzjednaceno/nerjeseno: %.2f\n", koef0);
                printf("2\t%s: %.2f\n\n", klub[15], koef2);
                printf("Odaberite na sto se kladite pomocu prethodnih oznaka.\n");
                scanf("%d", &kladjenje);
                if (kladjenje == 1)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 > gol2)
                    {
                        dobitak = uplata * koef1;
                        profit = (uplata * koef1) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[14]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 0)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4 + 1;
                    gol2 = rand() % 4 + 1;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 == gol2)
                    {
                        dobitak = uplata * koef0;
                        profit = (uplata * koef0) - uplata;
                        printf("Ishod utakmice: Nerijeseno\n");
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 > gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 2)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 < gol2)
                    {
                        dobitak = uplata * koef2;
                        profit = (uplata * koef2) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[15]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
            }
            else if (izbor_utk == 9)
            {
                printf("Odabrali ste utakmicu: %s vs %s\n", klub[16], klub[17]);
                printf("\n");
                printf("Kladite se prema sljedecim oznakama:\n");
                printf("Pobjeda domaćina - 1\n");
                printf("Neriješen rezultat - 0\n");
                printf("Pobjeda gosta - 2\n");
                printf("\n");
                printf("Koeficijenti:\n");
                if (tim[16] < tim[17])
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
                else if (tim[17] < tim[16])
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
                printf("1\t%s: %.2f\n", klub[16], koef1);
                printf("0\tIzjednaceno/nerjeseno: %.2f\n", koef0);
                printf("2\t%s: %.2f\n\n", klub[17], koef2);
                printf("Odaberite na sto se kladite pomocu prethodnih oznaka.\n");
                scanf("%d", &kladjenje);
                if (kladjenje == 1)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 > gol2)
                    {
                        dobitak = uplata * koef1;
                        profit = (uplata * koef1) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[16]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 0)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 == gol2)
                    {
                        dobitak = uplata * koef0;
                        profit = (uplata * koef0) - uplata;
                        printf("Ishod utakmice: Nerijeseno\n");
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 > gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 2)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 < gol2)
                    {
                        dobitak = uplata * koef2;
                        profit = (uplata * koef2) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[17]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
            }
            else if (izbor_utk == 10)
            {
                printf("Odabrali ste utakmicu: %s vs %s\n", klub[18], klub[19]);
                printf("\n");
                printf("Kladite se prema sljedecim oznakama:\n");
                printf("Pobjeda domaćina - 1\n");
                printf("Neriješen rezultat - 0\n");
                printf("Pobjeda gosta - 2\n");
                printf("\n");
                printf("Koeficijenti:\n");
                if (tim[18] < tim[19])
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
                else if (tim[19] < tim[18])
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
                printf("1\t%s: %.2f\n", klub[18], koef1);
                printf("0\tIzjednaceno/nerjeseno: %.2f\n", koef0);
                printf("2\t%s: %.2f\n\n", klub[19], koef2);
                printf("Odaberite na sto se kladite pomocu prethodnih oznaka.\n");
                scanf("%d", &kladjenje);
                if (kladjenje == 1)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 > gol2)
                    {
                        dobitak = uplata * koef1;
                        profit = (uplata * koef1) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[18]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 0)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 == gol2)
                    {
                        dobitak = uplata * koef0;
                        profit = (uplata * koef0) - uplata;
                        printf("Ishod utakmice: Nerijeseno\n");
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 > gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 2)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 < gol2)
                    {
                        dobitak = uplata * koef2;
                        profit = (uplata * koef2) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[19]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
            }
            else
            {
                printf("Unesite važeći broj.\n");
            }
            break;
        }
    }
    else if (izbor == 3)
    {
        printf("\n");
        printf("Trenutna tablica:\n"); // printanje live tablice
        printf("LaLiga 2022/23\n");
        char momcadi[20][30] = {
            "Barcelona      ", "Real Madrid    ", "Atletico Madrid",
            "Real Sociedad  ", "Villareal      ", "Real Betis     ",
            "Osasuna        ", "Athletic Club  ", "Mallorca       ",
            "Girona         ", "Rayo Vallecano ", "Sevilla        ",
            "Celta Vigo     ", "Cadiz          ", "Getafe         ",
            "Valencia       ", "Almeria        ", "Real Valladolid",
            "Espanyol       ", "Elche          "};
        int bodovi[20] = {88, 78, 77, 71, 64, 60, 53, 51, 50, 49,
                          49, 49, 43, 42, 42, 42, 41, 40, 37, 25};
        for (int i = 0; i < 20; i++)
            printf("%d.\t%s\t%d\n", i + 1, momcadi[i], bodovi[i]);
        printf("\n");
        printf("Utakmice ovog kola:\n");
#define br_timova 21
        char timovi[br_timova][16] = {
            "Barcelona", "Real Madrid", "Atletico Madrid",
            "Real Sociedad", "Villareal", "Real Betis",
            "Athletic Club", "Osasuna", "Girona",
            "Rayo Vallecano", "Sevilla", "Mallorca",
            "Cadiz", "Getafe", "Valencia",
            "Almeria", "Celta Vigo", "Real Valladolid",
            "Espanyol", "Elche", ""};
        char klub[br_timova][16];
        srand(time(NULL));
        int tim1, tim2, brojac = 0, tim[20];
        for (int i = 0; i < 10; i++)
        {
            printf("%d.\t", i + 1);
            tim1 = rand() % br_timova;
            for (int i = 0; i < 180; i++)
                if (strcmp(timovi[tim1], "") == 0)
                    tim1 = rand() % br_timova;
            strcpy(klub[brojac], timovi[tim1]);
            tim[brojac] = tim1;
            brojac++;
            printf("%s\t", timovi[tim1]);
            strcpy(timovi[tim1], timovi[20]);
            printf("vs\t");
            tim2 = rand() % br_timova;
            for (int i = 0; i < 180; i++)
                if (strcmp(timovi[tim2], "") == 0)
                    tim2 = rand() % br_timova;
            strcpy(klub[brojac], timovi[tim2]);
            tim[brojac] = tim2;
            brojac++;
            printf("%s", timovi[tim2]);
            strcpy(timovi[tim2], timovi[20]);
            printf("\n");
        }
        int izbor_utk, kladjenje, gol1, gol2;
        double koef1, koef0, koef2, koef_1, koef__1, koef_2, koef__2, uplata,
            dobitak, profit;
        while (1)
        {
            printf("\n");
            printf("Molimo unesite redni broj utakmice na koju se želite kladiti.\n");
            scanf("%d", &izbor_utk);
            if (izbor_utk == 1)
            {
                printf("Odabrali ste utakmicu: %s vs %s\n", klub[0], klub[1]);
                printf("\n");
                printf("Kladite se prema sljedecim oznakama:\n");
                printf("Pobjeda domaćina - 1\n");
                printf("Neriješen rezultat - 0\n");
                printf("Pobjeda gosta - 2\n");
                printf("\n");
                printf("Koeficijenti:\n");
                if (tim[0] < tim[1])
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
                printf("1\t%s: %.2f\n", klub[0], koef1);
                printf("0\tIzjednaceno/nerjeseno: %.2f\n", koef0);
                printf("2\t%s: %.2f\n\n", klub[1], koef2);
                printf("Odaberite na sto se kladite pomocu prethodnih oznaka.\n");
                scanf("%d", &kladjenje);
                if (kladjenje == 1)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 > gol2)
                    {
                        dobitak = uplata * koef1;
                        profit = (uplata * koef1) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[0]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 0)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 == gol2)
                    {
                        dobitak = uplata * koef0;
                        profit = (uplata * koef0) - uplata;
                        printf("Ishod utakmice: Nerijeseno\n");
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 < gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 2)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 < gol2)
                    {
                        dobitak = uplata * koef2;
                        profit = (uplata * koef2) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[1]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
            }
            else if (izbor_utk == 2)
            {
                printf("Odabrali ste utakmicu: %s vs %s\n", klub[2], klub[3]);
                printf("\n");
                printf("Kladite se prema sljedecim oznakama:\n");
                printf("Pobjeda domaćina - 1\n");
                printf("Neriješen rezultat - 0\n");
                printf("Pobjeda gosta - 2\n");
                printf("\n");
                printf("Koeficijenti:\n");
                if (tim[2] < tim[3])
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
                else if (tim[3] < tim[2])
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
                printf("1\t%s: %.2f\n", klub[2], koef1);
                printf("0\tIzjednaceno/nerjeseno: %.2f\n", koef0);
                printf("2\t%s: %.2f\n\n", klub[3], koef2);
                printf("Odaberite na sto se kladite pomocu prethodnih oznaka.\n");
                scanf("%d", &kladjenje);
                if (kladjenje == 1)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 > gol2)
                    {
                        dobitak = uplata * koef1;
                        profit = (uplata * koef1) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[2]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 0)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 == gol2)
                    {
                        dobitak = uplata * koef0;
                        profit = (uplata * koef0) - uplata;
                        printf("Ishod utakmice: Nerijeseno\n");
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 < gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 2)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 < gol2)
                    {
                        dobitak = uplata * koef2;
                        profit = (uplata * koef2) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[3]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
            }
            else if (izbor_utk == 3)
            {
                printf("Odabrali ste utakmicu: %s vs %s\n", klub[4], klub[5]);
                printf("\n");
                printf("Kladite se prema sljedecim oznakama:\n");
                printf("Pobjeda domaćina - 1\n");
                printf("Neriješen rezultat - 0\n");
                printf("Pobjeda gosta - 2\n");
                printf("\n");
                printf("Koeficijenti:\n");
                if (tim[4] < tim[5])
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
                else if (tim[5] < tim[4])
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
                printf("1\t%s: %.2f\n", klub[4], koef1);
                printf("0\tIzjednaceno/nerjeseno: %.2f\n", koef0);
                printf("2\t%s: %.2f\n\n", klub[5], koef2);
                printf("Odaberite na sto se kladite pomocu prethodnih oznaka.\n");
                scanf("%d", &kladjenje);
                if (kladjenje == 1)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 > gol2)
                    {
                        dobitak = uplata * koef1;
                        profit = (uplata * koef1) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[4]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 0)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 == gol2)
                    {
                        dobitak = uplata * koef0;
                        profit = (uplata * koef0) - uplata;
                        printf("Ishod utakmice: Nerijeseno\n");
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 < gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 2)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 < gol2)
                    {
                        dobitak = uplata * koef2;
                        profit = (uplata * koef2) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[5]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
            }
            else if (izbor_utk == 4)
            {
                printf("Odabrali ste utakmicu: %s vs %s\n", klub[6], klub[7]);
                printf("\n");
                printf("Kladite se prema sljedecim oznakama:\n");
                printf("Pobjeda domaćina - 1\n");
                printf("Neriješen rezultat - 0\n");
                printf("Pobjeda gosta - 2\n");
                printf("\n");
                printf("Koeficijenti:\n");
                if (tim[6] < tim[7])
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
                else if (tim[7] < tim[6])
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
                printf("1\t%s: %.2f\n", klub[6], koef1);
                printf("0\tIzjednaceno/nerjeseno: %.2f\n", koef0);
                printf("2\t%s: %.2f\n\n", klub[7], koef2);
                printf("Odaberite na sto se kladite pomocu prethodnih oznaka.\n");
                scanf("%d", &kladjenje);
                if (kladjenje == 1)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 > gol2)
                    {
                        dobitak = uplata * koef1;
                        profit = (uplata * koef1) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[6]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 0)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 == gol2)
                    {
                        dobitak = uplata * koef0;
                        profit = (uplata * koef0) - uplata;
                        printf("Ishod utakmice: Nerijeseno\n");
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 < gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 2)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 < gol2)
                    {
                        dobitak = uplata * koef2;
                        profit = (uplata * koef2) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[7]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
            }
            else if (izbor_utk == 5)
            {
                printf("Odabrali ste utakmicu: %s vs %s\n", klub[8], klub[9]);
                printf("\n");
                printf("Kladite se prema sljedecim oznakama:\n");
                printf("Pobjeda domaćina - 1\n");
                printf("Neriješen rezultat - 0\n");
                printf("Pobjeda gosta - 2\n");
                printf("\n");
                printf("Koeficijenti:\n");
                if (tim[8] < tim[9])
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
                else if (tim[9] < tim[8])
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
                printf("1\t%s: %.2f\n", klub[8], koef1);
                printf("0\tIzjednaceno/nerjeseno: %.2f\n", koef0);
                printf("2\t%s: %.2f\n\n", klub[9], koef2);
                printf("Odaberite na sto se kladite pomocu prethodnih oznaka.\n");
                scanf("%d", &kladjenje);
                if (kladjenje == 1)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 > gol2)
                    {
                        dobitak = uplata * koef1;
                        profit = (uplata * koef1) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[8]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 0)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 == gol2)
                    {
                        dobitak = uplata * koef0;
                        profit = (uplata * koef0) - uplata;
                        printf("Ishod utakmice: Nerijeseno\n");
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 > gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 2)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 < gol2)
                    {
                        dobitak = uplata * koef2;
                        profit = (uplata * koef2) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[9]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
            }
            else if (izbor_utk == 6)
            {
                printf("Odabrali ste utakmicu: %s vs %s\n", klub[10], klub[11]);
                printf("\n");
                printf("Kladite se prema sljedecim oznakama:\n");
                printf("Pobjeda domaćina - 1\n");
                printf("Neriješen rezultat - 0\n");
                printf("Pobjeda gosta - 2\n");
                printf("\n");
                printf("Koeficijenti:\n");
                if (tim[10] < tim[11])
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
                else if (tim[11] < tim[10])
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
                printf("1\t%s: %.2f\n", klub[10], koef1);
                printf("0\tIzjednaceno/nerijeseno: %.2f\n", koef0);
                printf("2\t%s: %.2f\n\n", klub[11], koef2);
                printf("Odaberite na sto se kladite pomocu prethodnih oznaka.\n");
                scanf("%d", &kladjenje);
                if (kladjenje == 1)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 > gol2)
                    {
                        dobitak = uplata * koef1;
                        profit = (uplata * koef1) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[10]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 0)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 == gol2)
                    {
                        dobitak = uplata * koef0;
                        profit = (uplata * koef0) - uplata;
                        printf("Ishod utakmice: Nerijeseno\n");
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 > gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 2)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 < gol2)
                    {
                        dobitak = uplata * koef2;
                        profit = (uplata * koef2) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[11]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
            }
            else if (izbor_utk == 7)
            {
                printf("Odabrali ste utakmicu: %s vs %s\n", klub[12], klub[13]);
                printf("\n");
                printf("Kladite se prema sljedecim oznakama:\n");
                printf("Pobjeda domaćina - 1\n");
                printf("Neriješen rezultat - 0\n");
                printf("Pobjeda gosta - 2\n");
                printf("\n");
                printf("Koeficijenti:\n");
                if (tim[12] < tim[13])
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
                else if (tim[13] < tim[12])
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
                printf("1\t%s: %.2f\n", klub[12], koef1);
                printf("0\tIzjednaceno/nerjeseno: %.2f\n", koef0);
                printf("2\t%s: %.2f\n\n", klub[13], koef2);
                printf("Odaberite na sto se kladite pomocu prethodnih oznaka.\n");
                scanf("%d", &kladjenje);
                if (kladjenje == 1)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 > gol2)
                    {
                        dobitak = uplata * koef1;
                        profit = (uplata * koef1) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[12]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 0)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 == gol2)
                    {
                        dobitak = uplata * koef0;
                        profit = (uplata * koef0) - uplata;
                        printf("Ishod utakmice: Nerijeseno\n");
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 > gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 2)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 < gol2)
                    {
                        dobitak = uplata * koef2;
                        profit = (uplata * koef2) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[13]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
            }
            else if (izbor_utk == 8)
            {
                printf("Odabrali ste utakmicu: %s vs %s\n", klub[14], klub[15]);
                printf("\n");
                printf("Kladite se prema sljedecim oznakama:\n");
                printf("Pobjeda domaćina - 1\n");
                printf("Neriješen rezultat - 0\n");
                printf("Pobjeda gosta - 2\n");
                printf("\n");
                printf("Koeficijenti:\n");
                if (tim[14] < tim[15])
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
                else if (tim[15] < tim[14])
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
                printf("1\t%s: %.2f\n", klub[14], koef1);
                printf("0\tIzjednaceno/nerjeseno: %.2f\n", koef0);
                printf("2\t%s: %.2f\n\n", klub[15], koef2);
                printf("Odaberite na sto se kladite pomocu prethodnih oznaka.\n");
                scanf("%d", &kladjenje);
                if (kladjenje == 1)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 > gol2)
                    {
                        dobitak = uplata * koef1;
                        profit = (uplata * koef1) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[14]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 0)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 == gol2)
                    {
                        dobitak = uplata * koef0;
                        profit = (uplata * koef0) - uplata;
                        printf("Ishod utakmice: Nerijeseno\n");
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 > gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 2)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 < gol2)
                    {
                        dobitak = uplata * koef2;
                        profit = (uplata * koef2) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[15]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
            }
            else if (izbor_utk == 9)
            {
                printf("Odabrali ste utakmicu: %s vs %s\n", klub[16], klub[17]);
                printf("\n");
                printf("Kladite se prema sljedecim oznakama:\n");
                printf("Pobjeda domaćina - 1\n");
                printf("Neriješen rezultat - 0\n");
                printf("Pobjeda gosta - 2\n");
                printf("\n");
                printf("Koeficijenti:\n");
                if (tim[16] < tim[17])
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
                else if (tim[17] < tim[16])
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
                printf("1\t%s: %.2f\n", klub[16], koef1);
                printf("0\tIzjednaceno/nerjeseno: %.2f\n", koef0);
                printf("2\t%s: %.2f\n\n", klub[17], koef2);
                printf("Odaberite na sto se kladite pomocu prethodnih oznaka.\n");
                scanf("%d", &kladjenje);
                if (kladjenje == 1)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 > gol2)
                    {
                        dobitak = uplata * koef1;
                        profit = (uplata * koef1) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[16]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 0)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 == gol2)
                    {
                        dobitak = uplata * koef0;
                        profit = (uplata * koef0) - uplata;
                        printf("Ishod utakmice: Nerijeseno\n");
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 > gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 2)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 < gol2)
                    {
                        dobitak = uplata * koef2;
                        profit = (uplata * koef2) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[17]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
            }
            else if (izbor_utk == 10)
            {
                printf("Odabrali ste utakmicu: %s vs %s\n", klub[18], klub[19]);
                printf("\n");
                printf("Kladite se prema sljedecim oznakama:\n");
                printf("Pobjeda domaćina - 1\n");
                printf("Neriješen rezultat - 0\n");
                printf("Pobjeda gosta - 2\n");
                printf("\n");
                printf("Koeficijenti:\n");
                if (tim[18] < tim[19])
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
                else if (tim[19] < tim[18])
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
                printf("1\t%s: %.2f\n", klub[18], koef1);
                printf("0\tIzjednaceno/nerjeseno: %.2f\n", koef0);
                printf("2\t%s: %.2f\n\n", klub[19], koef2);
                printf("Odaberite na sto se kladite pomocu prethodnih oznaka.\n");
                scanf("%d", &kladjenje);
                if (kladjenje == 1)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 > gol2)
                    {
                        dobitak = uplata * koef1;
                        profit = (uplata * koef1) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[18]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 0)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 == gol2)
                    {
                        dobitak = uplata * koef0;
                        profit = (uplata * koef0) - uplata;
                        printf("Ishod utakmice: Nerijeseno\n");
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 > gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 2)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 < gol2)
                    {
                        dobitak = uplata * koef2;
                        profit = (uplata * koef2) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[19]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
            }
            else
            {
                printf("Unesite važeći broj.\n");
            }
            break;
        }
    }
    else if (izbor == 4)
    {
        printf("\n");
        printf("Trenutna tablica:\n"); // printanje live tablice
        printf("Bundesliga 2022/23\n");
        char momcadi[18][30] = {
            "FC Bayern Munchen  ", "Borussia Dortmund  ", "RB Leipzig         ",
            "1. FC Union Berlin ", "SC Freiburg        ", "Bayer 04 Leverkusen",
            "Eintracht Frankfurt", "VfL Wolfsburg      ", "1. FSV Mainz 05    ",
            "Borussia M'gladbach", "1. FC Koln         ", "TSG Hoffenheim     ",
            "SV Werder Bremen   ", "VfL Bochum 1848    ", "FC Augsburg        ",
            "VfB Stuttgart      ", "FC Schalke 04      ", "Hertha Berlin      "};
        int bodovi[18] = {71, 71, 66, 62, 59, 50, 50, 49, 46,
                          43, 42, 36, 36, 35, 34, 33, 31, 29};
        for (int i = 0; i < 18; i++)
            printf("%d.\t%s\t%d\n", i + 1, momcadi[i], bodovi[i]);
        printf("\n");
        printf("Utakmice ovog kola:\n");
#define br_timova 19
        char timovi[br_timova][20] = {"FC Bayern Munchen",
                                      "Borussia Dortmund",
                                      "RB Leipzig",
                                      "1. FC Union Berlin",
                                      "SC Freiburg",
                                      "Bayer 04 Leverkusen",
                                      "Eintracht Frankfurt",
                                      "VfL Wolfsburg",
                                      "1. FSV Mainz 05",
                                      "Borussia M'gladbach",
                                      "1. FC Koln",
                                      "TSG Hoffenheim",
                                      "SV Werder Bremen",
                                      "VfL Bochum 1848",
                                      "FC Augsburg",
                                      "VfB Stuttgart",
                                      "FC Schalke 04",
                                      "Hertha Berlin",
                                      ""};
        char klub[br_timova][20];
        srand(time(NULL));
        int tim1, tim2, brojac = 0, tim[19];
        for (int i = 0; i < 9; i++)
        {
            printf("%d.\t", i + 1);
            tim1 = rand() % br_timova;
            for (int i = 0; i < 200; i++)
                if (strcmp(timovi[tim1], "") == 0)
                    tim1 = rand() % br_timova;
            strcpy(klub[brojac], timovi[tim1]);
            tim[brojac] = tim1;
            brojac++;
            printf("%s\t", timovi[tim1]);
            strcpy(timovi[tim1], timovi[18]);
            printf("vs\t");
            tim2 = rand() % br_timova;
            for (int i = 0; i < 200; i++)
                if (strcmp(timovi[tim2], "") == 0)
                    tim2 = rand() % br_timova;
            strcpy(klub[brojac], timovi[tim2]);
            tim[brojac] = tim2;
            brojac++;
            printf("%s", timovi[tim2]);
            strcpy(timovi[tim2], timovi[18]);
            printf("\n");
        }
        int izbor_utk, kladjenje, gol1, gol2;
        double koef1, koef0, koef2, koef_1, koef__1, koef_2, koef__2, uplata,
            dobitak, profit;
        while (1)
        {
            printf("\n");
            printf("Molimo unesite redni broj utakmice na koju se želite kladiti.\n");
            scanf("%d", &izbor_utk);
            if (izbor_utk == 1)
            {
                printf("Odabrali ste utakmicu: %s vs %s\n", klub[0], klub[1]);
                printf("\n");
                printf("Kladite se prema sljedecim oznakama:\n");
                printf("Pobjeda domaćina - 1\n");
                printf("Neriješen rezultat - 0\n");
                printf("Pobjeda gosta - 2\n");
                printf("\n");
                printf("Koeficijenti:\n");
                if (tim[0] < tim[1])
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
                printf("1\t%s: %.2f\n", klub[0], koef1);
                printf("0\tIzjednaceno/nerjeseno: %.2f\n", koef0);
                printf("2\t%s: %.2f\n\n", klub[1], koef2);
                printf("Odaberite na sto se kladite pomocu prethodnih oznaka.\n");
                scanf("%d", &kladjenje);
                if (kladjenje == 1)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 > gol2)
                    {
                        dobitak = uplata * koef1;
                        profit = (uplata * koef1) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[0]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 0)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 == gol2)
                    {
                        dobitak = uplata * koef0;
                        profit = (uplata * koef0) - uplata;
                        printf("Ishod utakmice: Nerijeseno\n");
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 < gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 2)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 < gol2)
                    {
                        dobitak = uplata * koef2;
                        profit = (uplata * koef2) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[1]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
            }
            else if (izbor_utk == 2)
            {
                printf("Odabrali ste utakmicu: %s vs %s\n", klub[2], klub[3]);
                printf("\n");
                printf("Kladite se prema sljedecim oznakama:\n");
                printf("Pobjeda domaćina - 1\n");
                printf("Neriješen rezultat - 0\n");
                printf("Pobjeda gosta - 2\n");
                printf("\n");
                printf("Koeficijenti:\n");
                if (tim[2] < tim[3])
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
                else if (tim[3] < tim[2])
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
                printf("1\t%s: %.2f\n", klub[2], koef1);
                printf("0\tIzjednaceno/nerjeseno: %.2f\n", koef0);
                printf("2\t%s: %.2f\n\n", klub[3], koef2);
                printf("Odaberite na sto se kladite pomocu prethodnih oznaka.\n");
                scanf("%d", &kladjenje);
                if (kladjenje == 1)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 > gol2)
                    {
                        dobitak = uplata * koef1;
                        profit = (uplata * koef1) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[2]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 0)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 == gol2)
                    {
                        dobitak = uplata * koef0;
                        profit = (uplata * koef0) - uplata;
                        printf("Ishod utakmice: Nerijeseno\n");
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 < gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 2)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 < gol2)
                    {
                        dobitak = uplata * koef2;
                        profit = (uplata * koef2) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[3]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
            }
            else if (izbor_utk == 3)
            {
                printf("Odabrali ste utakmicu: %s vs %s\n", klub[4], klub[5]);
                printf("\n");
                printf("Kladite se prema sljedecim oznakama:\n");
                printf("Pobjeda domaćina - 1\n");
                printf("Neriješen rezultat - 0\n");
                printf("Pobjeda gosta - 2\n");
                printf("\n");
                printf("Koeficijenti:\n");
                if (tim[4] < tim[5])
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
                else if (tim[5] < tim[4])
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
                printf("1\t%s: %.2f\n", klub[4], koef1);
                printf("0\tIzjednaceno/nerjeseno: %.2f\n", koef0);
                printf("2\t%s: %.2f\n\n", klub[5], koef2);
                printf("Odaberite na sto se kladite pomocu prethodnih oznaka.\n");
                scanf("%d", &kladjenje);
                if (kladjenje == 1)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 > gol2)
                    {
                        dobitak = uplata * koef1;
                        profit = (uplata * koef1) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[4]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 0)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 == gol2)
                    {
                        dobitak = uplata * koef0;
                        profit = (uplata * koef0) - uplata;
                        printf("Ishod utakmice: Nerijeseno\n");
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 < gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 2)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 < gol2)
                    {
                        dobitak = uplata * koef2;
                        profit = (uplata * koef2) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[5]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
            }
            else if (izbor_utk == 4)
            {
                printf("Odabrali ste utakmicu: %s vs %s\n", klub[6], klub[7]);
                printf("\n");
                printf("Kladite se prema sljedecim oznakama:\n");
                printf("Pobjeda domaćina - 1\n");
                printf("Neriješen rezultat - 0\n");
                printf("Pobjeda gosta - 2\n");
                printf("\n");
                printf("Koeficijenti:\n");
                if (tim[6] < tim[7])
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
                else if (tim[7] < tim[6])
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
                printf("1\t%s: %.2f\n", klub[6], koef1);
                printf("0\tIzjednaceno/nerjeseno: %.2f\n", koef0);
                printf("2\t%s: %.2f\n\n", klub[7], koef2);
                printf("Odaberite na sto se kladite pomocu prethodnih oznaka.\n");
                scanf("%d", &kladjenje);
                if (kladjenje == 1)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 > gol2)
                    {
                        dobitak = uplata * koef1;
                        profit = (uplata * koef1) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[6]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 0)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 == gol2)
                    {
                        dobitak = uplata * koef0;
                        profit = (uplata * koef0) - uplata;
                        printf("Ishod utakmice: Nerijeseno\n");
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 < gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 2)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 < gol2)
                    {
                        dobitak = uplata * koef2;
                        profit = (uplata * koef2) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[7]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
            }
            else if (izbor_utk == 5)
            {
                printf("Odabrali ste utakmicu: %s vs %s\n", klub[8], klub[9]);
                printf("\n");
                printf("Kladite se prema sljedecim oznakama:\n");
                printf("Pobjeda domaćina - 1\n");
                printf("Neriješen rezultat - 0\n");
                printf("Pobjeda gosta - 2\n");
                printf("\n");
                printf("Koeficijenti:\n");
                if (tim[8] < tim[9])
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
                else if (tim[9] < tim[8])
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
                printf("1\t%s: %.2f\n", klub[8], koef1);
                printf("0\tIzjednaceno/nerjeseno: %.2f\n", koef0);
                printf("2\t%s: %.2f\n\n", klub[9], koef2);
                printf("Odaberite na sto se kladite pomocu prethodnih oznaka.\n");
                scanf("%d", &kladjenje);
                if (kladjenje == 1)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 > gol2)
                    {
                        dobitak = uplata * koef1;
                        profit = (uplata * koef1) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[8]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 0)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 == gol2)
                    {
                        dobitak = uplata * koef0;
                        profit = (uplata * koef0) - uplata;
                        printf("Ishod utakmice: Nerijeseno\n");
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 > gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 2)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 < gol2)
                    {
                        dobitak = uplata * koef2;
                        profit = (uplata * koef2) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[9]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
            }
            else if (izbor_utk == 6)
            {
                printf("Odabrali ste utakmicu: %s vs %s\n", klub[10], klub[11]);
                printf("\n");
                printf("Kladite se prema sljedecim oznakama:\n");
                printf("Pobjeda domaćina - 1\n");
                printf("Neriješen rezultat - 0\n");
                printf("Pobjeda gosta - 2\n");
                printf("\n");
                printf("Koeficijenti:\n");
                if (tim[10] < tim[11])
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
                else if (tim[11] < tim[10])
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
                printf("1\t%s: %.2f\n", klub[10], koef1);
                printf("0\tIzjednaceno/nerjeseno: %.2f\n", koef0);
                printf("2\t%s: %.2f\n\n", klub[11], koef2);
                printf("Odaberite na sto se kladite pomocu prethodnih oznaka.\n");
                scanf("%d", &kladjenje);
                if (kladjenje == 1)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 > gol2)
                    {
                        dobitak = uplata * koef1;
                        profit = (uplata * koef1) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[10]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 0)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 == gol2)
                    {
                        dobitak = uplata * koef0;
                        profit = (uplata * koef0) - uplata;
                        printf("Ishod utakmice: Nerijeseno\n");
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 > gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 2)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 < gol2)
                    {
                        dobitak = uplata * koef2;
                        profit = (uplata * koef2) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[11]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
            }
            else if (izbor_utk == 7)
            {
                printf("Odabrali ste utakmicu: %s vs %s\n", klub[12], klub[13]);
                printf("\n");
                printf("Kladite se prema sljedecim oznakama:\n");
                printf("Pobjeda domaćina - 1\n");
                printf("Neriješen rezultat - 0\n");
                printf("Pobjeda gosta - 2\n");
                printf("\n");
                printf("Koeficijenti:\n");
                if (tim[12] < tim[13])
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
                else if (tim[13] < tim[12])
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
                printf("1\t%s: %.2f\n", klub[12], koef1);
                printf("0\tIzjednaceno/nerjeseno: %.2f\n", koef0);
                printf("2\t%s: %.2f\n\n", klub[13], koef2);
                printf("Odaberite na sto se kladite pomocu prethodnih oznaka.\n");
                scanf("%d", &kladjenje);
                if (kladjenje == 1)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 > gol2)
                    {
                        dobitak = uplata * koef1;
                        profit = (uplata * koef1) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[12]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 0)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 == gol2)
                    {
                        dobitak = uplata * koef0;
                        profit = (uplata * koef0) - uplata;
                        printf("Ishod utakmice: Nerijeseno\n");
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 > gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 2)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 < gol2)
                    {
                        dobitak = uplata * koef2;
                        profit = (uplata * koef2) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[13]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
            }
            else if (izbor_utk == 8)
            {
                printf("Odabrali ste utakmicu: %s vs %s\n", klub[14], klub[15]);
                printf("\n");
                printf("Kladite se prema sljedecim oznakama:\n");
                printf("Pobjeda domaćina - 1\n");
                printf("Neriješen rezultat - 0\n");
                printf("Pobjeda gosta - 2\n");
                printf("\n");
                printf("Koeficijenti:\n");
                if (tim[14] < tim[15])
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
                else if (tim[15] < tim[14])
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
                printf("1\t%s: %.2f\n", klub[14], koef1);
                printf("0\tIzjednaceno/nerjeseno: %.2f\n", koef0);
                printf("2\t%s: %.2f\n\n", klub[15], koef2);
                printf("Odaberite na sto se kladite pomocu prethodnih oznaka.\n");
                scanf("%d", &kladjenje);
                if (kladjenje == 1)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 > gol2)
                    {
                        dobitak = uplata * koef1;
                        profit = (uplata * koef1) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[14]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 0)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 == gol2)
                    {
                        dobitak = uplata * koef0;
                        profit = (uplata * koef0) - uplata;
                        printf("Ishod utakmice: Nerijeseno\n");
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 > gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 2)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 < gol2)
                    {
                        dobitak = uplata * koef2;
                        profit = (uplata * koef2) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[15]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
            }
            else if (izbor_utk == 9)
            {
                printf("Odabrali ste utakmicu: %s vs %s\n", klub[16], klub[17]);
                printf("\n");
                printf("Kladite se prema sljedecim oznakama:\n");
                printf("Pobjeda domaćina - 1\n");
                printf("Neriješen rezultat - 0\n");
                printf("Pobjeda gosta - 2\n");
                printf("\n");
                printf("Koeficijenti:\n");
                if (tim[16] < tim[17])
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
                else if (tim[17] < tim[16])
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
                printf("1\t%s: %.2f\n", klub[16], koef1);
                printf("0\tIzjednaceno/nerjeseno: %.2f\n", koef0);
                printf("2\t%s: %.2f\n\n", klub[17], koef2);
                printf("Odaberite na sto se kladite pomocu prethodnih oznaka.\n");
                scanf("%d", &kladjenje);
                if (kladjenje == 1)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 > gol2)
                    {
                        dobitak = uplata * koef1;
                        profit = (uplata * koef1) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[16]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 0)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 == gol2)
                    {
                        dobitak = uplata * koef0;
                        profit = (uplata * koef0) - uplata;
                        printf("Ishod utakmice: Nerijeseno\n");
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 > gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 2)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 < gol2)
                    {
                        dobitak = uplata * koef2;
                        profit = (uplata * koef2) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[17]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
            }
            else
            {
                printf("Unesite važeći broj.\n");
            }
            break;
        }
    }
    else if (izbor == 5)
    {
        printf("\n");
        printf("Trenutna tablica:\n"); // printanje live tablice
        printf("LaLiga 2022/23\n");
        char momcadi[20][30] = {
            "Napoli      ", "Lazio        ", "Inter        ", "Milan        ",
            "Atalanta      ", "Roma         ", "Juventus     ", "Fiorentina   ",
            "Bologna      ", "Torino       ", "Monza        ", "Udinese      ",
            "Sassuolo     ", "Empoli       ", "Salernitana  ", "Lecce        ",
            "Spezia      ", "Hellas Verona", "Cremonese    ", "Sampdoria    "};
        int bodovi[20] = {90, 74, 72, 70, 64, 63, 62, 56, 54, 53,
                          52, 46, 45, 43, 42, 36, 31, 31, 27, 19};
        for (int i = 0; i < 20; i++)
            printf("%d.\t%s\t%d\n", i + 1, momcadi[i], bodovi[i]);
        printf("\n");
        printf("Utakmice ovog kola:\n");
#define br_timova 21
        char timovi[br_timova][14] = {
            "Napoli", "Lazio", "Inter", "Milan", "Atalanta",
            "Roma", "Juventus", "Fiorentina", "Torino", "Monza",
            "Bologna", "Udinese", "Sassuolo", "Empoli", "Salernitana",
            "Lecce", "Hellas Verona", "Spezia", "Cremonese", "Sampdoria",
            ""};
        char klub[br_timova][14];
        srand(time(NULL));
        char tim1, tim2, brojac = 0, tim[20];
        for (int i = 0; i < 10; i++)
        {
            printf("%d.\t", i + 1);
            tim1 = rand() % br_timova;
            for (int i = 0; i < 200; i++)
                if (strcmp(timovi[tim1], "") == 0)
                    tim1 = rand() % br_timova;
            strcpy(klub[brojac], timovi[tim1]);
            tim[brojac] = tim1;
            brojac++;
            printf("%s\t", timovi[tim1]);
            strcpy(timovi[tim1], timovi[20]);
            printf("vs\t");
            tim2 = rand() % br_timova;
            for (int i = 0; i < 200; i++)
                if (strcmp(timovi[tim2], "") == 0)
                    tim2 = rand() % br_timova;
            strcpy(klub[brojac], timovi[tim2]);
            tim[brojac] = tim2;
            brojac++;
            printf("%s", timovi[tim2]);
            strcpy(timovi[tim2], timovi[20]);
            printf("\n");
        }
        int izbor_utk, kladjenje, gol1, gol2;
        double koef1, koef0, koef2, koef_1, koef__1, koef_2, koef__2, uplata,
            dobitak, profit;
        while (1)
        {
            printf("\n");
            printf("Molimo unesite redni broj utakmice na koju se želite kladiti.\n");
            scanf("%d", &izbor_utk);
            if (izbor_utk == 1)
            {
                printf("Odabrali ste utakmicu: %s vs %s\n", klub[0], klub[1]);
                printf("\n");
                printf("Kladite se prema sljedecim oznakama:\n");
                printf("Pobjeda domaćina - 1\n");
                printf("Neriješen rezultat - 0\n");
                printf("Pobjeda gosta - 2\n");
                printf("\n");
                printf("Koeficijenti:\n");
                if (tim[0] < tim[1])
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
                printf("1\t%s: %.2f\n", klub[0], koef1);
                printf("0\tIzjednaceno/nerjeseno: %.2f\n", koef0);
                printf("2\t%s: %.2f\n\n", klub[1], koef2);
                printf("Odaberite na sto se kladite pomocu prethodnih oznaka.\n");
                scanf("%d", &kladjenje);
                if (kladjenje == 1)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 > gol2)
                    {
                        dobitak = uplata * koef1;
                        profit = (uplata * koef1) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[0]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 0)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 == gol2)
                    {
                        dobitak = uplata * koef0;
                        profit = (uplata * koef0) - uplata;
                        printf("Ishod utakmice: Nerijeseno\n");
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 < gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 2)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 < gol2)
                    {
                        dobitak = uplata * koef2;
                        profit = (uplata * koef2) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[1]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
            }
            else if (izbor_utk == 2)
            {
                printf("Odabrali ste utakmicu: %s vs %s\n", klub[2], klub[3]);
                printf("\n");
                printf("Kladite se prema sljedecim oznakama:\n");
                printf("Pobjeda domaćina - 1\n");
                printf("Neriješen rezultat - 0\n");
                printf("Pobjeda gosta - 2\n");
                printf("\n");
                printf("Koeficijenti:\n");
                if (tim[2] < tim[3])
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
                else if (tim[3] < tim[2])
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
                printf("1\t%s: %.2f\n", klub[2], koef1);
                printf("0\tIzjednaceno/nerjeseno: %.2f\n", koef0);
                printf("2\t%s: %.2f\n\n", klub[3], koef2);
                printf("Odaberite na sto se kladite pomocu prethodnih oznaka.\n");
                scanf("%d", &kladjenje);
                if (kladjenje == 1)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 > gol2)
                    {
                        dobitak = uplata * koef1;
                        profit = (uplata * koef1) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[2]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 0)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 == gol2)
                    {
                        dobitak = uplata * koef0;
                        profit = (uplata * koef0) - uplata;
                        printf("Ishod utakmice: Nerijeseno\n");
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 < gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 2)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 < gol2)
                    {
                        dobitak = uplata * koef2;
                        profit = (uplata * koef2) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[3]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
            }
            else if (izbor_utk == 3)
            {
                printf("Odabrali ste utakmicu: %s vs %s\n", klub[4], klub[5]);
                printf("\n");
                printf("Kladite se prema sljedecim oznakama:\n");
                printf("Pobjeda domaćina - 1\n");
                printf("Neriješen rezultat - 0\n");
                printf("Pobjeda gosta - 2\n");
                printf("\n");
                printf("Koeficijenti:\n");
                if (tim[4] < tim[5])
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
                else if (tim[5] < tim[4])
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
                printf("1\t%s: %.2f\n", klub[4], koef1);
                printf("0\tIzjednaceno/nerjeseno: %.2f\n", koef0);
                printf("2\t%s: %.2f\n\n", klub[5], koef2);
                printf("Odaberite na sto se kladite pomocu prethodnih oznaka.\n");
                scanf("%d", &kladjenje);
                if (kladjenje == 1)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 > gol2)
                    {
                        dobitak = uplata * koef1;
                        profit = (uplata * koef1) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[4]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 0)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 == gol2)
                    {
                        dobitak = uplata * koef0;
                        profit = (uplata * koef0) - uplata;
                        printf("Ishod utakmice: Nerijeseno\n");
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 < gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 2)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 < gol2)
                    {
                        dobitak = uplata * koef2;
                        profit = (uplata * koef2) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[5]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
            }
            else if (izbor_utk == 4)
            {
                printf("Odabrali ste utakmicu: %s vs %s\n", klub[6], klub[7]);
                printf("\n");
                printf("Kladite se prema sljedecim oznakama:\n");
                printf("Pobjeda domaćina - 1\n");
                printf("Neriješen rezultat - 0\n");
                printf("Pobjeda gosta - 2\n");
                printf("\n");
                printf("Koeficijenti:\n");
                if (tim[6] < tim[7])
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
                else if (tim[7] < tim[6])
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
                printf("1\t%s: %.2f\n", klub[6], koef1);
                printf("0\tIzjednaceno/nerjeseno: %.2f\n", koef0);
                printf("2\t%s: %.2f\n\n", klub[7], koef2);
                printf("Odaberite na sto se kladite pomocu prethodnih oznaka.\n");
                scanf("%d", &kladjenje);
                if (kladjenje == 1)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 > gol2)
                    {
                        dobitak = uplata * koef1;
                        profit = (uplata * koef1) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[6]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 0)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 == gol2)
                    {
                        dobitak = uplata * koef0;
                        profit = (uplata * koef0) - uplata;
                        printf("Ishod utakmice: Nerijeseno\n");
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 < gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 2)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 < gol2)
                    {
                        dobitak = uplata * koef2;
                        profit = (uplata * koef2) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[7]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
            }
            else if (izbor_utk == 5)
            {
                printf("Odabrali ste utakmicu: %s vs %s\n", klub[8], klub[9]);
                printf("\n");
                printf("Kladite se prema sljedecim oznakama:\n");
                printf("Pobjeda domaćina - 1\n");
                printf("Neriješen rezultat - 0\n");
                printf("Pobjeda gosta - 2\n");
                printf("\n");
                printf("Koeficijenti:\n");
                if (tim[8] < tim[9])
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
                else if (tim[9] < tim[8])
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
                printf("1\t%s: %.2f\n", klub[8], koef1);
                printf("0\tIzjednaceno/nerjeseno: %.2f\n", koef0);
                printf("2\t%s: %.2f\n\n", klub[9], koef2);
                printf("Odaberite na sto se kladite pomocu prethodnih oznaka.\n");
                scanf("%d", &kladjenje);
                if (kladjenje == 1)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 > gol2)
                    {
                        dobitak = uplata * koef1;
                        profit = (uplata * koef1) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[8]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 0)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4 + 1;
                    gol2 = rand() % 4 + 1;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 == gol2)
                    {
                        dobitak = uplata * koef0;
                        profit = (uplata * koef0) - uplata;
                        printf("Ishod utakmice: Nerijeseno\n");
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 > gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 2)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 < gol2)
                    {
                        dobitak = uplata * koef2;
                        profit = (uplata * koef2) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[9]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
            }
            else if (izbor_utk == 6)
            {
                printf("Odabrali ste utakmicu: %s vs %s\n", klub[10], klub[11]);
                printf("\n");
                printf("Kladite se prema sljedecim oznakama:\n");
                printf("Pobjeda domaćina - 1\n");
                printf("Neriješen rezultat - 0\n");
                printf("Pobjeda gosta - 2\n");
                printf("\n");
                printf("Koeficijenti:\n");
                if (tim[10] < tim[11])
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
                else if (tim[11] < tim[10])
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
                printf("1\t%s: %.2f\n", klub[10], koef1);
                printf("0\tIzjednaceno/nerjeseno: %.2f\n", koef0);
                printf("2\t%s: %.2f\n\n", klub[11], koef2);
                printf("Odaberite na sto se kladite pomocu prethodnih oznaka.\n");
                scanf("%d", &kladjenje);
                if (kladjenje == 1)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 > gol2)
                    {
                        dobitak = uplata * koef1;
                        profit = (uplata * koef1) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[10]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 0)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 == gol2)
                    {
                        dobitak = uplata * koef0;
                        profit = (uplata * koef0) - uplata;
                        printf("Ishod utakmice: Nerijeseno\n");
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 > gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 2)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 < gol2)
                    {
                        dobitak = uplata * koef2;
                        profit = (uplata * koef2) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[11]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
            }
            else if (izbor_utk == 7)
            {
                printf("Odabrali ste utakmicu: %s vs %s\n", klub[12], klub[13]);
                printf("\n");
                printf("Kladite se prema sljedecim oznakama:\n");
                printf("Pobjeda domaćina - 1\n");
                printf("Neriješen rezultat - 0\n");
                printf("Pobjeda gosta - 2\n");
                printf("\n");
                printf("Koeficijenti:\n");
                if (tim[12] < tim[13])
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
                else if (tim[13] < tim[12])
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
                printf("1\t%s: %.2f\n", klub[12], koef1);
                printf("0\tIzjednaceno/nerjeseno: %.2f\n", koef0);
                printf("2\t%s: %.2f\n\n", klub[13], koef2);
                printf("Odaberite na sto se kladite pomocu prethodnih oznaka.\n");
                scanf("%d", &kladjenje);
                if (kladjenje == 1)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 > gol2)
                    {
                        dobitak = uplata * koef1;
                        profit = (uplata * koef1) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[12]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 0)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 == gol2)
                    {
                        dobitak = uplata * koef0;
                        profit = (uplata * koef0) - uplata;
                        printf("Ishod utakmice: Nerijeseno\n");
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 > gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 2)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 < gol2)
                    {
                        dobitak = uplata * koef2;
                        profit = (uplata * koef2) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[13]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
            }
            else if (izbor_utk == 8)
            {
                printf("Odabrali ste utakmicu: %s vs %s\n", klub[14], klub[15]);
                printf("\n");
                printf("Kladite se prema sljedecim oznakama:\n");
                printf("Pobjeda domaćina - 1\n");
                printf("Neriješen rezultat - 0\n");
                printf("Pobjeda gosta - 2\n");
                printf("\n");
                printf("Koeficijenti:\n");
                if (tim[14] < tim[15])
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
                else if (tim[15] < tim[14])
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
                printf("1\t%s: %.2f\n", klub[14], koef1);
                printf("0\tIzjednaceno/nerjeseno: %.2f\n", koef0);
                printf("2\t%s: %.2f\n\n", klub[15], koef2);
                printf("Odaberite na sto se kladite pomocu prethodnih oznaka.\n");
                scanf("%d", &kladjenje);
                if (kladjenje == 1)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 > gol2)
                    {
                        dobitak = uplata * koef1;
                        profit = (uplata * koef1) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[14]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 0)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 == gol2)
                    {
                        dobitak = uplata * koef0;
                        profit = (uplata * koef0) - uplata;
                        printf("Ishod utakmice: Nerijeseno\n");
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 > gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 2)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 < gol2)
                    {
                        dobitak = uplata * koef2;
                        profit = (uplata * koef2) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[15]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
            }
            else if (izbor_utk == 9)
            {
                printf("Odabrali ste utakmicu: %s vs %s\n", klub[16], klub[17]);
                printf("\n");
                printf("Kladite se prema sljedecim oznakama:\n");
                printf("Pobjeda domaćina - 1\n");
                printf("Neriješen rezultat - 0\n");
                printf("Pobjeda gosta - 2\n");
                printf("\n");
                printf("Koeficijenti:\n");
                if (tim[16] < tim[17])
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
                else if (tim[17] < tim[16])
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
                printf("1\t%s: %.2f\n", klub[16], koef1);
                printf("0\tIzjednaceno/nerjeseno: %.2f\n", koef0);
                printf("2\t%s: %.2f\n\n", klub[17], koef2);
                printf("Odaberite na sto se kladite pomocu prethodnih oznaka.\n");
                scanf("%d", &kladjenje);
                if (kladjenje == 1)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 > gol2)
                    {
                        dobitak = uplata * koef1;
                        profit = (uplata * koef1) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[16]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 0)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 == gol2)
                    {
                        dobitak = uplata * koef0;
                        profit = (uplata * koef0) - uplata;
                        printf("Ishod utakmice: Nerijeseno\n");
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 > gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 2)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 < gol2)
                    {
                        dobitak = uplata * koef2;
                        profit = (uplata * koef2) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[17]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
            }
            else if (izbor_utk == 10)
            {
                printf("Odabrali ste utakmicu: %s vs %s\n", klub[18], klub[19]);
                printf("\n");
                printf("Kladite se prema sljedecim oznakama:\n");
                printf("Pobjeda domaćina - 1\n");
                printf("Neriješen rezultat - 0\n");
                printf("Pobjeda gosta - 2\n");
                printf("\n");
                printf("Koeficijenti:\n");
                if (tim[18] < tim[19])
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
                else if (tim[19] < tim[18])
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
                printf("1\t%s: %.2f\n", klub[18], koef1);
                printf("0\tIzjednaceno/nerjeseno: %.2f\n", koef0);
                printf("2\t%s: %.2f\n\n", klub[19], koef2);
                printf("Odaberite na sto se kladite pomocu prethodnih oznaka.\n");
                scanf("%d", &kladjenje);
                if (kladjenje == 1)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 > gol2)
                    {
                        dobitak = uplata * koef1;
                        profit = (uplata * koef1) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[18]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 0)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 == gol2)
                    {
                        dobitak = uplata * koef0;
                        profit = (uplata * koef0) - uplata;
                        printf("Ishod utakmice: Nerijeseno\n");
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 > gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 2)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 < gol2)
                    {
                        dobitak = uplata * koef2;
                        profit = (uplata * koef2) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[19]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
            }
            else
            {
                printf("Unesite važeći broj.\n");
            }
            break;
        }
    }
    else if (izbor == 6)
    {
        printf("\n");
        printf("Trenutna tablica:\n"); // printanje live tablice
        printf("Bundesliga 2022/23\n");
        char momcadi[20][30] = {"Paris Saint-Germain   ", "Lens                  ",
                                "Olympique de Marseille", "Stade Rennais         ",
                                "Lille                  ", "AS Monaco             ",
                                "Olympique Lyonnais    ", "Clermont Foot        ",
                                "Nice                  ", "Lorient               ",
                                "Stade de Reims        ", "Montpellier           ",
                                "Toulouse              ", "Stade Brestois        ",
                                "Strasbourg            ", "Nantes                ",
                                "Auxerre               ", "Ajaccio               ",
                                "Troyes                ", "Angers               "};
        int bodovi[20] = {85, 84, 73, 68, 67, 65, 62, 59, 58, 55,
                          51, 50, 48, 44, 40, 36, 35, 26, 24, 18};
        for (int i = 0; i < 20; i++)
            printf("%d.\t%s\t%d\n", i + 1, momcadi[i], bodovi[i]);
        printf("\n");
        printf("\n");
        printf("Utakmice ovog kola:\n");
#define br_timova 21
        char timovi[br_timova][23] = {"Paris Saint-Germain",
                                      "Lens",
                                      "Olympique de Marseille",
                                      "Lille",
                                      "Stade Rennais",
                                      "AS Monaco",
                                      "Olympique Lyonnais",
                                      "Clermont Foot",
                                      "Nice",
                                      "Lorient",
                                      "Stade de Reims",
                                      "Montpellier",
                                      "Toulouse",
                                      "Stade Brestois",
                                      "Strasbourg",
                                      "Auxerre",
                                      "Nantes",
                                      "Troyes",
                                      "Ajaccio",
                                      "Angers",
                                      ""};
        char klub[br_timova][23];
        srand(time(NULL));
        int tim1, tim2, brojac = 0, tim[20];
        for (int i = 0; i < 10; i++)
        {
            printf("%d.\t", i + 1);
            tim1 = rand() % br_timova;
            for (int j = 0; j < 200; j++)
                if (strcmp(timovi[tim1], "") == 0)
                    tim1 = rand() % br_timova;
            strcpy(klub[brojac], timovi[tim1]);
            tim[brojac] = tim1;
            brojac++;
            printf("%s\t", timovi[tim1]);
            strcpy(timovi[tim1], timovi[20]);
            printf("vs\t");
            tim2 = rand() % br_timova;
            for (int j = 0; j < 200; j++)
                if (strcmp(timovi[tim2], "") == 0)
                    tim2 = rand() % br_timova;
            strcpy(klub[brojac], timovi[tim2]);
            tim[brojac] = tim2;
            brojac++;
            printf("%s", timovi[tim2]);
            strcpy(timovi[tim2], timovi[20]);
            printf("\n");
        }
        int izbor_utk, kladjenje, gol1, gol2;
        double koef1, koef0, koef2, koef_1, koef__1, koef_2, koef__2, uplata,
            dobitak, profit;
        while (1)
        {
            printf("\n");
            printf("Molimo unesite redni broj utakmice na koju se želite kladiti.\n");
            scanf("%d", &izbor_utk);
            if (izbor_utk == 1)
            {
                printf("Odabrali ste utakmicu: %s vs %s\n", klub[0], klub[1]);
                printf("\n");
                printf("Kladite se prema sljedecim oznakama:\n");
                printf("Pobjeda domaćina - 1\n");
                printf("Neriješen rezultat - 0\n");
                printf("Pobjeda gosta - 2\n");
                printf("\n");
                printf("Koeficijenti:\n");
                if (tim[0] < tim[1])
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
                printf("1\t%s: %.2f\n", klub[0], koef1);
                printf("0\tIzjednaceno/nerjeseno: %.2f\n", koef0);
                printf("2\t%s: %.2f\n\n", klub[1], koef2);
                printf("Odaberite na sto se kladite pomocu prethodnih oznaka.\n");
                scanf("%d", &kladjenje);
                if (kladjenje == 1)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 > gol2)
                    {
                        dobitak = uplata * koef1;
                        profit = (uplata * koef1) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[0]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 0)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 == gol2)
                    {
                        dobitak = uplata * koef0;
                        profit = (uplata * koef0) - uplata;
                        printf("Ishod utakmice: Nerijeseno\n");
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 < gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 2)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 < gol2)
                    {
                        dobitak = uplata * koef2;
                        profit = (uplata * koef2) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[1]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
            }
            else if (izbor_utk == 2)
            {
                printf("Odabrali ste utakmicu: %s vs %s\n", klub[2], klub[3]);
                printf("\n");
                printf("Kladite se prema sljedecim oznakama:\n");
                printf("Pobjeda domaćina - 1\n");
                printf("Neriješen rezultat - 0\n");
                printf("Pobjeda gosta - 2\n");
                printf("\n");
                printf("Koeficijenti:\n");
                if (tim[2] < tim[3])
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
                else if (tim[3] < tim[2])
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
                printf("1\t%s: %.2f\n", klub[2], koef1);
                printf("0\tIzjednaceno/nerjeseno: %.2f\n", koef0);
                printf("2\t%s: %.2f\n\n", klub[3], koef2);
                printf("Odaberite na sto se kladite pomocu prethodnih oznaka.\n");
                scanf("%d", &kladjenje);
                if (kladjenje == 1)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 > gol2)
                    {
                        dobitak = uplata * koef1;
                        profit = (uplata * koef1) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[2]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 0)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 == gol2)
                    {
                        dobitak = uplata * koef0;
                        profit = (uplata * koef0) - uplata;
                        printf("Ishod utakmice: Nerijeseno\n");
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 < gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 2)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 < gol2)
                    {
                        dobitak = uplata * koef2;
                        profit = (uplata * koef2) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[3]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
            }
            else if (izbor_utk == 3)
            {
                printf("Odabrali ste utakmicu: %s vs %s\n", klub[4], klub[5]);
                printf("\n");
                printf("Kladite se prema sljedecim oznakama:\n");
                printf("Pobjeda domaćina - 1\n");
                printf("Neriješen rezultat - 0\n");
                printf("Pobjeda gosta - 2\n");
                printf("\n");
                printf("Koeficijenti:\n");
                if (tim[4] < tim[5])
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
                else if (tim[5] < tim[4])
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
                printf("1\t%s: %.2f\n", klub[4], koef1);
                printf("0\tIzjednaceno/nerjeseno: %.2f\n", koef0);
                printf("2\t%s: %.2f\n\n", klub[5], koef2);
                printf("Odaberite na sto se kladite pomocu prethodnih oznaka.\n");
                scanf("%d", &kladjenje);
                if (kladjenje == 1)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 > gol2)
                    {
                        dobitak = uplata * koef1;
                        profit = (uplata * koef1) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[4]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 0)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 == gol2)
                    {
                        dobitak = uplata * koef0;
                        profit = (uplata * koef0) - uplata;
                        printf("Ishod utakmice: Nerijeseno\n");
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 < gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 2)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 < gol2)
                    {
                        dobitak = uplata * koef2;
                        profit = (uplata * koef2) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[5]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
            }
            else if (izbor_utk == 4)
            {
                printf("Odabrali ste utakmicu: %s vs %s\n", klub[6], klub[7]);
                printf("\n");
                printf("Kladite se prema sljedecim oznakama:\n");
                printf("Pobjeda domaćina - 1\n");
                printf("Neriješen rezultat - 0\n");
                printf("Pobjeda gosta - 2\n");
                printf("\n");
                printf("Koeficijenti:\n");
                if (tim[6] < tim[7])
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
                else if (tim[7] < tim[6])
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
                printf("1\t%s: %.2f\n", klub[6], koef1);
                printf("0\tIzjednaceno/nerjeseno: %.2f\n", koef0);
                printf("2\t%s: %.2f\n\n", klub[7], koef2);
                printf("Odaberite na sto se kladite pomocu prethodnih oznaka.\n");
                scanf("%d", &kladjenje);
                if (kladjenje == 1)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 > gol2)
                    {
                        dobitak = uplata * koef1;
                        profit = (uplata * koef1) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[6]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 0)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 == gol2)
                    {
                        dobitak = uplata * koef0;
                        profit = (uplata * koef0) - uplata;
                        printf("Ishod utakmice: Nerijeseno\n");
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 < gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 2)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 < gol2)
                    {
                        dobitak = uplata * koef2;
                        profit = (uplata * koef2) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[7]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
            }
            else if (izbor_utk == 5)
            {
                printf("Odabrali ste utakmicu: %s vs %s\n", klub[8], klub[9]);
                printf("\n");
                printf("Kladite se prema sljedecim oznakama:\n");
                printf("Pobjeda domaćina - 1\n");
                printf("Neriješen rezultat - 0\n");
                printf("Pobjeda gosta - 2\n");
                printf("\n");
                printf("Koeficijenti:\n");
                if (tim[8] < tim[9])
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
                else if (tim[9] < tim[8])
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
                printf("1\t%s: %.2f\n", klub[8], koef1);
                printf("0\tIzjednaceno/nerjeseno: %.2f\n", koef0);
                printf("2\t%s: %.2f\n\n", klub[9], koef2);
                printf("Odaberite na sto se kladite pomocu prethodnih oznaka.\n");
                scanf("%d", &kladjenje);
                if (kladjenje == 1)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 > gol2)
                    {
                        dobitak = uplata * koef1;
                        profit = (uplata * koef1) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[8]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 0)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 == gol2)
                    {
                        dobitak = uplata * koef0;
                        profit = (uplata * koef0) - uplata;
                        printf("Ishod utakmice: Nerijeseno\n");
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 > gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 2)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 < gol2)
                    {
                        dobitak = uplata * koef2;
                        profit = (uplata * koef2) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[9]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
            }
            else if (izbor_utk == 6)
            {
                printf("Odabrali ste utakmicu: %s vs %s\n", klub[10], klub[11]);
                printf("\n");
                printf("Kladite se prema sljedecim oznakama:\n");
                printf("Pobjeda domaćina - 1\n");
                printf("Neriješen rezultat - 0\n");
                printf("Pobjeda gosta - 2\n");
                printf("\n");
                printf("Koeficijenti:\n");
                if (tim[10] < tim[11])
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
                else if (tim[11] < tim[10])
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
                printf("1\t%s: %.2f\n", klub[10], koef1);
                printf("0\tIzjednaceno/nerjeseno: %.2f\n", koef0);
                printf("2\t%s: %.2f\n\n", klub[11], koef2);
                printf("Odaberite na sto se kladite pomocu prethodnih oznaka.\n");
                scanf("%d", &kladjenje);
                if (kladjenje == 1)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 > gol2)
                    {
                        dobitak = uplata * koef1;
                        profit = (uplata * koef1) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[10]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 0)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 == gol2)
                    {
                        dobitak = uplata * koef0;
                        profit = (uplata * koef0) - uplata;
                        printf("Ishod utakmice: Nerijeseno\n");
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 > gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 2)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 < gol2)
                    {
                        dobitak = uplata * koef2;
                        profit = (uplata * koef2) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[11]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
            }
            else if (izbor_utk == 7)
            {
                printf("Odabrali ste utakmicu: %s vs %s\n", klub[12], klub[13]);
                printf("\n");
                printf("Kladite se prema sljedecim oznakama:\n");
                printf("Pobjeda domaćina - 1\n");
                printf("Neriješen rezultat - 0\n");
                printf("Pobjeda gosta - 2\n");
                printf("\n");
                printf("Koeficijenti:\n");
                if (tim[12] < tim[13])
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
                else if (tim[13] < tim[12])
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
                printf("1\t%s: %.2f\n", klub[12], koef1);
                printf("0\tIzjednaceno/nerjeseno: %.2f\n", koef0);
                printf("2\t%s: %.2f\n\n", klub[13], koef2);
                printf("Odaberite na sto se kladite pomocu prethodnih oznaka.\n");
                scanf("%d", &kladjenje);
                if (kladjenje == 1)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 > gol2)
                    {
                        dobitak = uplata * koef1;
                        profit = (uplata * koef1) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[12]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 0)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 == gol2)
                    {
                        dobitak = uplata * koef0;
                        profit = (uplata * koef0) - uplata;
                        printf("Ishod utakmice: Nerijeseno\n");
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 > gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 2)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 < gol2)
                    {
                        dobitak = uplata * koef2;
                        profit = (uplata * koef2) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[13]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
            }
            else if (izbor_utk == 8)
            {
                printf("Odabrali ste utakmicu: %s vs %s\n", klub[14], klub[15]);
                printf("\n");
                printf("Kladite se prema sljedecim oznakama:\n");
                printf("Pobjeda domaćina - 1\n");
                printf("Neriješen rezultat - 0\n");
                printf("Pobjeda gosta - 2\n");
                printf("\n");
                printf("Koeficijenti:\n");
                if (tim[14] < tim[15])
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
                else if (tim[15] < tim[14])
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
                printf("1\t%s: %.2f\n", klub[14], koef1);
                printf("0\tIzjednaceno/nerjeseno: %.2f\n", koef0);
                printf("2\t%s: %.2f\n\n", klub[15], koef2);
                printf("Odaberite na sto se kladite pomocu prethodnih oznaka.\n");
                scanf("%d", &kladjenje);
                if (kladjenje == 1)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 > gol2)
                    {
                        dobitak = uplata * koef1;
                        profit = (uplata * koef1) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[14]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 0)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 == gol2)
                    {
                        dobitak = uplata * koef0;
                        profit = (uplata * koef0) - uplata;
                        printf("Ishod utakmice: Nerijeseno\n");
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 > gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 2)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 < gol2)
                    {
                        dobitak = uplata * koef2;
                        profit = (uplata * koef2) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[15]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
            }
            else if (izbor_utk == 9)
            {
                printf("Odabrali ste utakmicu: %s vs %s\n", klub[16], klub[17]);
                printf("\n");
                printf("Kladite se prema sljedecim oznakama:\n");
                printf("Pobjeda domaćina - 1\n");
                printf("Neriješen rezultat - 0\n");
                printf("Pobjeda gosta - 2\n");
                printf("\n");
                printf("Koeficijenti:\n");
                if (tim[16] < tim[17])
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
                else if (tim[17] < tim[16])
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
                printf("1\t%s: %.2f\n", klub[16], koef1);
                printf("0\tIzjednaceno/nerjeseno: %.2f\n", koef0);
                printf("2\t%s: %.2f\n\n", klub[17], koef2);
                printf("Odaberite na sto se kladite pomocu prethodnih oznaka.\n");
                scanf("%d", &kladjenje);
                if (kladjenje == 1)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4 + 1;
                    gol2 = rand() % 4 + 1;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 > gol2)
                    {
                        dobitak = uplata * koef1;
                        profit = (uplata * koef1) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[16]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 0)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 == gol2)
                    {
                        dobitak = uplata * koef0;
                        profit = (uplata * koef0) - uplata;
                        printf("Ishod utakmice: Nerijeseno\n");
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 > gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 2)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 < gol2)
                    {
                        dobitak = uplata * koef2;
                        profit = (uplata * koef2) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[17]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
            }
            else if (izbor_utk == 10)
            {
                printf("Odabrali ste utakmicu: %s vs %s\n", klub[18], klub[19]);
                printf("\n");
                printf("Kladite se prema sljedecim oznakama:\n");
                printf("Pobjeda domaćina - 1\n");
                printf("Neriješen rezultat - 0\n");
                printf("Pobjeda gosta - 2\n");
                printf("\n");
                printf("Koeficijenti:\n");
                if (tim[18] < tim[19])
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
                else if (tim[19] < tim[18])
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
                printf("1\t%s: %.2f\n", klub[18], koef1);
                printf("0\tIzjednaceno/nerjeseno: %.2f\n", koef0);
                printf("2\t%s: %.2f\n\n", klub[19], koef2);
                printf("Odaberite na sto se kladite pomocu prethodnih oznaka.\n");
                scanf("%d", &kladjenje);
                if (kladjenje == 1)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 > gol2)
                    {
                        dobitak = uplata * koef1;
                        profit = (uplata * koef1) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[18]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 0)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 == gol2)
                    {
                        dobitak = uplata * koef0;
                        profit = (uplata * koef0) - uplata;
                        printf("Ishod utakmice: Nerijeseno\n");
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 > gol2 || gol1 < gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
                else if (kladjenje == 2)
                {
                    printf("Koliko uplacujete?\n");
                    scanf("%lf", &uplata);
                    srand(time(NULL));
                    gol1 = rand() % 4;
                    gol2 = rand() % 4;
                    printf("Rezultat: %d:%d\n", gol1, gol2);
                    if (gol1 < gol2)
                    {
                        dobitak = uplata * koef2;
                        profit = (uplata * koef2) - uplata;
                        printf("Ishod utakmice: Pobjeda %s\n", klub[19]);
                        printf("Pogodili ste ishod utakmice.\n");
                        printf("Vas dobitak: %.2f\n", dobitak);
                        printf("Vas profit: %.2f\n", profit);
                    }
                    else if (gol1 == gol2 || gol1 > gol2)
                        printf("Nazalost niste pogodili ishod utakmice.\n");
                }
            }
            else
            {
                printf("Unesite važeći broj.\n");
            }
            break;
        }
    }
    printf("Hvala na klađenju!");
    return 0;
}