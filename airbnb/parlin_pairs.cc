/*
Given a list of unique words, find all pairs of distinct indices (i, j) in the given list,
so that the concatenation of the two words, i.e. words[i] + words[j] is a palindrome.

Example 1:

Input: ["abcd","dcba","lls","s","sssll"]
Output: [[0,1],[1,0],[3,2],[2,4]]
Explanation: The palindromes are ["dcbaabcd","abcddcba","slls","llssssll"]
Example 2:

Input: ["bat","tab","cat"]
Output: [[0,1],[1,0]]
Explanation: The palindromes are ["battab","tabbat"]
*/

/*
思路：最暴力的肯定是o(n*n*k)
但如果考虑用Trie数，
*/

class TrieNode {
public:
    int idx;
    vector<int> indices;
    TrieNode* children[26];
    TrieNode() : idx(-1) {
        memset(children, NULL, sizeof(children));
    }
};

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
            add(words[i], i);
        }
        vector<vector<int>> pairs;
        for (int i = 0; i < words.size(); i++) {
            search(words[i], i, pairs);
        }
        return pairs;
    }
private:
    TrieNode* root = new TrieNode();

    void add(string word, int i) {
        TrieNode* node = root;
        for (int j = word.size() - 1; j >= 0; j--) {
            if (isPalindrome(word, 0, j)) {
                node -> indices.push_back(i);
            }
            if (!node -> children[word[j] - 'a']) {
                node -> children[word[j] - 'a'] = new TrieNode();
            }
            node = node -> children[word[j] - 'a'];
        }
        node -> idx = i;
        node -> indices.push_back(i);
    }

    void search(string word, int i, vector<vector<int>>& pairs) {
        TrieNode* node = root;
        int n = word.size();
        for (int j = 0; j < n && node; j++) {
            if (node -> idx >= 0 && node -> idx != i && isPalindrome(word, j, n - 1)) {
                pairs.push_back({i, node -> idx});
            }
            node = node -> children[word[j] - 'a'];
        }
        if (node) {
            for (int idx : node -> indices) {
                if (i != idx) {
                    pairs.push_back({i, idx});
                }
            }
        }
    }

    bool isPalindrome(string s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) {
                return false;
            }
        }
        return true;
    }
};
