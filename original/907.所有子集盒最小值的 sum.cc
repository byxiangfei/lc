/*
给一个数组， 求 sum(min(each_subset))
//res = t[0]*a[0] + t[1]*a[1] ...
//t[i]是包含了以a[i]为最小值的子数组的个数

left[i] 是 在a[i]左边，*严格*比 a[i]大的元素的个数，即中间不能有比它小的
right[i]是 在 a[i]右边，比 a[i]大的元素的个数
比如， 3,[1],2,4 =>  left[idx=1] = 1, right[idx=1] = 2
                =>  left[idx=2] = 0, right[idx=2] = 1
                // t[2] = {} * {2,24} = 2
t[i] = (left[i] + 1) * (right[i] + 1)
可以通过边界来计算 count
*/

#include "common.h"

int solve(std::vector<int> A) {
    int n = A.size();
    vector<int> left(n, 0), right(n,0);
    stack<int> s,s2;
    s.push(-1);
    for(int i = 0; i < n; i++) {
        while(s.top() != -1 && A[s.top()] > A[i]) s.pop();
        left[i] = s.top() + 1;  //左边界
        s.push(i);
    }
    for(int i = 0; i < n; i++) cout<<left[i]<<" ";
    cout<<endl;

    s2.push(n);
    for(int i = n-1; i >= 0; i--) {
        while(s2.top() != n && A[s2.top()] >= A[i]) s2.pop();
        right[i] = s2.top()-1;
        s2.push(i);
    }
    for(int i = 0; i < n; i++) cout<<right[i]<<" ";
    cout<<endl;

    int res = 0;
    for(int i = 0;i < A.size(); i++) {
        res += A[i]*(i-left[i]+1)*(right[i]-i+1);
    }
    return res;
}

int main() {
    std::vector<int> a = {3,1,2,4};
    cout<<solve(a)<<endl;
    return 0;
}
