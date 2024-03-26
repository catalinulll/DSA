#include "PriorityQueue.h"
#include <stdexcept>

using namespace std;

// constructor de copiere

//Constructorul de copiere ar putea avea următoarele precondiții:
// Obiectul "other" trebuie să fie de tip PriorityQueue.
// Obiectul "other" nu trebuie să fie nullptr.
//Constructorul de copiere ar putea avea următoarele postcondiții:
// Se creează un obiect nou de tip PriorityQueue.
// Obiectul nou are aceeași relație de ordonare ca și obiectul "other".
// Obiectul nou conține toate elementele din obiectul "other".

// (best case): theta(1) - dacă coada "other" este goală.
//(average case): theta(n) - având în vedere că trebuie să parcurgem toate elementele din coada "other" în cele mai multe cazuri.
//(worst case): theta(n) - trebuie să parcurgem toate elementele din coada "other" și să le adăugăm în coada nouă.
PriorityQueue::PriorityQueue(const PriorityQueue& other) : head{nullptr}, relation{other.relation} {
    if (other.head != nullptr) { // check if the other queue is not empty
        Node* currentNode = other.head; // create a pointer to traverse the other queue starting from the head
        while (currentNode != nullptr) { // loop through all nodes in the other queue
            push(currentNode->data.first, currentNode->data.second); // add the element to the new queue
            currentNode = currentNode->next; // advance to the next node
        }
    }
}
//constructor de copiere (other: PriorityQueue)
//    // initializare
//    head = nullptr
//    relation = other.relation
//
//    // verificăm dacă coada "other" nu este goală
//    dacă other.head != nullptr atunci
//        currentNode = other.head
//        // parcurgem coada "other"
//        cât timp currentNode != nullptr facem
//            // adăugăm elementul în coada nouă
//            push(currentNode->data.first, currentNode->data.second)
//            currentNode = currentNode->next
//        sfârșit cât timp
//    sfârșit dacă
//sfârșit constructor de copiere


// metoda care interclaseaza doua cozi de prioritate care au aceeasi prioritate

//Metoda merge ar putea avea următoarele precondiții:
// Obiectul "other" trebuie să fie de tip PriorityQueue.
//Metoda merge ar putea avea următoarele postcondiții:
// Obiectul curent (pe care s-a apelat metoda merge) conține toate elementele din obiectul curent și din obiectul "other".
// Obiectul "other" devine gol (adica nu mai conține niciun element).

//(best case): theta(1) - dacă coada curentă este goală.
//(average case): theta(n) - având în vedere că trebuie să parcurgem toate elementele din coada curentă în cele mai multe cazuri.
//(worst case): theta(n) - trebuie să parcurgem toate elementele din coada curentă pentru a ajunge la penultimul element și apoi să concatenăm coada "other" la coada curentă.
void PriorityQueue::merge(PriorityQueue& other) {
    if (isEmpty()) { // check if the current queue is empty
        head = other.head; // if it is empty, set the head of the current queue to be the head of the other queue
        other.head = nullptr; // set the head of the other queue to nullptr
        return; // exit the function
    }

    Node* currentNode = head; // create a pointer to traverse the current queue starting from the head
    while (currentNode->next != nullptr) { // loop through all nodes in the current queue, except the last one
        currentNode = currentNode->next; // advance to the next node
    }
    currentNode->next = other.head; // set the next node after the last node in the current queue to be the head of the other queue
    other.head = nullptr; // set the head of the other queue to nullptr
}
//merge(other: PriorityQueue)
//    // verificăm dacă coada curentă este goală
//    dacă isEmpty() atunci
//        // setăm head-ul coada curentă să fie head-ul coada "other"
//        head = other.head
//        // setăm head-ul coada "other" să fie nullptr
//        other.head = nullptr
//        return
//    sfârșit dacă
//
//    // parcurgem coada curentă până la penultimul element
//    currentNode = head
//    cât timp currentNode->next != nullptr facem
//        currentNode = currentNode->next
//
//    // concatenăm coada "other" la coada curentă
//    currentNode->next = other.head
//    other.head = nullptr
//sfârșit merge


// implicit constructor
PriorityQueue::PriorityQueue(Relation r) : head{nullptr}, relation{r} {} // constructor for the PriorityQueue class, sets the head to nullptr and the relation to the input r

// pushes an element with priority to the queue
//Best-case complexity: Theta(1)
//Average-case complexity: Theta(n)
//Worst-case complexity: Theta(n)
void PriorityQueue::push(TElem e, TPriority p) {
    Element elem{e, p}; // create a new element with the given element e and priority p
    Node* newNode = new Node{elem}; // allocate memory for a new node with the element

    if (isEmpty()) { // check if the queue is empty
        head = newNode; // set the new node as the head of the queue
        return;
    }

    // handle adding element with highest priority (first)
    if (relation(p, head->data.second)) { // check if the new element has higher priority than the current head of the queue
        newNode->next = head; // set the new node as the new head
        head = newNode; // update the head pointer
        return; // exit the function
    }

    // handle adding element with lowest priority
    Node* currentNode = head; // create a pointer to traverse the queue starting from the head
    while (currentNode->next != nullptr && relation(currentNode->next->data.second, p)) { // loop until the end of the queue or until a node with lower priority is found
        currentNode = currentNode->next; // advance to the next node
    }
    newNode->next = currentNode->next; // set the new node to point to the next node in the queue
    currentNode->next = newNode; // set the previous node to point to the new node
}

// returns the element with the highest priority with respect to the order relation
// throws exception if the queue is empty
//Complexity: Theta(1)
Element PriorityQueue::top() const {
    if (isEmpty()) { // check if the queue is empty
        throw runtime_error{"Queue is empty!"};
    }
    return head->data; // return the data of the head node, which is the element with the highest priority
}

// removes and returns the element with the highest priority
// throws exception if the queue is empty
//Complexity: Theta(1)
Element PriorityQueue::pop() {
    if (isEmpty()) { // check if the queue is empty
        throw runtime_error{"Queue is empty!"};
    }
    Node* nodeToDelete = head; // create a pointer to the node to delete, which is the head
    Element elem = head->data; // copy the data of the head node into elem
    head = head->next; // set the next node in the queue as the new head
    delete nodeToDelete; // free the memory allocated for the node to delete
    return elem; // return the element with the highest priority
}

// checks if the queue is empty
//Complexity: Theta(1)
bool PriorityQueue::isEmpty() const {
    return head == nullptr; // return true if the head is nullptr (queue is empty), false otherwise
}

// destructor
//Complexity: Theta(n)
PriorityQueue::~PriorityQueue() {
    while (!isEmpty()) { // loop until the queue is empty
        Node* nodeToDelete = head; // create a pointer to the node to delete, which is the head
        head = head->next; // set the next node in the queue as the new head
        delete nodeToDelete; // free the memory allocated for the node to delete
    }

}