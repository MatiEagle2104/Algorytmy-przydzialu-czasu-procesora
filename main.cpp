#include <iostream>
#include <time.h>
#include <vector>
#include <fstream>

#include "algorytm.h"
#include "FCFS.h"
#include "SJF.h"
#include "statystyka.h"

using namespace std;

int main()
{
    srand(time(NULL));

    // tworzenie i otwarcie plikow do ktorych zapisywane beda dane i wyniki
    ofstream zapis_danych;
    zapis_danych.open("dane.txt", ios::out);
    ofstream zapis_statystyk;
    zapis_statystyk.open("wyniki.txt", ios::out);

    for(int i=0; i<100; i++)                  // testowanie na stu roznych ciagach
    {
        algorytm procesy[100];                // tworzenie ciagu procesow
        // zapis danych do pliku
        zapis_danych << i+1 << ". CIAG - ";
        for(int j=0; j<100; j++)
        {
            zapis_danych << procesy[j].ile << "(" << procesy[j].kiedy << ") ";
        }
        zapis_danych << "\n";

        vector<algorytm>a;          a=FCFS(procesy);            // uruchomienie algorytmu FCFS
        vector<algorytm>b;          b=SJF(procesy);             // uruchomienie algorytmu SJF
        vector<float>c;             c=statystyka(a);            // statystyki dla algorytmu FCFS
        vector<float>d;             d=statystyka(b);            // statystyki dla algorytmu SJF

        // zapis statystyk do pliku
        zapis_statystyk << i+1 << ". " << c[1] << " " << c[0] << " - " << d[1] << " " << d[0] << "\n";
    }

    // zamkniecie plikow do ktorych zapisywano dane i wyniki
    zapis_danych.close();
    zapis_statystyk.close();

    cout << "Wykonano symulacje!" << endl;              // komunikat na ekranie o zakonczeniu symulacji

    return 0;
}
