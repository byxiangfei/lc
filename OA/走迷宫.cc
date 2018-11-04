/* 2D array 0 block， 1 accessible，9 destination。 问从【0，0】到9最少要多少步。*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int bfs(vector<vector<int>> &grids) {
    int m = grids.size();
    int n = grids[0].size();
    queue<int> q;
    q.push(0);
    int res = 0;
    vector<pair<int,int>> dir={{-1,0},{1,0},{0,1},{0,-1}};
    while(!q.empty()) {
        int s = q.size();
        for(int i = 0; i < s; i++) {
            int t = q.front(); q.pop();
            int x = t/n, y = t%n;
            cout<<"x:"<<x<<" y:"<<y<<endl;
            if(grids[x][y]== 9) {
                return res;
            }
            if(grids[x][y]== 0) {
                continue;
            }
            grids[x][y] = 0 ; //visited
            for(auto d: dir) {
                int nx = x + d.first, ny = y + d.second;
                if(nx >= 0 && nx < m && ny >= 0 && ny < n && grids[nx][ny]) q.push(nx * n + ny);
            }
        }
        res++;
    }
    return -1;
}

int main() {
    vector<vector<int>> grids = {
        {1,0,0,0},
        {1,1,1,0},
        {0,0,1,9},
    };
    cout<<bfs(grids)<<endl;
    return 0;
}
