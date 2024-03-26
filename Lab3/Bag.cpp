#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>
using namespace std;

// Constructor
// Complexity: θ(1)
Bag::Bag() {
    capacity = 5;
    nodes = new DLLANode[capacity];
    for(int i = 0; i < capacity - 1; i++)
    {
        nodes[i].next = i + 1;
        nodes[i + 1].previous = i;
    }
    nodes[capacity - 1].next = -1;
    head = -1;
    tail = -1;
    firstEmpty = 0;
    length = 0;
}

// Add method
// Adds an element to the DLLA
// Complexity: Best θ(1), Average θ(n), Worst θ(n)
void Bag::add(TElem elem) {
    if (firstEmpty == -1) {
        resizeUp();
    }

    int currentNode = head;
    while(currentNode != -1 && nodes[currentNode].data.element != elem) {
        currentNode = nodes[currentNode].next;
    }

    if(currentNode != -1) {
        nodes[currentNode].data.frequency++;
    }
    else {
        int newElement = firstEmpty;
        firstEmpty = nodes[firstEmpty].next;
        nodes[newElement].data.element = elem;
        nodes[newElement].data.frequency = 1;
        nodes[newElement].next = head;
        nodes[newElement].previous = -1;

        if (head != -1) {
            nodes[head].previous = newElement;
        }
        else {
            tail = newElement;
        }
        head = newElement;
    }
}

// Remove method
// Returns true if the element is in the DLLA, and deletes it; otherwise returns false
// Complexity: Best θ(1), Average θ(n), Worst θ(n)
bool Bag::remove(TElem elem) {
    int current = head;
    while(current != -1 && nodes[current].data.element != elem) {
        current = nodes[current].next;
    }

    if(current == -1) {
        return false;
    }

    if(nodes[current].data.frequency > 1) {
        nodes[current].data.frequency--;
        return true;
    }

    int prev = nodes[current].previous;
    int next = nodes[current].next;
    if(prev == -1) {
        head = next;
    }
    else {
        nodes[prev].next = next;
    }

    if(next == -1) {
        tail = prev;
    }
    else {
        nodes[next].previous = prev;
    }

    nodes[current].next = firstEmpty;
    firstEmpty = current;
    nodes[current].previous = -1;
    nodes[current].data.element = NULL_TELEM;
    nodes[current].data.frequency = 0;

    if(capacity == firstEmpty) {
        resizeDown();
    }

    return true;
}

// Search method
// Returns true if element was found, false if the element is not in the DLLA
// Complexity: Best θ(1), Average θ(n), Worst θ(n)
bool Bag::search(TElem elem) const {
    for(int i = head; i != -1; i = nodes[i].next) {
        if(nodes[i].data.element == elem) {
            return true;
        }
    }
    return false;
}

// Number of occurrences method
// Returns the number of times an element is found in the DLLA
// Complexity: θ(n)
int Bag::nrOccurrences(TElem elem) const {
    int count = 0;
    for(int i = head; i != -1; i = nodes[i].next) {
        if(nodes[i].data.element == elem) {
            count += nodes[i].data.frequency;
        }
    }
    return count;
}

// Size method
// Returns the size of the DLLA
// Complexity: θ(n)
int Bag::size() const {
    int count = 0;
    int currentNode = head;
    while(currentNode != -1) {
        count += nodes[currentNode].data.frequency;
        currentNode = nodes[currentNode].next;
    }
    return count;
}

// Is empty method
// Checks if the DLLA is empty
// Complexity: θ(1)
bool Bag::isEmpty() const {
    return head == -1;
}

// Iterator method
// Initializes an iterator for the DLLA
// Complexity: θ(1)
BagIterator Bag::iterator() const {
    return BagIterator(*this);
}

// Destructor
// Deallocates the data used by the DLLA
// Complexity: θ(n)
Bag::~Bag() {
    delete[] nodes;
}

// Resize up method
// Doubles the capacity of the DLLA
// Complexity: θ(n)
void Bag::resizeUp() {
    capacity *= 2;
    DLLANode* newNodes = new DLLANode[capacity];
    for(int i = 0; i < capacity / 2; i++) {
        newNodes[i] = nodes[i];
    }
    for(int i = capacity / 2; i < capacity; i++) {
        newNodes[i].next = i + 1;
        newNodes[i].previous = i - 1;
    }
    newNodes[capacity - 1].next = -1;
    newNodes[head].previous = capacity / 2 - 1;
    firstEmpty = capacity / 2;
    delete[] nodes;
    nodes = newNodes;
}

// Resize down method
// Halves the capacity of the DLLA
// Complexity: θ(n)
void Bag::resizeDown() {
    capacity /= 2;
    DLLANode* newNodes = new DLLANode[capacity];
    for(int i = 0; i < capacity; i++) {
        newNodes[i] = nodes[i];
    }
    for(int i = capacity; i < 2 * capacity; i++) {
        newNodes[i].next = firstEmpty;
        firstEmpty = i;
    }
    delete[] nodes;
    nodes = newNodes;
    head = 0;
    tail = capacity - 1;
    nodes[head].previous = -1;
    nodes[tail].next = -1;
}

// Reverse DLLA method
// Reverses the elements of the DLLA so that the first element is last, second is second to last, and so on
// Complexity: θ(n)

// Pseudocode
// subalgorithm reverse(b) is:
// //pre: b is in the set B, b is valid
// //post: the elements of the container are reversed
//
// currentNode <- head
// while currentNode =/= -1 execute
//    temp <- nodes[currentNode].next
//    nodes[currentNode].next <- nodes[currentNode].previous
//    nodes[currentNode].previous <- temp
//    currentNode <- temp
// end-while
// temp <- head
// head <- tail
// tail <- temp
// end-subalgorithm

void Bag::reverse() {
    int currentNode = head;
    while(currentNode != -1) {
        int temp = nodes[currentNode].next;
        nodes[currentNode].next = nodes[currentNode].previous;
        nodes[currentNode].previous = temp;
        currentNode = temp;
    }
    int temp = head;
    head = tail;
    tail = temp;
}
