#include <iostream>
#include <vector>
using namespace std;

class TreeNode {
public:
    TreeNode():val(-1),left(nullptr),right(nullptr){};
    int val;
    TreeNode* left, *right;
};


void helper(TreeNode* root, vector<vector<int>> &res, vector<int> path) {
    if(root == nullptr) {
        return;
    }
    path.push_back(root->val);
    if (root->left == nullptr && root->right == nullptr) {
        res.push_back(path);
        return;
    }
    helper(root->left, res, path);
    helper(root->right, res, path);
}

vector<vector<int>> path(TreeNode* root) {
    vector<vector<int>> res;
    vector<int> path;
    helper(root, res, path);
    return res;
}


int main() {
    TreeNode* root = new TreeNode();
    root->val = 1;
    root->left = new TreeNode();
    root->left->val = 2;
    root->right = new TreeNode();
    root->right->val = 3;

    root->right->right = new TreeNode();
    root->right->right->val = 4;

    auto res = path(root);

    for (auto r : res) {
        for(auto e : r) {
            cout<<e<<" ";
        }
        cout<<endl;
    }

}
