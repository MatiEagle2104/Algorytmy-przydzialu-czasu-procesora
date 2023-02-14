#include <vector>
#include "algorytm.h"
#include "SJF.h"

using namespace std;

vector<algorytm> SJF(algorytm x[100])
{
    int zostalo=100;                        // ile procesow zostalo do obsluzenia
    int przyjscie=0;                        // biezaca sekunda
    int sekunda=0;                          // zmienna przechowujaca ile sekund jeszcze dany proces trwa
    int shortest=0;                         // bufor zawierajacy ktory proces jest najkrotszy

    vector<algorytm>bufor;                  // wektor przechowujacy aktywne procesy
    vector<algorytm>gotowe;                 // wektor przechowujacy zakonczone procesy

    while(zostalo>0)
    {
        for(int i=0; i<100; i++)
        {
            if(przyjscie==x[i].kiedy)       // sprawdzenie ktore procesy w danej sekundzie przyszly
            {
                bufor.push_back(x[i]);
            }
        }
        przyjscie++;

        if (bufor.size()>0)
        {
            if (sekunda==0)                 // sprawdzenie czy jakis proces sie w danej sekundzie wykonuje
            {
                // decyzja ktory proces jest najkrotszy
                sekunda=bufor[0].ile;
                shortest=0;

                for(int i=1; i<bufor.size(); i++)
                {
                    if(bufor[i].ile<sekunda)
                    {
                        sekunda=bufor[i].ile;
                        shortest=i;
                    }
                }
            }

            // aktualizacja danych dla procesow (czas oczekiwania/cyklu przetwarzania)
            for(int i=0; i<bufor.size(); i++)
            {
                bufor[i].oczekiwanie ++;
                bufor[i].wykonanie ++;
            }
            sekunda--;

            // jesli proces zakonczyl swoje wykonywanie - dodanie do wektora zakonczonych procesow, usuniecie z wektora
            // procesow aktywnych i aktualizacja ilosci procesow pozostalych do wykonania
            if (sekunda==0)
            {
                bufor[shortest].oczekiwanie -= bufor[shortest].ile;
                gotowe.push_back(bufor[shortest]);

                zostalo--;
                bufor.erase(bufor.begin()+shortest);
            }
        }
    }

    return gotowe;
}
