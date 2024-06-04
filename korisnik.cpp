#include <iostream>
#include<fstream>
#include <string>
using namespace std;

/*int main()
{
    cout << "+NOVI KORISNIK\t\tLOG IN" << endl;
    int odabir;

    string unos_korisnika, ispis_datoteke;
    cout << "Ukoliko zelite napraviti novi racun unesite broj 1, a ako se zelite ulogirati u vec postojeci racun unesite broj 2."<<endl;
    cin >> odabir;
    if(odabir == 1)
    {
        fstream korisnik;
        korisnik.open("korisnik.txt");
        cout << "Unesite ime racuna: ";
        getline(cin, unos_korisnika);
        cin.ignore();
        korisnik << unos_korisnika;
        korisnik.close();
    }
    if(odabir == 2)
    {
        fstream korisnik;
        korisnik.open("korisnik.txt");
        while(getline(korisnik, ispis_datoteke))
        {
            cout << ispis_datoteke << endl;
        }
        korisnik.close();
    }
    return 0;
}*/

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // Create and open a text file
    ofstream MyFile("filename.txt");

    // Write to the file
    MyFile << "Files can be tricky, but it is fun enough!";

    // Close the file
    MyFile.close();
}