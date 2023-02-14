#include <vector>
#include "algorytm.h"
#include "statystyka.h"

using namespace std;

vector<float>statystyka (vector<algorytm>x)
{
    vector<float>staty;                 // wektor przechowujacy dane dot. czasow oczekiwania i wykonania
    staty.push_back(0);
    staty.push_back(0);

    // obliczanie sredniej
    for(int i=0; i<100; i++)
    {
        staty[0] += x[i].oczekiwanie;
        staty[1] += x[i].wykonanie;
    }

    staty[0] = staty[0] / 100;
    staty[1] = staty[1] / 100;

    return staty;
}
