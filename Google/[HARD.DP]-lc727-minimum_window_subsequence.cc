/*
http://www.cnblogs.com/grandyang/p/8684817.html
两个字符串S和T，让我们找出S的一个长度最短子串W，使得T是W的子序列，如果长度相同，取起始位置靠前的。
思路： DP

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 还是考虑一下 dp 吧
// dp[i][j] 代表 s 前 i 个，t 前 j 个子串里，满条件的 s 的 start idx，
// 那么 lens 就是 i - start_idx
/*
  S[i]: - a b c d e
      - 0 1 2 3 4 5
 T[j] b x x 1 0
     d  x x 0 0
     e  x x x 0
*/
//  dp[i][j] = (S[i - 1] == T[j - 1]) ? dp[i - 1][j - 1] : dp[i - 1][j];
//  abcd & bd ==  abc & b
//  abcde & bd == abcd & bd
// 初始化边界的时候 trick 一点
string solve(string S, string T) {
    int m = S.size(), n = T.size(), start = -1, minLen = INT_MAX;
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    for (int i = 0; i <= m; ++i) dp[i][0] = i;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= min(i, n); ++j) {
            dp[i][j] = (S[i - 1] == T[j - 1]) ? dp[i - 1][j - 1] : dp[i - 1][j];
        }
        if (dp[i][n] != -1) {   //  每一行结束的时候都可以检测一些，如果走到最后了就有命中的
            int len = i - dp[i][n];
            if (minLen > len) {
                minLen = len;
                start = dp[i][n];
            }
        }
    }
    return (start != -1) ? S.substr(start, minLen) : "";
}

int main() {
    cout<<solve("abcdebdde", "bde")<<endl; // return bcde
    cout<<solve("bbbbdde","bde")<<endl;
    return 0;
}
