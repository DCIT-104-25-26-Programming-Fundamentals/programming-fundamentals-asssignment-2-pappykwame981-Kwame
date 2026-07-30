// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 9
// =============================================================================
//
// TASK: Console-Based Simple Calculator
//
// Build a calculator program that runs in the console and performs basic
// arithmetic operations based on the user's input.
//
// -----------------------------------------------------------------------------
// OPERATIONS YOUR CALCULATOR MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Addition          ( + )    e.g.  10 + 3  =  13
//   2. Subtraction       ( - )    e.g.  10 - 3  =  7
//   3. Multiplication    ( * )    e.g.  10 * 3  =  30
//   4. Division          ( / )    e.g.  10 / 3  =  3.33
//   5. Modulus           ( % )    e.g.  10 % 3  =  1  (remainder)
//   6. Exponentiation    ( ^ )    e.g.  2 ^ 8   =  256
//   7. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        SIMPLE CALCULATOR
//   ============================
//   1. Addition
//   2. Subtraction
//   3. Multiplication
//   4. Division
//   5. Modulus
//   6. Exponentiation
//   7. Quit
//   Select an operation (1-7):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Select an operation (1-7): 4
//   Enter first number : 10
//   Enter second number: 3
//   Result: 10 / 3 = 3.33
//
//   Select an operation (1-7): 4
//   Enter first number : 5
//   Enter second number: 0
//   Error: Cannot divide by zero.
//
//   Select an operation (1-7): 7
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Each arithmetic operation MUST be written as its own function.
// - Use a loop so the calculator keeps running until the user selects Quit.
// - Division by zero must be caught and handled with a clear error message
//   (do NOT let the program crash).
// - Use fixed and setprecision(2) to display results to 2 decimal places.
// - Handle invalid menu choices gracefully.
// - For exponentiation use a loop or the pow() function from <cmath>.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// =============================================================================
//
// TASK: Console-Based Simple Calculator
//
// =============================================================================

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    // Return NAN as a sentinel; main() checks for divide-by-zero before calling this
    if (b == 0) {
        return NAN;
    }
    return a / b;
}

double modulus(int a, int b) {
    if (b == 0) {
        return NAN;
    }
    return a % b;
}

double power(double base, int exponent) {
    return pow(base, exponent);
}

int main() {
    int choice;

    do {
        cout << "\n============================" << endl;
        cout << "     SIMPLE CALCULATOR" << endl;
        cout << "============================" << endl;
        cout << "1. Addition" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Division" << endl;
        cout << "5. Modulus" << endl;
        cout << "6. Exponentiation" << endl;
        cout << "7. Quit" << endl;
        cout << "Select an operation (1-7): ";
        cin >> choice;

        if (cin.fail()) {
            cout << "Invalid input. Exiting." << endl;
            break;
        }

        if (choice == 7) {
            cout << "Goodbye!" << endl;
            continue;
        }

        if (choice < 1 || choice > 7) {
            cout << "Invalid choice. Please select 1-7." << endl;
            continue;
        }

        double a, b;
        cout << "Enter first number : ";
        cin >> a;
        cout << "Enter second number: ";
        cin >> b;

        cout << fixed << setprecision(2);

        if (choice == 1) {
            cout << "Result: " << a << " + " << b << " = " << add(a, b) << endl;
        } else if (choice == 2) {
            cout << "Result: " << a << " - " << b << " = " << subtract(a, b) << endl;
        } else if (choice == 3) {
            cout << "Result: " << a << " * " << b << " = " << multiply(a, b) << endl;
        } else if (choice == 4) {
            if (b == 0) {
                cout << "Error: Cannot divide by zero." << endl;
            } else {
                cout << "Result: " << a << " / " << b << " = " << divide(a, b) << endl;
            }
        } else if (choice == 5) {
            int ia = static_cast<int>(a);
            int ib = static_cast<int>(b);
            if (ib == 0) {
                cout << "Error: Cannot perform modulus by zero." << endl;
            } else {
                cout << "Result: " << ia << " % " << ib << " = " << modulus(ia, ib) << endl;
            }
        } else if (choice == 6) {
            int exponent = static_cast<int>(b);
            cout << "Result: " << a << " ^ " << exponent << " = " << power(a, exponent) << endl;
        }

    } while (choice != 7);

    return 0;
}
