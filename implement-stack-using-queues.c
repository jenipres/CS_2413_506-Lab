#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a structure for a stack node
typedef struct StackNode {
    int x;             // Data stored in the node
    struct StackNode* y; // Pointer to the next node in the stack
} StackNode;

// Define the stack structure
typedef struct {
    StackNode* z; // Pointer to the top of the stack
} MyStack;

// Function to create a new stack
MyStack* myStackCreate() {
    MyStack* x = (MyStack*)malloc(sizeof(MyStack)); // Allocate memory for the stack
    x->z = NULL; // Initialize the stack as empty
    return x; // Return the newly created stack
}

// Function to push an element onto the stack
void myStackPush(MyStack* x, int y) {
    StackNode* z = (StackNode*)malloc(sizeof(StackNode)); // Allocate memory for a new node
    z->x = y; // Store the value in the node
    z->y = x->z; // Link the new node to the previous top node
    x->z = z; // Update the top of the stack
}

// Function to pop an element from the stack
int myStackPop(MyStack* x) {
    if (x->z == NULL) { // Check if the stack is empty
        return -1; // Return -1 to indicate underflow
    }
    StackNode* y = x->z; // Store the top node in a temporary variable
    int z = y->x; // Retrieve the value from the top node
    x->z = x->z->y; // Move the top pointer to the next node
    free(y); // Free the memory of the popped node
    return z; // Return the popped value
}

// Function to get the top element of the stack without popping
int myStackTop(MyStack* x) {
    if (x->z == NULL) { // Check if the stack is empty
        return -1; // Return -1 if there is no top element
    }
    return x->z->x; // Return the value at the top of the stack
}

// Function to check if the stack is empty
bool myStackEmpty(MyStack* x) {
    return x->z == NULL; // Return true if the stack is empty, false otherwise
}

// Function to free the stack memory
void myStackFree(MyStack* x) {
    while (x->z != NULL) { // Loop through the stack until it's empty
        myStackPop(x); // Pop each element to free its memory
    }
    free(x); // Free the memory allocated for the stack structure
}
