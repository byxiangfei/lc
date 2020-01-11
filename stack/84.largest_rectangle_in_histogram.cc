#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//核心思路是维护一个递（增）的栈, 与蓄水相反
//当遇到大于栈头，就去算差值
int trap(vector<int> arr) {
   arr.push_back(0);
   stack<int> s;
   int res = 0;
   for(int i = 0; i < arr.size(); ) {
        if(s.empty() || arr[s.top()] < arr[i]) {
            s.push(i++);
        }
        else {
            int t = s.top();
            s.pop();
            res = max(res, arr[t] * (s.empty() ? i : (i - s.top() - 1));
        }
    }
    return res;
}

