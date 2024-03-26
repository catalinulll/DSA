#include <exception>
#include "BagIterator.h"
#include "Bag.h"

using namespace std;

// Constructor
// Complexity: θ(1)
BagIterator::BagIterator(const Bag& c): bag(c) {
    this->currentElement = this->bag.head;
    this->currentFrequency = 1;
}

// First element method
// Puts the iterator on the first element of the DLLA
// Complexity: θ(1)
void BagIterator::first() {
    this->currentElement = this->bag.head;
    this->currentFrequency = 1;
}

// Last element method
// Puts the iterator on the last element of the DLLA
// Complexity: θ(1)
void BagIterator::last() {
    this->currentElement = this->bag.tail;
    this->currentFrequency = bag.nrOccurrences(currentElement);
}

// Next element method
// Goes to the next valid element in the DLLA, throws an exception if the current element is not valid
// Complexity: θ(1),
void BagIterator::next() {
    if(!this->valid()) {
        throw std::exception();
    }
    if (this->currentFrequency < this->bag.nodes[this->currentElement].data.frequency) {
        this->currentFrequency++;
    }
    else {
        this->currentElement = this->bag.nodes[this->currentElement].next;
        this->currentFrequency = 1;
    }
}

// Previous element method
// Goes to the previous valid element in the DLLA, throws an exception if the current element is not valid
// Complexity: θ(1)
void BagIterator::previous() {
    if(!this->valid()) {
        throw std::exception();
    }
    if (this->currentFrequency > this->bag.nodes[this->currentElement].data.frequency) {
        this->currentFrequency--;
    }
    else {
        this->currentElement = this->bag.nodes[this->currentElement].previous;
        this->currentFrequency = bag.nrOccurrences(this->currentElement);
    }
}

// Is valid method
// Returns true if the element is on a valid position, otherwise false
// Complexity: θ(1)
bool BagIterator::valid() const {
    return this->currentElement != -1;
}

// Get current element method
// Returns the current element of the DLLA, if it's not valid throw an exception
// Complexity: θ(1)
TElem BagIterator::getCurrent() const {
    if(!this->valid()) {
        throw std::exception();
    }
    return this->bag.nodes[this->currentElement].data.element;
}
