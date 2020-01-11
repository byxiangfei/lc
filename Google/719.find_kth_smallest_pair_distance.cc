/*
http://www.cnblogs.com/grandyang/p/8627783.html
题目就是找第 k 小数对儿， 数对儿的距离就是差值

1. sort(nums.begin(), nums.end());
2. => a,b,c,d,e
1->3 有几个数对儿， C（end - beg + 1）/ 2
C n/2  n(n-1) / 2



*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;
bool cmp(int a, int b) {return a < b; } // equal to less
int smallest(vector<int> &arr) {
    sort(arr.begin(), arr.end(), less<int>()); // 默认是从小到大
    // sort(arr.begin(), arr.end(), cmp); // 默认是从小到大
    return 0;
}

int main() {
    vector<int> a = {5,3,10,4};
    smallest(a);
    for(auto i: a) cout<<i<<" ";
    return 0;
}
