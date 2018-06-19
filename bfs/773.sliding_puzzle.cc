/* 华容道 */
/*
On a 2x3 board, there are 5 tiles represented by the integers 1 through 5, and an empty square represented by 0.

A move consists of choosing 0 and a 4-directionally adjacent number and swapping it.

The state of the board is solved if and only if the board is [[1,2,3],[4,5,0]].

Given a puzzle board, return the least number of moves required so that the state of 
the board is solved. If it is impossible for the state of the board to be solved, return -1.

从零开始BFS遍历，每次都有最多四个选择，然后每次抉择都算是一层，或者说是一个step，
所以都是遍历完一层所有的option，才进入下一层。
但为了重复交换，我们要有把每次交换后的形状都存在一个visit里，所以才把输入变成了一个字符串。

*/
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int slidingPuzzle(vector<vector<int>>& board) {
    int m = board.size();
    if(m == 0) return 0;
    int n = board[0].size();
    
    string target = "123450";
    string s;
    for(auto row: board) for(auto col : row) s += col + '0';
    if( s == target) return 0;
    
    
    queue<string> q; 
    set<string> visited;
    q.push(s);
    visited.insert(s);
    
    int step = 0;
    int dir[] = {-1,0,1,0,-1};
    
    while(!q.empty()) {
        step++;
        int len = q.size();
        for(int i = 0; i < len; i++) {
            string t = q.front(); q.pop();
            int idx = t.find('0');
            int r = idx / n, c = idx % n;
            
            for(int d = 0; d < 4; d++) {
                int x = r + dir[d], y = c + dir[d+1];
                if(x < 0 || y < 0 || x > m - 1 || y > n - 1) continue;
                swap(t[idx], t[x*n+y]);
                if(t == target) return step;
                if(!visited.count(t)) {
                    q.push(t);
                    visited.insert(t);
                }
                swap(t[idx], t[x*n+y]);
            }
        }
    }
    return -1;
}
