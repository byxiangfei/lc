/*
http://www.cnblogs.com/grandyang/p/5291058.html

A group of two or more people wants to meet and minimize the total travel distance. You are given a 2D grid of values 0 or 1, where each 1 marks the home of someone in the group. The distance is calculated using Manhattan Distance, where distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|.

For example, given three people living at (0,0), (0,4), and (2,2):

1 - 0 - 0 - 0 - 1
|   |   |   |   |
0 - 0 - 0 - 0 - 0
|   |   |   |   |
0 - 0 - 1 - 0 - 0
The point (0,2) is an ideal meeting point, as the total travel distance of 2+2+2=6 is minimal. So return 6.

这题要从1维分析， 1维的情况是 a0,a1,a2,a3 ==>  a3-a0 + a2-a1
换到2维的情况，就是横纵两个1维，走两路， 遇到a1，a2,a3  同样也是 ==>  a3 - a1
就是先横着挪，然后再纵着挪

拓展题目是 带有 blocker 的题目
[LeetCode] Shortest Distance from All Buildings 建筑物的最短距离
http://www.cnblogs.com/grandyang/p/5297683.html
*/


#include <iostream>
#include <vector>

using namespace std;
int helper(vector<int> rows) {
    sort(rows.begin(), rows.end());
    int i = 0, j = rows.size() - 1;
    int res = 0;
    while(i < j) {
        res += rows[j--] - rows[i++];
    }
    return res;

}
int solve(vector<vector<int>> grid) {
    for(int i = 0; i < grid.size(); i++) {
        for(int j = 0; j < grid[0].size(); j++){
            if(grid[i][j]) {
                rows.push_back(i);
                cols.push_back(j);
        }
    }
    return helper(rows) + helper(cols);
}
