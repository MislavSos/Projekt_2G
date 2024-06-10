#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    cout << "LOG IN\t\t+NOVI KORISNIK" << endl;
    int odabir, brojac = 0, brojacc = 0, brojaccc = 0, balance = 0, flag1 = 2, flag2 = 2;
    string racun, lozinka, ispis_usera, log_in_racun, log_in_lozinka;
    fstream korisnik;
    cout << "Ukoliko se zelite ulogirati u vec postojeci racun unesite broj 1, a ako zelite napraviti novi racun unesite broj 2." << endl;
    cin >> odabir;
    if (odabir == 1)
    {
    unos_korisnik:
        cin.ignore();
        cout << "Unesite ime racuna: ";
        getline(cin, log_in_racun);
        cout << "Unesite lozinku: ";
        getline(cin, log_in_lozinka);
        korisnik.open("korisnik.txt", ios::in);
        while (getline(korisnik, ispis_usera))
        {
            brojac++;
            if (brojac % 2 == 1 && brojac % 3 != 0)
            {
                if (log_in_racun == ispis_usera)
                {
                    cout << ispis_usera << "\t";
                    flag1 = 1;
                }
                else
                    flag1 = 0;
            }
            else if (brojac % 2 == 0)
            {
                if (log_in_lozinka == ispis_usera)
                {
                    flag2 = 1;
                }
                else
                    flag2 = 0;
            }
            if (flag1 == 1 && flag2 == 1)
                break;
            else if (flag1 == 0 || flag2 == 0)
            {
                cout << "Neispravno korisnicko ime ili lozinka." << endl;
                brojac = 0;
                goto unos_korisnik;
            }
        }
        korisnik.close();
    }
    if (odabir == 2)
    {
        cin.ignore();
        cout << "Unesite ime racuna: ";
        getline(cin, racun);
        cout << "Unesite lozinku: ";
        getline(cin, lozinka);
        korisnik.open("korisnik.txt", ios::out | ios::app);
        korisnik << racun << endl
                 << lozinka << endl;
        korisnik.close();
    }
    /*fstream balansi("C:/Users/Mislav/Documents/GitHub/Projekt_2G/Datoteke/balansi.bin", ios::binary | ios::out | ios::app);
    balansi.write((char *)&balance, sizeof(balance));
    balansi.close();*/
    /*fstream balansi1("C:/Users/Mislav/Documents/GitHub/Projekt_2G/Datoteke/balansi.bin", ios::binary | ios::in);
    while (balansi1.read((char *)&balance, sizeof(balance)))
    {
        brojacc++;
        if(brojac/2==brojacc)
        {
            cout << "Balance: " <<balance << endl;
            break;
        }
    }
    balansi1.close();
    fstream balansi2("C:/Users/Mislav/Documents/GitHub/Projekt_2G/Datoteke/balansi.bin", ios::binary | ios::out | ios::app);
    while(balansi2.write((char *)&balance, sizeof(balance)))
    {
        brojaccc++;
        if (brojaccc == brojacc)
        {
            balance += 5;
            balansi1 << balance;
            break;
        }
    }
    balansi2.close();*/
    ofstream balansi("balansi.bin", ios::binary | ios::trunc);
    balansi.close();
    return 0;
}