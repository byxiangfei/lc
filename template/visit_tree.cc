#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

class TreeNode {
public:
	int val;

	TreeNode* left, *right;

	TreeNode(int v): val(v), left(NULL), right(NULL) {};
};


TreeNode* buildTree() {
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->right->right = new TreeNode(4);
	return root;
}

// left, root, right
void pushLeft(stack<TreeNode*> &s, TreeNode* n) {
	while(n != nullptr) {
		s.push(n);
		n = n->left;
	}
}
void pushLeftWithPrint(stack<TreeNode*> &s, TreeNode* n) {
	while(n != nullptr) {
		cout<<n->val<<" ";
		s.push(n);
		n = n->left;
	}
}

void PreOrderIteration_0(TreeNode* root) {
	if(!root) return;
	stack<TreeNode*> s;
	pushLeftWithPrint(s, root);
	while(!s.empty()) {
		auto cur = s.top(); s.pop();
		pushLeftWithPrint(s, cur->right);
	}
	cout<<endl;
	return;
}

void MidOrderIteration_0(TreeNode* root) {
	if(!root) return;
	stack<TreeNode*> s;
	pushLeft(s, root);
	while(!s.empty()) {
		auto cur = s.top();
		s.pop(); cout<<cur->val<<" ";
		pushLeft(s, cur->right);
	}
	cout<<endl;
	return;
}

void PostOrderIteration_0(TreeNode* root) {
	if(!root) return;
	stack<TreeNode*> s;
	pushLeft(s, root);
	TreeNode* pre = NULL;
	while(!s.empty()) {
		TreeNode* cur = s.top();   // must have a new one
		//当right没有，或者right已经visit过了，才visit top
		if (cur->right != nullptr && cur->right != pre) {
			pushLeft(s, cur->right);
			continue;
		}
		s.pop();
		cout<<cur->val<<" ";
		pre = cur;
	}
	cout<<endl;
	return;
}

int main() {
	TreeNode* root = buildTree();
	cout<<"pre  order: "; PreOrderIteration_0(root);
	cout<<"mid  order: "; MidOrderIteration_0(root);
	cout<<"post order: "; PostOrderIteration_0(root);
	return 0;
}
