#include "Set.h"
#include "SetIterator.h"
#include <iostream>

// Complexity: Theta(1)
int Set::hashFunction(TElem elem) const
{
    return abs(elem % m); // Calculam (elem % m) pentru a distribui elementele in mod egal si folosim abs pentru a ne asigura ca pozitia e pozitiva
}

// Complexity: Theta(n)
void Set::resize()
{
    // Salvam valorile vechi
    int old_m = m; // dimensiune
    int* oldTable = table; // tabel
    int* oldNext = next; // vectorul next

    // Cream valori noi
    m *= 2; // Dublam dimenisunea multimii
    table = new int[m]; // Se aloca un tabel nou cu noua dimeniunea
    next = new int[m]; // Se aloca un vector next nou cu noua dimeniune
    for (int i = 0; i < m; ++i) // Se parcurg toate elementele din noile tabele
    {
        table[i] = NULL_TELEM; // Le initilizam cu NULL
        next[i] = -1; // si -1
    }

    // Rehashuim toate elementele din vechiul tabel in noile tabele
    length = 0;
    for (int i = 0; i < old_m; ++i)
    {
        if (oldTable[i] != NULL_TELEM)
            add(oldTable[i]);
    }

    // Stergem vechile tabele si se elibereaza memoria
    delete[] oldTable;
    delete[] oldNext;
}

// Complexity: Theta(n)
void Set::resizeDown()
{
    // Nu se face resize daca dimensiunea e mai mica decat 5
    if (m < 5)
        return;
    // Salvam valorile vechi
    int old_m = m; // dimensiune
    int* oldTable = table; // tabel
    int* oldNext = next; // vectorul next

    // Cream valori noi
    m /= 2; // Dimensiunea se reduce la jumatate
    table = new int[m]; // Se aloca un tabel nou cu noua dimeniunea
    next = new int[m]; // Se aloca un vector next nou cu noua dimeniune
    for (int i = 0; i < m; i++) // Se parcurg toate elementele din noile tabele
    {
        table[i] = NULL_TELEM; // Le initilizam cu NULL
        next[i] = -1; // si -1
    }

    // Rehashuim toate elementele din vechiul tabel in noile tabele
    length = 0;
    for (int i = 0; i < old_m; i++)
    {
        if (oldTable[i] != NULL_TELEM)
            add(oldTable[i]);
    }

    // Stergem vechile tabele si se elibereaza memoria
    delete[] oldTable;
    delete[] oldNext;
}

// Complexity: Theta(1)
Set::Set() { // Constructor
    this->length = 0; // lungimea multimii
    this->m = 5; // dimeniunea
    this->table = new int [m]; // Se aloca memorie pentru tabel
    this->next = new int [m]; // Se aloca memorie pentru vectorul next
    for (int i = 0; i < this->m; i++) // Se parcurg toate elementele din noile tabele
    {
        table[i] = NULL_TELEM; // Le initilizam cu NULL
        next[i] = -1; // si -1
    }

}

// Worst case: Theta(n), Best Case: Theta(1), Average case: Theta(n)
bool Set::add(TElem elem) {
    // Daca s-a atins 80% din capacitate ii dam resize
    if (length*10 / m > 8)
    {
        this->resize();
    }
    int hashedPosition = hashFunction(elem); // Calculam pozitia hash pentru elementul dat
    if (table[hashedPosition] == NULL_TELEM) // Daca pozitia din tabel e libera
    {
        table[hashedPosition] = elem; // Se adauga elementul la acea pozitie
        next[hashedPosition] = -1; // Se actualizeaza next cu -1
        length++;
        return true;
    }
    // Daca nu e libera se parcurg toate elementele de pe acea pozitie pana la ultimul
    int currentPosition = hashedPosition;
    int lastPosition;
    while (currentPosition != -1)
    {
        // Daca elementul deja exista returnam false
        if (table[currentPosition] == elem)
        {
            return false;
        }
        lastPosition = currentPosition;
        currentPosition = next[currentPosition];
    }
    // Cautam o pozitie goala
    while (table[currentPosition] != NULL_TELEM)
    {
        currentPosition++;
        // Daca currentPosition ajunge la sfarsitul tabelului revine la inceput
        if (currentPosition == m)
        {
            currentPosition = 0;
        }
    }
    // Adaugam elementul pe pozitia goala
    next[lastPosition] = currentPosition;
    next[currentPosition] = -1;
    table[currentPosition] = elem;
    length++;
    return true;
}

// Worst case: Theta(n), Best Case: Theta(1), Average case: Theta(n)
bool Set::remove(TElem elem)
{
    int hashedPosition = hashFunction(elem); // Calculam pozitia hash pentru elementul dat
    if (table[hashedPosition] == NULL_TELEM) // Daca pozitia e libera(elementul nu e in set)
    {
        return false;
    }
    // Daca nu e libera se parcurg toate elementele de pe acea pozitie pana la ultimul
    int currentPosition = hashedPosition;
    int lastPosition;
    while (currentPosition != -1)
    {
        // Daca elementul s-a gasit
        if (table[currentPosition] == elem)
        {
            // Se verifica daca este ultimul element de pe acea pozitie
            if (next[currentPosition] == -1)
            {
                // Se sterge elementul prin resetarea valorilor
                table[currentPosition] = NULL_TELEM;
                next[currentPosition] = -1;
            }
            else
            {
                int nextElemPosition = next[currentPosition]; // Mutam urmatorul element pe pozitia curenta
                TElem nextElem = table[nextElemPosition];
                // Punem urmatorul element in pozitia curenta
                table[currentPosition] = nextElem;
                next[currentPosition] = next[nextElemPosition];
                // Se sterge elementul urmator
                table[nextElemPosition] = NULL_TELEM;
                next[nextElemPosition] = -1;
            }
            length--;
            return true;
        }
        lastPosition = currentPosition; // Se merge mai departe in loop
        currentPosition = next[currentPosition];
    }
    // Daca elementul nu e in set returnam false
    return false;
}

// Worst case: Theta(n), Best Case: Theta(1), Average case: Theta(n)
bool Set::search(TElem elem) const
{
    int currentPosition = hashFunction(elem); // Calculam pozitia hash pentru elementul dat
    while (currentPosition != -1) // Se parcurg elementele de pe acea pozitie
    {
        if (table[currentPosition] == elem) // Daca elementul este gasit
            return true;
        currentPosition = next[currentPosition];
    }
    return false;
}

// Complexity: Theta(1)
int Set::size() const
{
    return this->length; // Returnam numarul de elemente
}

// Complexity: Theta(1)
bool Set::isEmpty() const
{
    return this->length == 0; // Verificam daca multimea este goala
}

// Complexity: Theta(1)
SetIterator Set::iterator() const {
    return SetIterator(*this); // Se returneaza un iterator cu referinta catre multimea curenta
}

// Complexity: Theta(1)
Set::~Set()
{ // Destructor
    delete[] table;
    delete[] next;
}
// Complexity: Theta(m)
void Set::printSet()
{ // Afiseaza setul
    for (int i = 0; i < m; ++i)
    {
        std::cout << "Index: " << i << "  Elem: " << table[i] << std::endl;
        std::cout << "Next: " << next[i] << std::endl << std::endl;
    }
}


