#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    cout << "LOG IN\t\t+NOVI KORISNIK" << endl;
    int odabir, brojac=0, brojacc=0, balance=0;
    string racun, lozinka, ispis_usera, log_in_racun, log_in_lozinka;
    fstream korisnik;
    cout << "Ukoliko se zelite ulogirati u vec postojeci racun unesite broj 1, a ako zelite napraviti novi racun unesite broj 2." << endl;
    cin >> odabir;
    if (odabir == 1)
    {
        cin.ignore();
        cout << "Unesite ime racuna: ";
        getline(cin, log_in_racun);
        cout << "Unesite lozinku: ";
        getline(cin, log_in_lozinka);
        korisnik.open("C:/Users/Gb-gama/Documents/GitHub/Projekt_2G/korisnik.txt", ios::in);
        while (getline(korisnik, ispis_usera, '\t'))
        {
            getline(korisnik, racun, '\t');
            getline(korisnik, lozinka, '\n');
            brojac++;
            if (log_in_racun == racun && log_in_lozinka == lozinka)
            {
                cout << "Uspjesno ste usli u vas racun." << endl;
                balance += 10; 
                cout << ispis_usera << endl;
                break;
            }
            /*else
            {
                cout << "Neispravno korisnicko ime ili lozinka."<<endl;
            }*/
        }
        korisnik.close();
    }
    if (odabir == 2)
    {
        korisnik.open("C:/Users/Gb-gama/Documents/GitHub/Projekt_2G/korisnik.txt", ios::out | ios::app);
        cin.ignore();
        cout << "Unesite ime racuna: ";
        getline(cin, racun);
        cout << "Unesite lozinku: ";
        getline(cin, lozinka);
        korisnik << racun << "\t" << lozinka <<"\tBalance: "<< balance << endl;
        korisnik.close();
    }
    /*korisnik.open("C:/Users/Gb-gama/Documents/GitHub/Projekt_2G/korisnik.txt", ios::in);
    while (getline(korisnik, ispis_usera))
    {
        brojacc++;
        if (brojacc==brojac)
        {
            balance += 10;
            cout << ispis_usera << endl;
            break;
        }
    }*/
    return 0;
}