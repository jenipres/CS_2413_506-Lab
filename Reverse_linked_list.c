#include <stdlib.h>  // For malloc and free

// Function to reverse a linked list
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;  // Pointer to the previous node (initially NULL)
    struct ListNode* current = head;  // Pointer to the current node

    while (current != NULL) {
        struct ListNode* nextTemp = current->next; // Store the next node
        current->next = prev;  // Reverse the link
        prev = current;  // Move prev to current
        current = nextTemp;  // Move to the next node
    }
    
    return prev; // New head of the reversed list
}
