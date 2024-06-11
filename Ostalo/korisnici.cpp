#include <iostream>
#include <fstream>
#include <string>
#include <cstring> // Za strncpy

using namespace std;

struct Korisnik
{
    char racun[50];
    char lozinka[50];
    int balance;
};

void unosNovogKorisnika()
{
    string racun, lozinka;
    cout << "Unesite ime racuna: ";
    getline(cin, racun);
    cout << "Unesite lozinku: ";
    getline(cin, lozinka);

    Korisnik noviKorisnik;
    strncpy(noviKorisnik.racun, racun.c_str(), sizeof(noviKorisnik.racun) - 1);
    noviKorisnik.racun[sizeof(noviKorisnik.racun) - 1] = '\0'; // Osiguranje null-terminatora
    strncpy(noviKorisnik.lozinka, lozinka.c_str(), sizeof(noviKorisnik.lozinka) - 1);
    noviKorisnik.lozinka[sizeof(noviKorisnik.lozinka) - 1] = '\0'; // Osiguranje null-terminatora
    noviKorisnik.balance = 10;                                     // Postavljanje početnog balansa na 10€

    fstream korisnici("C:/Users/Mislav/Documents/GitHub/Projekt_2G/Datoteke/korisnici.bin", ios::binary | ios::out | ios::app);
    if (!korisnici)
    {
        cerr << "Greška pri otvaranju datoteke!" << endl;
        return;
    }
    korisnici.write(reinterpret_cast<char *>(&noviKorisnik), sizeof(Korisnik));
    korisnici.close();

    cout << "Novi korisnik uspješno dodan." << endl;
    cout << "Ovo je vaš startni balance: 10€" << endl;
}

bool logIn(Korisnik &ulogiraniKorisnik)
{
    string log_in_racun, log_in_lozinka;
    cout << "Unesite ime racuna: ";
    getline(cin, log_in_racun);
    cout << "Unesite lozinku: ";
    getline(cin, log_in_lozinka);

    fstream korisnici("C:/Users/Mislav/Documents/GitHub/Projekt_2G/Datoteke/korisnici.bin", ios::binary | ios::in);
    if (!korisnici)
    {
        cerr << "Greška pri otvaranju datoteke!" << endl;
        return false;
    }
    Korisnik korisnik;
    while (korisnici.read(reinterpret_cast<char *>(&korisnik), sizeof(Korisnik)))
    {
        if (log_in_racun == korisnik.racun && log_in_lozinka == korisnik.lozinka)
        {
            cout << "Uspješno ste ušli u Vaš račun." << endl;
            ulogiraniKorisnik = korisnik;
            korisnici.close();
            return true;
        }
    }
    korisnici.close();
    cout << "Neispravno korisničko ime ili lozinka." << endl;
    return false;
}

void azurirajBalance(Korisnik &ulogiraniKorisnik, int iznos)
{
    fstream korisnici("C:/Users/Mislav/Documents/GitHub/Projekt_2G/Datoteke/korisnici.bin", ios::binary | ios::in | ios::out);
    if (!korisnici)
    {
        cerr << "Greška pri otvaranju datoteke!" << endl;
        return;
    }
    Korisnik korisnik;
    streampos pos;
    while (korisnici.read(reinterpret_cast<char *>(&korisnik), sizeof(Korisnik)))
    {
        if (strcmp(korisnik.racun, ulogiraniKorisnik.racun) == 0 && strcmp(korisnik.lozinka, ulogiraniKorisnik.lozinka) == 0)
        {
            pos = korisnici.tellg();
            korisnik.balance += iznos;
            korisnici.seekp(pos - sizeof(Korisnik));
            korisnici.write(reinterpret_cast<char *>(&korisnik), sizeof(Korisnik));
            ulogiraniKorisnik.balance = korisnik.balance;
            break;
        }
    }
    korisnici.close();
}

int main()
{
    cout << "LOG IN\t\t+NOVI KORISNIK" << endl;
    int odabir;
    cout << "Ukoliko se želite ulogirati u već postojeći račun unesite broj 1, a ako želite napraviti novi račun unesite broj 2." << endl;
    cin >> odabir;
    cin.ignore(); // Ignoriranje zaostalih znakova iz buffera

    Korisnik ulogiraniKorisnik;

    if (odabir == 1)
    {
        if (logIn(ulogiraniKorisnik))
        {
            cout << "Vaš novi balance je: " << ulogiraniKorisnik.balance << "€" << endl;
        }
    }
    else if (odabir == 2)
    {
        unosNovogKorisnika();
    }

    // Ovdje možete pozivati azurirajBalance() ili druge funkcije prema potrebi

    return 0;
}
