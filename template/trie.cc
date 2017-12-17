#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

struct TreeNode {
    bool isWord;
    struct TreeNode* next[26];
    char ch;
    int count;  // easy for deleting
};

TreeNode* NewTreeNode(char ch) {
    TreeNode* node = (TreeNode *)malloc(sizeof(TreeNode));
    node->isWord = false;
    node->ch = ch;
    memset(node->next, 0, sizeof(node->next));
    return node;
}

class TrieManager {
private:
    TreeNode* root_;

public:
    TrieManager(char ch);

    int Search(string word) {
        TreeNode* node = root_;
        for(int i = 0; i < word.size(); i++) {
            node = node->next[word[i] - 'a'];
            if(node == NULL) return 0;
        }
        return node->isWord;
    }
    
    bool Delete(string word) {
        TreeNode* node = root_;
        for(int i = 0; i < word.size(); i++) {
            node = node->next[word[i] - 'a'];
            if(!node) return false;
            if(--node->count == 0) {
                delete[] node;
                return true;
            }
        }
    }

    int Insert(string word) {
        TreeNode* node = root_;
        for(int i = 0; i < word.size(); i++) {
            int id = word[i]-'a';
            if(!node->next[id]) node->next[id] = NewTreeNode(word[i]);  //公用
            node = node->next[id];
            node->count++;
        }
        node->isWord = true;
        return node->count;
    }
};


TrieManager::TrieManager(char ch):root_(NewTreeNode(ch)) {};

int main() {
    TrieManager m(' ');
    cout<<m.Insert("hello")<<endl;
    cout<<m.Insert("he")<<endl;

    cout<<m.Search("he")<<endl;
    cout<<m.Search("h")<<endl;

    cout<<m.Delete("ba")<<endl;
    cout<<m.Delete("he")<<endl;

    return 0;
}
