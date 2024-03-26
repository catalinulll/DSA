#include "SetIterator.h"
#include "Set.h"
#include <exception>

//Complexity: Theta(1)
SetIterator::SetIterator(const Set& m) : set(m) // Constructorul primeste o referinta la un obiect  de tip Set si initilaizeaza set cu acesta
{
    this->currentPosition = 0;
    while (set.table[currentPosition] == NULL_TELEM && currentPosition < set.m) // Avansam currentPosition pana se gaseste prima valoare valida din tabel
    { // Pentru a ne asigura ca iteratorul incepe de la primul element valid din set
        currentPosition++;
    }
}


//Complexity: Theta(1)
void SetIterator::first()
{ // Reseteaza pozitia iteratorului pentru a incepe de la inceputul multimii
    this->currentPosition = 0;
    while (set.table[currentPosition] == NULL_TELEM && currentPosition < set.m)
    {
        currentPosition++;
    }
}

//Complexity: Theta(1)
void SetIterator::next()
{
    if (!valid()) // Daca iteratorul nu se afla pe o pozitie valida
        throw std::exception();
    currentPosition++; // Daca da mergem mai departe
    while (set.table[currentPosition] == NULL_TELEM && currentPosition < set.m) // Si mergem la urmatoarea valoare valida din set
    {
        currentPosition++;
    }
}
//Preconditii:
//
//set reprezinta o structura de date Set valida si initializata.
//currentPosition este o variabila intreaga valida, reprezentand pozitia curenta in cadrul structurii set.
//NULL_TELEM reprezinta o valoare speciala care indica o pozitie goala in cadrul structurii set.
//
//Postconditii:
//
//Daca apelul functiei nu arunca o exceptie, iteratorul a fost actualizat astfel incat sa indice pozitia anterioara valida din cadrul structurii set, sau in cazul in care nu exista o pozitie anterioara valida, iteratorul a fost mutat intr-o stare invalida.
//Daca apelul functiei arunca o exceptie, starea iteratorului ramane neschimbata.
//Complexity: Theta(1)
void SetIterator::previous()
{
    if (!valid()) // Daca iteratorul nu se afla pe o pozitie valida
        throw std::exception();
    currentPosition--; // Daca da mergem inapoi
    while (currentPosition >= 0 && set.table[currentPosition] == NULL_TELEM) { // Si mergem la valoare valida din set de mai inainte
        currentPosition--;
    }
}

// Pseudocod
//subalgoritm previous(it)
//if not valid(it) than
//        throw exception
//        end if
//        it.currentPosition ← it.currentPosition - 1
//while it.currentPosition >= 0 AND it.set.table[it.currentPosition] == NULL_TELEM
//it.currentPosition ← it.currentPosition - 1
//end while
//end subalgoritm


//Complexity: Theta(1)
TElem SetIterator::getCurrent()
{
    if (!valid()) // Daca iteratorul nu se afla pe o pozitie valida
        throw std::exception();
    return set.table[currentPosition]; // Se returneaza valoarea din tabel de la pozitia curenta
}

//Complexity: Theta(1)
bool SetIterator::valid() const
{ // Verifica daca iteratorul se afla pe o pozitie valida
    if (this->currentPosition < 0 || this->currentPosition >= set.m) // Daca nu e in parametrii
    {
        return false;
    }
    return true;
}

