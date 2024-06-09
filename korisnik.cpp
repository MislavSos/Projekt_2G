#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    cout << "LOG IN\t\t+NOVI KORISNIK" << endl;
    int odabir, brojac=0, balance=0;
    string racun, lozinka, ispis_usera, log_in_racun, log_in_lozinka;
    fstream korisnik;
    cout << "Ukoliko se zelite ulogirati u vec postojeci racun unesite broj 1, a ako zelite napraviti novi racun unesite broj 2." << endl;
    cin >> odabir;
    if (odabir == 1)
    {
        cout << "Unesite ime racuna: ";
        getline(cin, log_in_racun);
        cout << "Unesite lozinku: ";
        getline(cin, log_in_lozinka);
        korisnik.open("korisnik.txt", ios::app);
        while(getline(korisnik, ispis_usera))
        {
            brojac++;
            if (log_in_racun == racun && log_in_lozinka == lozinka)
            {
                cout << ispis_usera << endl;
                break;
            }
        }
        korisnik.close();
    }
    if (odabir == 2)
    {
        korisnik.open("korisnik.txt", ios::app);
        cin.ignore();
        cout << "Unesite ime racuna: ";
        getline(cin, racun);
        cout << "Unesite lozinku: ";
        getline(cin, lozinka);
        korisnik << racun << "\t" << lozinka << balance << endl;
        korisnik.close();
    }
    int profit = 10;
    korisnik.open("korisnik.txt", ios::app);
    balance += profit;
    korisnik.close();
    return 0;
}