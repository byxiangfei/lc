#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream> //istringstream 必须包含这个头文件
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x)
        : val(x)
        , left(NULL)
        , right(NULL) {
    }
};

void printVector(vector<int> t) {
    for (auto x : t)
        cout << x << " ";
    cout << endl;
}
