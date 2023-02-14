#include <iostream>
#include <time.h>
#include "algorytm.h"

using namespace std;

algorytm::algorytm()
{
    ile = rand() % 20 + 1;          // t z zakresu 1-20
    kiedy = rand() % 50;            // generowanie kiedy proces przychodzi (zakres 0-50 MS)
    oczekiwanie = 0;
    wykonanie = 0;
}

algorytm::~algorytm(){}

void algorytm::dane()const
{
    cout << "Czas trwania procesu: " << ile << "MS" << endl;
    cout << "Czas pojawienia sie procesu: " << kiedy << "MS" << endl;
    cout << "Czas oczekiwania: " << oczekiwanie << "MS" << endl;
    cout << "Czas wykonania: " << wykonanie << "MS" << endl;
}
