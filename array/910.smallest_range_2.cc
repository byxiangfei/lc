/*
对数组 A 的每个元素要么+k，要么-k，求得到的 B 数组 最小的 diff 是多少
A =[0,10] K = 2, B=> [2,8] return 6

分析：A 有序时， 那么操作一定是先+K,(再某一个位置-K), 并且转折的位置，与其下面的数的 diff
才可能是更小的 diff 0,1,3,6  => 2,(3,1),4 or 2,(3,5),4  => 3
所以我们就依次把每个元素都当成是可能的转捩点，试一下
变形后的数组的最大值肯定是 A[i]+K 与 A[n-1] - K 之间的一个
最小值则是  A[i+1] - K, 与 A[0] + K 之间的一个
*/

#include "../common.h"

int diff(vector<int> A, int K) {
    int n = A.size();
    if (n == 1)
        return 0;
    sort(A.begin(), A.end());
    int res = A[ n - 1 ] - A[ 0 ];
    for (int i = 0; i < n; i++) {
        int high = max(A[ i ] + K, A[ n - 1 ] - K);
        int low  = min(A[ i + 1 ] - K, A[ 0 ] + K);
        res      = min(res, high - low);
    }
    return res;
}

int main() {
    vector<int> A = {0, 1, 3, 6};
    cout << diff(A, 3) << endl;
    return 0;
}
