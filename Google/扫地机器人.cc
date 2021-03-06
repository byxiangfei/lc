/*
http://www.1point3acres.com/bbs/thread-289514-1-1.html
http://www.1point3acres.com/bbs/thread-345555-1-1.html

Robot API

class Robot {
public:
    // Moves returns true if next cell is open and robot moves into the cell,
    // returns false if next cell is obstacle and robot stays on the current cell.
    bool Move();

    bool Move(direction = None);  // each call only move one step in one direction

    void TurnLeft(int k);

    void TurnRight(int k);

    void Clean();

    void cleanAll();
}
*/


#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Robot{
private:
    vector<vector<int>> data;
    int x;
    int y;
    int N;
    int d;  // direction 0：←， 1： 下 2：→，3：上，

public:
    // direction  relative direction
    bool move(int direction){
        int x = direction - d;
        if(x > 0){
            turnR(x);
        } else if(x < 0){
            turnL(-x);
        }
        int ret = move();
        if(ret) cout << "move:" << direction << endl;
        return ret;
    }

    bool move(){
        int dx = 0;
        int dy = 0;

        switch(d){
            case 0:
                dx--;
                break;
            case 1:
                dy++;
                break;
            case 2:
                dx++;
                break;
            case 3:
                dy--;
                break;
            default:
                break;
        }
        int tx = x + dx;
        int ty = y + dy;

        if( tx >= N || tx < 0 || ty >= N || ty < 0){
            return false;
        }

        if(data[tx][ty]) return false;
        x = tx;
        y = ty;
        return true;
    }

    // k 必须是个非负数
    void turnR(int k){
        d += k;
        d = d % 4;
    }
    void turnL(int k){
        turnR(4 - k % 4);   // 向左转3 == 像右转1
    }

    void clean(){
        cout << "clean:" << x << ":" << y << endl;
    }

    Robot(){
        N = 4;
        data = {
                {0,0,0,1},
                {0,1,0,0},
                {0,0,1,1},
                {0,0,0,0}
        };
        x = 0;
        y = 0;
        d = 0;
    }

    void cleanAll(){
        unordered_set<int> vis;
        help(vis);
    }

    void help(unordered_set<int> & vis){
        if(vis.find(x * N + y) != vis.end()) return;
        clean();
        vis.insert(x * N + y);

        int back[4] = {2, 3, 0, 1};

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i ++) {
            int tx = x + dx[i], ty = y + dy[i];
            if( tx >= N || tx < 0 || ty >= N || ty < 0 || vis.count(tx * N + ty)) continue;
            if(move(i)) {
                help(vis);
                move(back[i]);   //扫地之精华，就是在每个方向，前进了，还要后退！
            }
        }
    }
};

int main() {
        Robot r;
        r.cleanAll();
        return 0;
}
