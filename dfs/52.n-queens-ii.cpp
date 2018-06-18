/*
 * [52] N-Queens II
 *
 * https://leetcode.com/problems/n-queens-ii
 *
 * Hard (44.26%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '1'
 *
 * Follow up for N-Queens problem.
 * 
 * Now, instead outputting board configurations, return the total number of
 * distinct solutions.
 * 
 * 
 */
class Solution {
public:
    bool check(int row, int col, vector<int> queue) {
        for(int i = 0; i< row; i++) {
            if (abs(i - row) == abs(queue[i] - col))
                return false;
        }
        return true;
    }
    
    void solve(vector<int> &queue, vector<bool> &visited, int row, int n, int &total) {
        if (row == n) {
            total++;
            return;
        }
        // 每次都从第0 列开始
        for (int i = 0; i < n; i++) {
            if (visited[i] || !check(row, i, queue)) continue;
            visited[i] = true;
            queue[row] = i;
            solve(queue, visited, row+1, n, total);
            queue[row] = -1;
            visited[i] = false;
        }
    }
    int totalNQueens(int n) {
       vector<int> queue(n, -1);
       vector<bool> visited(n, false);
       int total = 0;
       solve(queue, visited, 0, n, total);
       return total;
    }
};
