#include <stdlib.h>  // For malloc

// Helper function for recursive pre-order traversal
void preorder(struct TreeNode* root, int* x, int* y) {
    if (root == NULL) return;        // Base case: if node is NULL, do nothing
    x[(*y)++] = root->val;           // Add current node value to result array and increment index
    preorder(root->left, x, y);      // Recursively visit left subtree
    preorder(root->right, x, y);     // Recursively visit right subtree
}

// Main function to start pre-order traversal
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int* x = (int*)malloc(100 * sizeof(int)); // Allocate space for result array (max 100 nodes)
    int y = 0;                                // Initialize index to track position in array
    preorder(root, x, &y);                    // Call helper function to fill the array
    *returnSize = y;                          // Set return size to number of elements added
    return x;                                 // Return pointer to result array
}
