/* 
https://leetcode-cn.com/problems/making-a-large-island/description/
我们最多只能将一格 0 海洋变成 1变成陆地。
进行填海之后，地图上最大的岛屿面积是多少？
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int largestIsland(vector<vector<int>>& grid) {
	int res = 0;
	
	
	return res;

}

int main() {
	vector<vector<int>> grid = {
		{1,0,1},
		{0,1,1},
		{0,0,1},
	};
	cout<<largestIsland(grid)<<endl; // should be 6
}