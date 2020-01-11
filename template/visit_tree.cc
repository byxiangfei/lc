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


// root , left, right
void PreOrderIteration(TreeNode* root) {
	if(!root) return;
	stack<TreeNode*> s;
	TreeNode* cur = root;
	while( cur!= NULL || !s.empty()) {
		if( cur!= NULL ) {
			cout<<cur->val<<" "; //visited
			s.push(cur);
			cur = cur->left;
		} else {            // !s.empty()
			cur = s.top();
			s.pop();
			cur = cur->right;
		}
	}
	cout<<endl;
	return;
}

// left, root, right
void pushLeft(stack<TreeNode*> &s, TreeNode* n) {
	while(n != nullptr) {
		s.push(n);
		n = n->left;
	}
}

void MidOrderIteration_0(TreeNode* root) {
	if(!root) return;
	stack<TreeNode*> s;
	pushLeft(s, root);
	while(!s.empty()) {
		auto cur = s.top(); s.pop();
		cout<<cur->val<<" ";
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
		TreeNode* top = s.top();   // must have a new one
		//当right没有，或者right已经visit过了，才visit top
		if (top->right != nullptr && top->right != pre) {
			pushLeft(s, top->right);
			continue;
		}
		s.pop();
		cout<<top->val<<" ";
		pre = top;
	}
	cout<<endl;
	return;
}


void MidOrderIteration(TreeNode* root) {
	if(!root) return;
	stack<TreeNode*> s;
	TreeNode* cur = root;
	while( cur || !s.empty()) {
		if( cur ) {
			s.push(cur);
			cur = cur->left;
		} else {
			cur = s.top();
			s.pop();
			cout<<cur->val<<" ";
			cur = cur->right;
		}
	}
	cout<<endl;
	return;
}

// left, right, root,  o(n) time & space
// 需要一个pre记录是否visit过
void PostOrderIteration(TreeNode* root) {
	if(!root) return;
	stack<TreeNode*> s;
	TreeNode* cur = root;
	TreeNode* pre = NULL;
	while( cur || !s.empty()) {
		if(cur) {
			s.push(cur);
			cur = cur->left;
		} else {
			TreeNode* top = s.top();   // must have a new one
			//当right没有，或者right已经visit过了，才visit top
			if(top->right == NULL || top->right == pre) {
				s.pop();
				cout<<top->val<<" ";
				pre = top;
			} else {
				cur = top->right;
			}
		}
	}
	cout<<endl;
	return;
}


int main() {
	TreeNode* root = buildTree();
	cout<<"pre  order: "; PreOrderIteration(root);
	cout<<"mid  order: "; MidOrderIteration_0(root);
	cout<<"post order: "; PostOrderIteration_0(root);
	return 0;
}
