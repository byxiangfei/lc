int numIslands(vector<vector<char>>& grid) {
    int res = 0;
    int m = grid.size();
    if(m == 0) return res;
    int n = grid[0].size();
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == '1') {
                helper(grid,i,j);
                res++;
            }
        }
    }
    return res;
}

void helper_dfs(vector<vector<char>>& grid, int i, int j) {
    if(i < 0 || j < 0 || i > grid.size() - 1 || j > grid[0].size() - 1 || grid[i][j] == '0') return;
    grid[i][j] = '0';
    int dir[5] = {-1,0,1,0,-1};
    for(int d = 0; d < 4; d++)
        helper(grid, i + dir[d], j + dir[d+1]);
    return;
}

void helper_bfs(vector<vector<char>>& grid, int i, int j) {
    queue<pair<int,int>> q;
    q.emplace(i, j);
    while(!q.empty()) {
        auto top = q.front();
        q.pop();
        int dir[5] = {-1,0,1,0,-1};
        for(int d = 0; d < 4; d++) {
            int x = top.first + dir[d];
            int y = top.second + dir[d+1];
            if(x < 0 || y < 0 || x > grid.size() - 1 || y > grid[0].size() - 1 || grid[x][y] == '0') continue;
            grid[x][y] = '0';
            q.emplace(x,y);
        }
    }
    return;
}