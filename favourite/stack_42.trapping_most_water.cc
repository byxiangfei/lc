#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//核心思路是维护一个递减的栈,栈里存index
//当遇到大于栈头，就去算差值
int trap(vector<int> arr) {
   stack<int> s;
   int res = 0;
   for(int i = 0; i < arr.size(); ) {
        if(s.empty() || arr[s.top()] > arr[i]) {
            s.push(i++);
        }
        else {
            int t = s.top();
            s.pop();
            res += s.empty() ? 0 : (min(arr[s.top()], arr[i]) - arr[t])*(i - s.top() - 1);
        }
    }
    return res;
}


//挡泥板思路，左边短，挪左边
int trap1(vector<int> arr) {
    int beg = 0, end = arr.size() - 1;
    int res = 0;
    while(beg < end) {
        int min = min(arr[beg], arr[end]);
        if(arr[beg] == min) {
            beg++;
            while(beg < end && arr[beg] < min) {
                res += min - arr[beg];
                beg++;
            }
        } else {
            end--;
            while(beg < end && arr[end] < min) {
                res += min - arr[end];
                end--;
            }
        }
    }
    return res;
}
