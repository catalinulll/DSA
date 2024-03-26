#pragma once
#include "Matrix.h"

class Iterator {
private:
    const Matrix& matrix; //referinta constanta la matricea pe care iteratorul o parcurge
    int i, j; //pozitiile actuale ale iteratorului

public:
    Iterator(const Matrix& matrix); //constructorul
    void first(); //muta iteratorul la prima pozitie (0, 0)
    void nexti(); //muta iteratorul la urmatoarea pozitie pe linie
    void nextj(); //muta iteratorul la urmatoarea pozitie pe coloana
    bool valid() const; //verifica daca iteratorul se afla intr-o pozitie valida
    TElem getCurrent() const; //returneaza elementul de pe pozitia curenta
};