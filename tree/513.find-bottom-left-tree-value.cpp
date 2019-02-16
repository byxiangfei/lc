/*
 * [513] Find Bottom Left Tree Value
 *
 * https://leetcode.com/problems/find-bottom-left-tree-value
 *
 * Medium (55.94%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[2,1,3]'
 *
 *
 * Given a binary tree, find the leftmost value in the last row of the tree.
 *
 *
 * Example 1:
 *
 * Input:
 *
 * ⁠   2
 * ⁠  / \
 * ⁠ 1   3
 *
 * Output:
 * 1
 *
 *
 *
 * ⁠ Example 2:
 *
 * Input:
 *
 * ⁠       1
 * ⁠      / \
 * ⁠     2   3
 * ⁠    /   / \
 * ⁠   4   5   6
 * ⁠      /
 * ⁠     7
 *
 * Output:
 * 7
 *
 *
 *
 * Note:
 * You may assume the tree (i.e., the given root node) is not NULL.
 *
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int height(TreeNode* root) {
        if(!root) return 0;
        return 1 + max(height(root->left), height(root->right));
    }

    int findBottomLeftValue(TreeNode* root) {
        if(!root) return 0;
        int h = height(root);
        queue<TreeNode*> q;
        q.push(root);
        int i = 1;
        while(i<h) {
            int n = q.size();
            for(int x = 0; x < n; x++) {
                TreeNode* node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            i++;
        }
        TreeNode* res = q.front();
        return res->val;
    }
};
