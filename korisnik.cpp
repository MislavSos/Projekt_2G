#include <iostream>
#include<fstream>
#include <string>
using namespace std;

int main()
{
    cout << "+NOVI KORISNIK\t\tLOG IN" << endl;
    int odabir;
    fstream korisnik;
    string unos_korisnika, ispis_datoteke;
    cout << "Ukoliko zelite napraviti novi racun unesite broj 1, a ako se zelite ulogirati u vec postojeci racun unesite broj 2."<<endl;
    cin >> odabir;
    if(odabir == 1)
    {
        korisnik.open("korisnik.txt");
        while (getline(korisnik, ispis_datoteke))
        {
            cout << ispis_datoteke << endl;
        }
        korisnik.close();
        korisnik.open("korisnik.txt", ios::app);
        cout << "Unesite ime racuna: ";
        getline(cin, unos_korisnika);
        cin.ignore();
        korisnik << unos_korisnika;
        korisnik.close();
    }
    if(odabir == 2)
    {

    }
    return 0;
}