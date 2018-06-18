/*
 * [637] Average of Levels in Binary Tree
 *
 * https://leetcode.com/problems/average-of-levels-in-binary-tree
 *
 * Easy (55.48%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '[3,9,20,15,7]'
 *
 * Given a non-empty binary tree, return the average value of the nodes on each
 * level in the form of an array.
 * 
 * Example 1:
 * 
 * Input:
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * Output: [3, 14.5, 11]
 * Explanation:
 * The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on
 * level 2 is 11. Hence return [3, 14.5, 11].
 * 
 * 
 * 
 * Note:
 * 
 * The range of node's value is in the range of 32-bit signed integer.
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
struct Info {
    int count;
    double sum;
    Info(int c, double s):count(c), sum(s) {};
};
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
       vector<Info> infos;
       helper(root, infos, 0);
       vector<double> res;
       for(auto info: infos) {
           res.push_back(info.sum/info.count) ;
       }
       return res;
    }
    void helper(TreeNode* root, vector<Info> &infos, int level) {
        if(!root) return;
        if(level == infos.size())
            infos.push_back(Info(1, root->val*1.0));
        else {
            infos[level].sum += root->val;
            infos[level].count++;
        }
        helper(root->left, infos, level+1);
        helper(root->right, infos, level+1);
    }
};
