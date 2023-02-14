#ifndef ALGORYTM_H_INCLUDED
#define ALGORYTM_H_INCLUDED

class algorytm{
public:
    int ile;                // parametr t - dlugosc trwania procesu
    int kiedy;              // parametr a - okreslenie czas przybycia procesu
    int oczekiwanie;        // czas oczekiwania procesu
    int wykonanie;          // czas cyklu przetwarzania

    // konstruktor i destruktor
    algorytm();
    ~algorytm();

    void dane()const;       // zmienne wypisujaca dane dla obiektu - uzywana w trakcie wykonywania projektu
                            // w celu kontroli nad poprawnoscia kodu
};

#endif // ALGORYTM_H_INCLUDED
