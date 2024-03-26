#include "Matrix.h"
#include <iostream>

using namespace std;
// Default Constructor
//Complexity: Theta(nrLines * nrCols)
Matrix::Matrix() {
    currentRows = 2;
    currentCols = 2;
    size = currentRows * currentCols;
    elements = new Tuple[size];
    for (int i = 0; i < size; i++) {
        elements[i] = { 0, 0, NULL_TELEM };
    }
}
// Constructor
// Complexity: Theta(nrLines * nrCols)
Matrix::Matrix(int nrLines, int nrCols) {
    if (nrLines <= 0 || nrCols <= 0) {
        throw runtime_error("Invalid matrix size");
    }
    currentRows = nrLines;
    currentCols = nrCols;
    size = currentRows * currentCols;
    elements = new Tuple[size];
    for (int i = 0; i < size; i++) {
        elements[i] = { 0, 0, NULL_TELEM };
    }
}
// Destructor
//Complexity: Theta(nrLines * nrCols)
Matrix::~Matrix() {
    delete[] elements;
}
// Get the number of rows of the matrix
//Complexity: Theta(nrLines)
int Matrix::nrLines() const {
    return currentRows;
}
// Get the number of columns of the matrix
//Complexity: Theta(nrCols)
int Matrix::nrColumns() const {
    return currentCols;
}
// Get the element at the given position
//Complexity: Theta(1)
TElem Matrix::element(int i, int j) const {
    if (i >= currentRows || j >= currentCols || i < 0 || j < 0) {
        throw runtime_error("Invalid position");
    }
    int index = i * currentCols + j;
    if (elements[index].val != NULL_TELEM) {
        return elements[index].val;
    }
    return NULL_TELEM;
}
// Modify the element at the given position
//Complexity: Theta(1)
TElem Matrix::modify(int i, int j, TElem e) {
    if (i >= currentRows || j >= currentCols || i < 0 || j < 0) {
        throw runtime_error("Invalid position");
    }
    int index = i * currentCols + j;
    TElem previous = elements[index].val;
    elements[index].val = e;
    return previous;
}
// Resize the matrix
//Complexity: Theta(nrLines * nrCols)
void Matrix::resize(int nrLines, int nrCols) {
    if (nrLines <= 0 || nrCols <= 0 || nrLines > size || nrCols > size) {
        throw runtime_error("Invalid matrix size");
    }
    Tuple *newElements = new Tuple[nrLines * nrCols];
    for (int i = 0; i < nrLines; i++) {
        for (int j = 0; j < nrCols; j++) {
            if (i < currentRows && j < currentCols) {
                newElements[i * nrCols + j] = elements[i * currentCols + j];
            } else {
                newElements[i * nrCols + j] = {0, 0, NULL_TELEM};
            }
        }
    }
};