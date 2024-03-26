#include "Iterator.h"
//Complexity: Theta(1)
// Constructor for the Iterator class
// The constructor takes a reference to a Matrix object and initializes the current position to the start of the matrix (0,0)
Iterator::Iterator(const Matrix& matrix): matrix(matrix) {
    i = j = 0; // Initialize i and j to 0
}

//Complexity: Theta(1)
// Move the current position to the beginning of the matrix (0,0)
void Iterator::first() {
    i = j = 0;
}

//Complexity: Theta(1)
// Move the current position to the start of the next row
// If there are no more rows, do nothing
void Iterator::nexti() {
    if (i < matrix.nrLines() - 1) {
        i++; // Move to the next row
        j = 0; // Move to the start of the row
    }
}

//Complexity: Theta(1)
// Move the current position to the start of the next column
// If there are no more columns, move to the start of the next row
void Iterator::nextj() {
    if (j < matrix.nrColumns() - 1) {
        j++; // Move to the next column
    }
    else {
        i++; // Move to the start of the next row
        j = 0; // Move to the start of the row
    }
}

//Complexity: Theta(1)
// Check if the current position is valid
// A position is valid if it is within the bounds of the matrix
bool Iterator::valid() const {
    return i < matrix.nrLines() && j < matrix.nrColumns();
}

//Complexity: Theta(1)
// Get the current element at the current position
TElem Iterator::getCurrent() const {
    return matrix.element(i, j);
}
