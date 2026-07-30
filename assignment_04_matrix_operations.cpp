// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// PART A — Transpose a Matrix
// PART B — Add Two Matrices
// PART C — Multiply Two Matrices
//
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAXSIZE = 10;

void readMatrix(int mat[MAXSIZE][MAXSIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> mat[i][j];
        }
    }
}

void printMatrix(int mat[MAXSIZE][MAXSIZE], int rows, int cols, string label) {
    cout << "\n" << label << ":" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << mat[i][j];
        }
        cout << endl;
    }
}

void transpose(int mat[MAXSIZE][MAXSIZE], int rows, int cols, int result[MAXSIZE][MAXSIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = mat[i][j];
        }
    }
}

void addMatrices(int a[MAXSIZE][MAXSIZE], int b[MAXSIZE][MAXSIZE], int rows, int cols, int result[MAXSIZE][MAXSIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void multiplyMatrices(int a[MAXSIZE][MAXSIZE], int b[MAXSIZE][MAXSIZE], int rowsA, int colsA, int colsB, int result[MAXSIZE][MAXSIZE]) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            int sum = 0;
            for (int k = 0; k < colsA; k++) {
                sum += a[i][k] * b[k][j];
            }
            result[i][j] = sum;
        }
    }
}

int main() {
    int choice;

    do {
        cout << "\n===== Matrix Operations Menu =====" << endl;
        cout << "1) Transpose a matrix" << endl;
        cout << "2) Add two matrices" << endl;
        cout << "3) Multiply two matrices" << endl;
        cout << "4) Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int rows, cols;
            int mat[MAXSIZE][MAXSIZE], result[MAXSIZE][MAXSIZE];

            cout << "Enter number of rows: ";
            cin >> rows;
            cout << "Enter number of columns: ";
            cin >> cols;

            readMatrix(mat, rows, cols);
            transpose(mat, rows, cols, result);

            printMatrix(mat, rows, cols, "Original Matrix");
            printMatrix(result, cols, rows, "Transposed Matrix");

        } else if (choice == 2) {
            int rows, cols;
            int a[MAXSIZE][MAXSIZE], b[MAXSIZE][MAXSIZE], result[MAXSIZE][MAXSIZE];

            cout << "Enter number of rows: ";
            cin >> rows;
            cout << "Enter number of columns: ";
            cin >> cols;

            cout << "\n-- Matrix A --" << endl;
            readMatrix(a, rows, cols);
            cout << "\n-- Matrix B --" << endl;
            readMatrix(b, rows, cols);

            addMatrices(a, b, rows, cols, result);

            printMatrix(a, rows, cols, "Matrix A");
            printMatrix(b, rows, cols, "Matrix B");
            printMatrix(result, rows, cols, "Sum (A + B)");

        } else if (choice == 3) {
            int rowsA, colsA, rowsB, colsB;
            int a[MAXSIZE][MAXSIZE], b[MAXSIZE][MAXSIZE], result[MAXSIZE][MAXSIZE];

            cout << "Enter rows of Matrix A: ";
            cin >> rowsA;
            cout << "Enter columns of Matrix A: ";
            cin >> colsA;

            cout << "\n-- Matrix A --" << endl;
            readMatrix(a, rowsA, colsA);

            cout << "\nEnter rows of Matrix B: ";
            cin >> rowsB;

            if (rowsB != colsA) {
                cout << "Error: Number of rows in B must equal number of columns in A." << endl;
                continue;
            }

            cout << "Enter columns of Matrix B: ";
            cin >> colsB;

            cout << "\n-- Matrix B --" << endl;
            readMatrix(b, rowsB, colsB);

            multiplyMatrices(a, b, rowsA, colsA, colsB, result);

            printMatrix(a, rowsA, colsA, "Matrix A");
            printMatrix(b, rowsB, colsB, "Matrix B");
            printMatrix(result, rowsA, colsB, "Product (A x B)");

        } else if (choice == 4) {
            cout << "Goodbye!" << endl;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 4);

    return 0;
}
