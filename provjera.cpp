#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    int balance = 0;
    fstream balansi("C:/Users/Mislav/Documents/GitHub/Projekt_2G/Datoteke/balansi.bin", ios::binary | ios::out | ios::app);
    balansi.write((char *)&balance, sizeof(balance));
    balansi.close();
    fstream balansi1("C:/Users/Mislav/Documents/GitHub/Projekt_2G/Datoteke/balansi.bin", ios::binary | ios::in);
    while (balansi1.read((char *)&balance, sizeof(balance)))
    {
        balance += 5;
        break;
    }
    balansi1.close();
    fstream balansi2("C:/Users/Mislav/Documents/GitHub/Projekt_2G/Datoteke/balansi.bin", ios::binary | ios::out | ios::app);
    balansi.write((char *)&balance, sizeof(balance));
    balansi2.close();
    fstream balansi3("C:/Users/Mislav/Documents/GitHub/Projekt_2G/Datoteke/balansi.bin", ios::binary | ios::out | ios::app);
    balansi.write((char *)&balance, sizeof(balance));
    cout << balance << endl;
    balansi3.close();
    return 0;
}