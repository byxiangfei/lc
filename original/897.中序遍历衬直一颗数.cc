#include "common.h"

/*
       4
    2    5
  1  3
----------------
     4
  1     5
    2
      3
*/

TreeNode* increasingBST(TreeNode* root, TreeNode* tail = NULL) {
     if (!root) return tail;
     TreeNode* res = increasingBST(root->left, root);
     root->left = NULL;
     root->right = increasingBST(root->right, tail);
     return res;
 }


TreeNode* increasingBST(TreeNode* root) {
    if (!root) return root;
    root->right = increasingBST(root->right);
    root->left = increasingBST(root->left);

    if (root->left) {
        TreeNode* newRoot = root->left;
        TreeNode* cur = root->left;
        while (cur->right)
            cur = cur->right;
        cur->right = root;
        root->left = nullptr;
        return newRoot;
    }
    return root;
}
