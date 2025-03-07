#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a structure for a queue node
typedef struct QueueNode {
    int x;               // Data stored in the node
    struct QueueNode* y; // Pointer to the next node in the queue
} QueueNode;

// Define the queue structure
typedef struct {
    QueueNode* z;  // Pointer to the front of the queue
    QueueNode* front; // Pointer to the rear of the queue
} MyQueue;

// Function to create a new queue
MyQueue* myQueueCreate() {
    MyQueue* x = (MyQueue*)malloc(sizeof(MyQueue)); // Allocate memory for the queue
    x->z = NULL;  // Initialize the front pointer to NULL (empty queue)
    x->front = NULL; // Initialize the rear pointer to NULL
    return x; // Return the newly created queue
}

// Function to push an element onto the queue
void myQueuePush(MyQueue* x, int y) {
    QueueNode* z = (QueueNode*)malloc(sizeof(QueueNode)); // Allocate memory for a new node
    z->x = y; // Store the value in the node
    z->y = NULL; // Set the next pointer of the node to NULL

    if (x->z == NULL) { // If the queue is empty
        x->z = z; // The first element becomes both the front and rear of the queue
        x->front = z; // Set the front to the new node
    } else { // If the queue is not empty
        x->front->y = z; // Link the current front's next to the new node
        x->front = z; // Update the front pointer to the new node
    }
}

// Function to pop an element from the queue
int myQueuePop(MyQueue* x) {
    if (x->z == NULL) { // Check if the queue is empty
        return -1; // Return -1 to indicate underflow
    }
    QueueNode* y = x->z; // Store the front node in a temporary variable
    int z = y->x; // Retrieve the value from the front node
    x->z = x->z->y; // Move the front pointer to the next node
    if (x->z == NULL) { // If the queue becomes empty
        x->front = NULL; // Set the rear pointer to NULL
    }
    free(y); // Free the memory of the popped node
    return z; // Return the popped value
}

// Function to get the front element of the queue without popping it
int myQueuePeek(MyQueue* x) {
    if (x->z == NULL) { // Check if the queue is empty
        return -1; // Return -1 if there is no front element
    }
    return x->z->x; // Return the value at the front of the queue
}

// Function to check if the queue is empty
bool myQueueEmpty(MyQueue* x) {
    return x->z == NULL; // Return true if the queue is empty, false otherwise
}

// Function to free the queue memory
void myQueueFree(MyQueue* x) {
    while (x->z != NULL) { // Loop through the queue until it's empty
        myQueuePop(x); // Pop each element to free its memory
    }
    free(x); // Free the memory allocated for the queue structure
}

