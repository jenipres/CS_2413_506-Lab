#include <stdbool.h>

// Check if two trees are mirror images
bool z(struct TreeNode* x, struct TreeNode* y) {
    if (x == NULL && y == NULL)
        return true; // both empty
    if (x == NULL || y == NULL)
        return false; // only one is empty
    return (x->val == y->val) // values match
        && z(x->left, y->right) // outer mirror
        && z(x->right, y->left); // inner mirror
}

// Check if tree is symmetric
bool isSymmetric(struct TreeNode* x) {
    if (x == NULL)
        return true; // empty tree is symmetric
    return z(x->left, x->right); // check mirror
}
