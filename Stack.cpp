// Stack.cpp - Implementation file
#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

// Node struct
struct Node {
    double data;
    Node* next;

    // Node constructor
    Node(double value) {
        data = value;
        next = nullptr;
    }
};

// Stack class
class Stack {
private:
    Node* top;
public:
    Stack();
    ~Stack();
    void push(double value);
    double pop();
    bool isEmpty();
};

// Stack constructor
Stack::Stack() {
    top = nullptr;
}

// Stack destructor
Stack::~Stack() {
    while (!isEmpty()) {
        pop();
    }
}

//====push======================================================
// This method pushes a value onto the stack.
//
// Input:
//      value (double) - The value to push onto the stack
//==============================================================
void Stack::push(double value) {
    Node* newNode = new Node(value);

    newNode->next = top;
    top = newNode;
}                        // end of push()
//==============================================================

//====pop=======================================================
// This method pops a value off the stack.
//
// Output:
//      double - The value popped off the stack
//==============================================================
double Stack::pop() {
    double num; 

    // Return -1 if the stack is empty
    if (isEmpty()) {
        return -1;

    // Pop the value off the stack
    } else {
        num = top->data;
        Node* temp = top;
        top = top->next;

        delete temp;
        return num;
    }
}                         // end of pop()
//==============================================================

//====isEmpty===================================================
// This method checks if the stack is empty.
//==============================================================
bool Stack::isEmpty() {
    return top == nullptr;
}                      // end of isEmpty()
//==============================================================

#endif