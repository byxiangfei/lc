#include "common.h"
/*
[32,57,24,19,0,24,49,67,87,87] => [32,57,24,19,0,24,49], [67,87,87] 返回最小的len(left)

suppose the original left subarray is from 0 to partitionIdx, the max value of that is localMax.
If it is a valid partition, every value from partitionIdx + 1 to end should be >= localMax.
But if we find a value in the right part, a[i], is smaller than localMax,
which means the partition is not correct and we have to incorporate a[i] to form the left subarray.
So the partitionIdx is set to be i, and we have to recalculate the max value of the new left subarray.(recorded in max)
*/

int solve(vector<int> arr) {
    int localMax = a[0], partitionIdx = 0, m = localMax;
    for (int i = 1; i < a.size(); i++)
       if (a[i] < localMax) {
           partitionIdx = i;
           localMax = m;
       } else m = max(m, a[i]);
    return partitionIdx + 1;
}


int main() {
    cout<<solve(vector<int>{32,57,24,19,0,24,49,67,87,87});
    return 0;
}
