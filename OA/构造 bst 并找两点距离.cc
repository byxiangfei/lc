/*给定一个数组，要求在不rebalance tree的情况下构造BST（仅交换节点), 然后求两个节点的距离*/
/*思路：构建BST->找两点是否都在BST里->找共同祖先->找各种到祖先的距离然后加起来*/
//https://www.geeksforgeeks.org/shortest-distance-between-two-nodes-in-bst/
//https://blog.csdn.net/pyang1989/article/details/21184229
#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    Node(int v) {val = v; left = nullptr; right = nullptr;} //必须要初始化
    Node* left;
    Node* right;
    int val;

};

//if return is void,* should be *&
Node* insertNode(Node *root, int val) {
    if(root == nullptr) {
        root = new Node(val);
    } else if (root->val > val) {
        root->left = insertNode(root->left, val);
    } else if (root->val < val) {
        root->right = insertNode(root->right, val);
    }
    return root;
}

Node* findNode(Node* root, int val) {
    if(root == nullptr) {
        return nullptr;
    }
    if(root->val == val) {
        return root;
    }
    if(root->val < val) {
        return findNode(root->right, val);
    }
    return findNode(root->left, val);
}

//找最 common的节点
Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
    if(!root || root == p || root == q) return root;
    Node* left = lowestCommonAncestor(root->left, p, q);
    Node* right = lowestCommonAncestor(root->right, p, q);
    if(left && right) return root;
    return left ? left : right;
}

Node* lowestCommonAncestor(Node* root, int p, int q) {
    if(!root || root->val == p || root->val == q) return root;
    Node* left = lowestCommonAncestor(root->left, p, q);
    Node* right = lowestCommonAncestor(root->right, p, q);
    if(left && right) return root;
    return left ? left : right;
}



// 求深度，
int countDepth(Node* root, int target) {
    int count = 0;
    Node* tmp = root;
    while(tmp) {
        if(tmp->val == target) {
            return count;
        }
        if(tmp->val < target) {
            tmp = tmp->right;
        } else {
            tmp = tmp->left;
        }
        count++;
    }
    return -1;
}

// This function returns distance of x from
// root. This function assumes that x exists
// in BST and BST is not NULL.
int distanceFromRoot(Node* root, int x)
{
    if (root->val == x)
        return 0;
    else if (root->val > x)
        return 1 + distanceFromRoot(root->left, x);
    return 1 + distanceFromRoot(root->right, x);
}
/*
       4
    2    7
  1  3
*/

int main() {
    vector<int> a = {4,2,1,3,7};
    Node* root = nullptr;
    for(int i = 0; i < a.size(); i++) {
        root =  insertNode(root, a[i]);
    }
    cout<<root->val<<endl;
    cout<<countDepth(root, 1)<<endl;
    cout<<countDepth(root, 7)<<endl;

    auto l = lowestCommonAncestor(root, 1, 7);
    cout<<l->val<<endl;

    cout<<countDepth(root, l->val)<<endl;
}
