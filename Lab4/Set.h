#pragma once
//DO NOT INCLUDE SETITERATOR

//DO NOT CHANGE THIS PART
#define NULL_TELEM -111111
typedef int TElem;
class SetIterator;

#include "iostream"

class Set {
    //DO NOT CHANGE THIS PART
    friend class SetIterator;

private:
    int* table; // tabel
    int* next; // vectorul next
    int m; // capacitate
    int length; // numarul curent de elemente
    int hashFunction(TElem elem) const;


    void resize();
    void resizeDown();

public:
    // implicit constructor
    Set();

    Set(const Set& other);

    // adauga un element la set
    bool add(TElem e);

    // sterge un element din set
    bool remove(TElem e);

    // verifica daca un element se afla in set sau nu
    bool search(TElem elem) const;

    // returneaza numarul de elemente din set
    int size() const;

    // verifica daca setul este gol
    bool isEmpty() const;

    // returneaza un iterator pentru set
    SetIterator iterator() const;

    // destructor
    ~Set();

    void printSet();

};
