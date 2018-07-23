//
/*
Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.

Input:
0 0 0
0 1 0
1 1 1
Output:
0 0 0
0 1 0
1 2 1
*/

#include <iostream>
#include <vector>
using namespace std;

// 从所有0出发，去找1，遇到更小，就更新
vector<vector<int>> solve(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> dirs{{0,-1},{-1,0},{0,1},{1,0}};
    queue<pair<int, int>> q;  //bfs
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == 0) q.push({i, j});
            else matrix[i][j] = INT_MAX;
        }
    }
    while (!q.empty()) {
        auto t = q.front(); q.pop();
        for (auto dir : dirs) {
            int x = t.first + dir[0], y = t.second + dir[1];
            if (x < 0 || x >= m || y < 0 || y >= n ||
            matrix[x][y] <= matrix[t.first][t.second]) continue;
            matrix[x][y] = matrix[t.first][t.second] + 1;
            q.push({x, y});
        }
    }
    return matrix;
}

int main() {
    vector<vector<int>> grid = {{0,0,0},{0,1,0},{1,1,1}};
    auto res = solve(grid);
    for(auto r: res) {for(auto c : r) cout<<c<<" ";  cout<<endl;}
    return 0;
}
