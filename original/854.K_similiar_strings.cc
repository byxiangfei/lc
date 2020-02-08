#include "common.h"
// K-similar 字符串对儿的定义是，交换 K times变一样
// 给定两个字符串，问他们最小的 K 是多少
// BFS（最短问题优先考虑 BFS）， DFS+cache 都可以, DFS不太好写

int solve(string a, string b) {
    string tA, tB;
    for (int i =  0; i < A.size(); i++) {
        if (A[i] != B[i]) {
            tA.push_back(A[i]);
            tB.push_back(B[i]);
        }
    }
    unordered_map<string, int> dp;
    return dfs(tA, tB, 0, dp);
}
// DFS: +cache
int dfs(string a, string b, int pos, unordered_map<string, int>& dp) {
    if (pos == b.size()) {
        dp[a] = 0;
        return 0;
    }
    if (dp.count(a)) return dp[a];
    if (a[pos] == b[pos]) return dfs(a, b, pos+1, dp);
    int mn = INT_MAX;
    for (int i = pos + 1; i < a.size(); i++) {
        if (a[i] == b[pos]) {
            swap(a[pos], a[i]);
            mn = min(mn, dfs(a, b, pos+1, dp) + 1);
            swap(a[pos], a[i]);
        }
    }
    dp[a] = mn;
    return dp[a];
}
};

// BFS: A为变量，B 为 target
int bfs(string A, string B) {
    if (A == B) return 0;
    queue<string> que;
    unordered_set<string> vis;
    que.push(A);
    int ans = 0, len = A.length();
    while (!que.empty()) {
       ans++;
       int m = que.size();
       while (m--) {
           string cur = que.front(); que.pop();
           int i = 0;
           while (cur[i] == B[i]) i++;  //跳过一样的前缀
           for (int j = i + 1; j < len; j++) {
               //从A中找到等于 B[i]的
               if (cur[j] != B[j] && cur[j] == B[i]) {
                   string temp = cur;  //这里是保证 str 不变的
                   swap(temp[i], temp[j]);
                   if (temp == B) return ans;
                   if (vis.insert(temp).second) que.push(temp);
               }
           }
       }
    }
    return ans;
}

int main() {
    cout<<bfs("abac", "baca")<<endl;
    cout<<bfs("aabc", "abca")<<endl;
    return 0;
}
