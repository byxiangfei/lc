/*
这道题给了我们一个数组，又给了我们两个数字L和R，
表示一个区间范围，让我们求有多少个这样的子数组，使得其最大值在[L, R]区间的范围内
Example :
Input:
A = [2, 1, 4, 3]
L = 2
R = 3
Output: 3
Explanation: There are three subarrays that meet the requirements: [2], [2, 1], [3].
*/
#include <iostream>
#include <vector>

using namespace std;

int count(vector<int>& A, int bound) {
    int res = 0, cur = 0;
    for (int x : A) {
        cur = (x <= bound) ? cur + 1 : 0;
        res += cur;
    }
    return res;
}

int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
    return count(A, R) - count(A, L - 1);
}


int main() {
    vector<int> A = {2,1,4,3};
    cout<<numSubarrayBoundedMax(A, 1, 2);
    return 0;
}
