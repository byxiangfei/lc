#include "../common.h"

string Serialize(TreeNode *root) {
    if (root == nullptr)
        return "#";
    return to_string(root->val) + " " + Serialize(root->left) + " " + Serialize(root->right);
}

TreeNode *deserialize(istringstream &in) {
    string val;
    in >> val;
    if (val == "#")
        return nullptr;
    TreeNode *root = new TreeNode(stoi(val));
    root->left = deserialize(in);
    root->right = deserialize(in);
    return root;
}

TreeNode *Deserialize(string str) {
    istringstream is(str);
    return deserialize(is);
}

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    cout << Serialize(root) << endl;
    TreeNode *newroot = Deserialize(Serialize(root));

    cout << newroot->val << endl;
    cout << newroot->left->val << endl;
    cout << newroot->right->val << endl;
    return 0;
}
