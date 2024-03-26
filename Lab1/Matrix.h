#pragma once

// DO NOT CHANGE THIS PART
typedef int TElem;
#define NULL_TELEM 0

// Define a tuple for storing a matrix element
struct Tuple {
    int row, col;
    TElem val;
};

class Matrix {
private:
    Tuple* elements; // Array of tuples
    int size; // Maximum number of elements
    int currentRows, currentCols; // Current number of rows and columns
public:
// Default constructor
    Matrix();
// Constructor
    Matrix(int nrLines, int nrCols);

// Destructor
    ~Matrix();

// Get the number of rows
    int nrLines() const;

// Get the number of columns
    int nrColumns() const;

// Get the element at a given position
    TElem element(int i, int j) const;

// Set the value of an element at a given position
    TElem modify(int i, int j, TElem e);

// Resize the matrix
    void resize(int nrLines, int nrCols);

};