/*
 * [663] Equal Tree Partition
 *
 * https://leetcode.com/problems/equal-tree-partition
 *
 * Medium (37.90%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '[5,10,10,null,null,2,3]'
 *
 * 
 * Given a binary tree with n nodes, your task is to check if it's possible to
 * partition the tree to two trees which have the equal sum of values after
 * removing exactly one edge on the original tree.
 * 
 * 
 * Example 1:
 * 
 * Input:     
 * ⁠   5
 * ⁠  / \
 * ⁠ 10 10
 * ⁠   /  \
 * ⁠  2   3
 * 
 * Output: True
 * Explanation: 
 * ⁠   5
 * ⁠  / 
 * ⁠ 10
 * ⁠     
 * Sum: 15
 * 
 * ⁠  10
 * ⁠ /  \
 * ⁠2    3
 * 
 * Sum: 15
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:     
 * ⁠   1
 * ⁠  / \
 * ⁠ 2  10
 * ⁠   /  \
 * ⁠  2   20
 * 
 * Output: False
 * Explanation: You can't split the tree into two trees with equal sum after
 * removing exactly one edge on the tree.
 * 
 * 
 * 
 * Note:
 * 
 * The range of tree node value is in the range of [-100000, 100000].
 * 1 <= n <= 10000
 * 
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
    //求某个节点开始到所有叶子节点之和
    int sum(TreeNode* root) {
        if(!root) return 0;
        return root->val + sum(root->left) + sum(root->right);
    }
    // 然后便利看看有没有一半的节点
    bool helper(TreeNode* root, int total) {
        if(!root) return false;
        if(total == 2 * sum(root)) return true;
        return helper(root->right, total) || helper(root->left, total);
    }

    bool checkEqualTree(TreeNode* root) {
        if(!root->left && !root->right) return false;  // [0] 的问题
        int total = sum(root);
        return helper(root, total);
    }
    
    // 另一种方法，可以设计一个map，在sum的过程中就把每个节点的sum值存在map里, 然后直接查一下有没有 sum/2 的值
    int getsum(TreeNode* root,  unordered_map<int, int>& map){
        if(!root) return 0;
        int cur = root->val + getsum(root->left, map) + getsum(root->right, map);
        map[cur]++;
        return cur;
    }

    bool checkEqualTree2(TreeNode* root) {
        unordered_map<int, int> map;
        int sum = getsum(root, map);
        if(sum == 0) return map[sum] > 1;  // [0] 的问题
        return sum%2 == 0 && map.count(sum/2);
    }

};
