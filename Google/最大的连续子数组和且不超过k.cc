#include "../common.h"

// https://www.quora.com/Given-an-array-of-integers-A-and-an-integer-k-find-a-subarray-that-contains-the-largest-sum-subject-to-a-constraint-that-the-sum-is-less-than-k
/*
Given an array of integers A and an integer k,
find a subarray that contains the largest sum,
subject to a constraint that the sum is less than k?


*/

vector<int> vec = {2, 1, -4, -5};
int         k   = 4;

int arraySumLessK(vector<int> &arr, int k) {
    set<int> s;
    s.insert(0); // 这个insert很难想到, 哨兵，加上了，如果恰好是前n个元素和，满足才会得以返回
    int sum = 0;
    int ma  = INT_MIN;
    for (int i = 0; i < arr.size(); i++) {
        sum += arr[ i ];
        auto it = s.lower_bound(sum - k);
        if (it != s.end()) {
            ma = max(ma, sum - *it);
        }
        s.insert(sum);
    }
    return ma;
}

int main() {
    auto res = arraySumLessK(vec, k);
    cout << res << endl;
    return 0;
}
