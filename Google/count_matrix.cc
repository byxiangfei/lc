/*
面经:
https://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=613538&extra=page%3D1%26filter%3Dsortid%26sortid%3D327%26searchoption%5B3179%5D%5Bvalue%5D%3D53%26searchoption%5B3179%5D%5Btype%5D%3Dradio%26sortid%3D327%26orderby%3Ddateline
一面高中函数二分法
y = f(x)

f(x) = 4
f(1) == a
f(100) == b

一个01矩阵，求全0的子矩阵有多少个
[0,1,0,0,1]
[1,0,0,0,0]
[1,0,0,1,1]
*/

#include "../common.h"

int arraySumLessK(vector<int> &arr, int k) {
    set<int> s;
    s.insert(0); // 这个insert很难想到
    int sum = 0;
    int ma = INT_MIN;
    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        auto it = s.lower_bound(sum - k);
        if (it != s.end()) {
            ma = max(ma, sum - *it);
        }
        s.insert(sum);
    }
    return ma;
}

int getlen(vector<int> &arr, int x) {
    int n = arr.size();
    vector<int> h(n + 1, 0);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        h[i + 1] = max(h[i], sum);
    }
    sum = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        int idx = lower_bound(h.begin(), h.end(), sum - x) - h.begin();
        ans = max(ans, i - idx + 1);
    }
    return ans;
}

int main() {
    vector<int> arr = {10, 1, 5, 4, 1};
    cout << getlen(arr, -1) << endl;
}
