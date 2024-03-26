#pragma once
#include "Set.h"

class SetIterator
{
    //DO NOT CHANGE THIS PART
    friend class Set;
private:
    //DO NOT CHANGE THIS PART
    const Set& set; // referinta catre multimea pe care se itereaza
    SetIterator(const Set& s); // constructor

    int currentPosition; // pozitia curenta a iteratorului


public:
    void first(); // plaseaza iteratorul la prima pozitie
    void next(); // plaseaza iteratorul la urmatorul element din multime
    void previous(); // plaseaza iteratorul la elementul anterior din mutime
    TElem getCurrent(); // returneaza elementul curent la care se afla iteratorul in multime
    bool valid() const; // verifica daca iteratorul se afla pe o pozitie valida in multime
};
