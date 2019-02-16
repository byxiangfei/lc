#include "common.h"
//判断小岛相同，应该要用相对位置, 只要每次传递一个起始点就好了
//如果说可以旋转，也算位置一样呢

vector<int> helper_bfs(vector<vector<int>>& grid, int i, int j, int i0, int j0) {
    vector<int> res;
    queue<pair<int,int>> q;
    q.emplace(i, j);
    while(!q.empty()) {
        auto top = q.front();
        q.pop();
        int dir[3] = {0,1,0};
        for(int d = 0; d < 2; d++) {
            int x = top.first + dir[d];
            int y = top.second + dir[d+1];
            if(x < 0 || y < 0 || x > grid.size() - 1 || y > grid[0].size() - 1 || grid[x][y] == 0) continue;
            grid[x][y] = 0;
            res.push_back(x*grid[0].size() + y);
            q.emplace(x,y);
        }
    }
    return res;
}

bool isSame(vector<int> a, vector<int> b) {
    if(a.size() != b.size()) return false;
    if(a.size() < 2) return true;
    int diff = a[0] - b[0];
    for(int i = 1; i < b.size(); i++) {
        if (b[i] - a[i] != diff) {
            return false;
        }
    }
    return true;
}

int distinctIsland(vector<vector<int>>& grid) {
    int res = 0;
    int m = grid.size();
    if (m == 0) return res;
    int n = grid[0].size();
    set<vector<int>> myset;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == 1) {
                myset.insert(helper_bfs(grid,i,j));
            }
        }
    }
    return myset.size();
}



int main() {
    vector<vector<int>> grids ={{1,1,0,0}, {1,0,0,0}, {0,0,1,1}, {0,0,1,0}};
    cout<<distinctIsland(grids)<<endl;
}
