#include <stdlib.h>  // Include for malloc

// Helper function for recursive in-order traversal
void inorder(struct TreeNode* root, int* x, int* y) {
    if (root == NULL) return;        // Base case: if node is NULL, do nothing
    inorder(root->left, x, y);       // Recursively visit left subtree
    x[(*y)++] = root->val;           // Add current node value to result array and increment index
    inorder(root->right, x, y);      // Recursively visit right subtree
}

// Main function to start in-order traversal
int* inorderTraversal(struct TreeNode* root, int* z) {
    int* x = (int*)malloc(100 * sizeof(int)); // Allocate space for result array (max 100 nodes)
    int y = 0;                                // Initialize index to track position in array
    inorder(root, x, &y);                     // Call helper function to fill the array
    *z = y;                                   // Set return size to number of elements added
    return x;                                 // Return pointer to result array
}
