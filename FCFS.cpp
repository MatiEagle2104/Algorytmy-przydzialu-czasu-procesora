#include <vector>
#include "algorytm.h"
#include "FCFS.h"

using namespace std;

vector<algorytm>FCFS (algorytm x[100])          // funkcja symulujaca algorytmem First Come First Serve
{
    int zostalo=100;                             // ile procesow zostalo do obsluzenia
    int przyjscie=0;                             // biezaca sekunda
    int sekunda=0;                               // zmienna przechowujaca ile sekund jeszcze dany proces trwa

    vector<algorytm>bufor;                       // wektor przechowujacy aktywne procesy
    vector<algorytm>::iterator it;               // do usuwania elementu wektora
    vector<algorytm>gotowe;                      // wektor przechowujacy zakonczone procesy

    while(zostalo>0)
    {
        for(int i=0; i<100; i++)
        {
            if(przyjscie==x[i].kiedy)             // sprawdzenie ktore procesy w danej sekundzie przyszly
            {
                bufor.push_back(x[i]);
            }
        }
        przyjscie++;

        if (bufor.size()>0)
        {
            if (sekunda==0)                        // sprawdzenie czy jakis proces sie w danej sekundzie wykonuje
            {
                sekunda=bufor[0].ile;
            }

            for(int i=1; i<bufor.size(); i++)
            {
                bufor[i].oczekiwanie ++;            // aktualizacja danych dla procesow (czas oczekiwania/cyklu przetwarzania)
                bufor[i].wykonanie ++;
            }
            sekunda--;

            // jesli proces zakonczyl swoje wykonywanie - dodanie do wektora zakonczonych procesow, usuniecie z wektora
            // procesow aktywnych i aktualizacja ilosci procesow pozostalych do wykonania
            if (sekunda==0)
            {
                bufor[0].wykonanie += bufor[0].ile;
                gotowe.push_back(bufor[0]);

                zostalo--;
                it = bufor.begin();
                bufor.erase(it);
            }
        }
    }

    return gotowe;
}
