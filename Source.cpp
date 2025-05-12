/* 
===============================================================
How to use this program:
1. Enter a Reverse Polish Notation expression.
2. The program will calculate the result and display it.
3. Enter "0" to exit the program.
4. The program supports the following operators: +, -, *, /.
===============================================================
Programmer: Vinny Pham
Date: 01/27/2025
===============================================================
*/ 
#include <iostream>
#include <string>
#include <sstream>
#include "Stack.cpp"
using namespace std;

// Function prototypes
void calcResults(string input);

//====main======================================================
//
//==============================================================
int main() {
    // Variables
    string input;
    bool running = true;

    // Get user input
    while(running) {
        cout << "Enter expression: " << endl;
        getline(cin, input);

        // Check if user wants to exit
        if (input == "0") {
            running = false;
        } else {
            // Calculate results
            calcResults(input);
        }
    }


    return 0;
}                     // end of main()
//==============================================================

//====calcResults===============================================
// This function calculates the results of Reverse Polish 
// expressions.
//
// Input:
//      input (string) - The input string
//==============================================================
void calcResults(string input) {
    // Variables
    Stack stack;
    stringstream stream(input);
    string word;
    double num;

    // Loop through the input string
    while (stream >> word) {
        stringstream numCheck(word);

        // Check if the word is a number
        if (numCheck >> num) {
            stack.push(num);

        // Check if the word is an operator
        } else {
            double num1, num2;
            char operatorChar = word[0];

            // Check if the operator is =
            if (operatorChar == '=') {
                double result = stack.pop();

                // Check if there are too many operands
                if (stack.isEmpty()) {
                    cout << "Result: " << result << endl;
                    return;
                } else {
                    cout << "Error: Too many operands" << endl;
                    return;
                }
            }

            num2 = stack.pop();
            num1 = stack.pop();

            // Check if there are too many operators
            if (num1 == -1 || num2 == -1) {
                cout << "Error: Too many operators" << endl;
                return;
            }

            // Perform the operation
            switch (operatorChar) {
                case '+':
                    stack.push(num1 + num2);
                    break;
                case '-':
                    stack.push(num1 - num2);
                    break;
                case '*':
                    stack.push(num1 * num2);
                    break;
                case '/':
                    if (num2 == 0) {
                        cout << "Error: Division by zero" << endl;
                        return;
                    }
                    stack.push(num1 / num2);
                    break;
                default:
                    cout << "Error: Invalid operator" << endl;
                    return;
            }
        }
    }  
}                      // end of calcResults()
//==============================================================

/*
Output:
Enter expression: 
10 15 + =
Result: 25
Enter expression:
10 15 - =
Result: -5
Enter expression:
2.5 3.5 + =
Result: 6
Enter expression:
10 0 / =
Error: Division by zero
Enter expression:
10 20 * / = 
Error: Too many operators
Enter expression:
12 20 30 / = 
Error: Too many operands
Enter expression:
-10 -30 - =
Result: 20
Enter expression:
100 10 50 25 / * - -2 / =
Result: -40
Enter expression:
0
*/