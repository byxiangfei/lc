#include <iostream>
#include <vector>
using namespace std;

/*
http://www.cnblogs.com/grandyang/p/8433813.html

Input: grid =
[[1, 1, 1],
 [1, 1, 1],
 [1, 1, 1]]
Output: 9
*/
// 任取两行， 如果同一列都为1，则 cnt++, 然后直接能算出来一共有多少个矩形
int numOfRectangle(vector<vector<int>> &grid) {
    int res = 0;
    int m = grid.size(), n = grid[0].size();

    for(int i = 0; i < m; i++) {
        for(int j = i + 1;  j < m ; j++) {
            int cnt = 0;
            for(int k = 0; k < n; k++)
                if(grid[i][k] == 1 && grid[j][k] == 1) cnt++;
            res += cnt * (cnt - 1) / 2;
        }

    }
    return res;
}

int numOfRectangleSpeedUp(vector<vector<int>> &grid) {
    int res = 0;
    int m = grid.size(), n = grid[0].size();

    for(int i = 0; i < m; i++) {
        vector<int> ones;
        for (int k = 0; k < n; k++) if (grid[i][k]) ones.push_back(k);
        for(int j = i + 1;  j < m ; j++) {
            int cnt = 0;
            for(int k = 0; k < ones.size(); k++)
                if(grid[j][ones[k]] == 1)  cnt++;
            res += cnt * (cnt - 1) / 2;
        }
    }
    return res;
}

int main() {
    vector<vector<int>> grid = {{1,1,1},{1,1,1}, {1,1,1}};
    cout<<numOfRectangleSpeedUp(grid)<<endl;
    return 0;
}
