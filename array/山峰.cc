#include "../common.h"

int longestMountain(vector<int> &A) {
    int i   = 1;
    int res = 0;
    int n   = A.size();
    while (i < n) {
        int start = i;
        while (i < n && A[ i ] > A[ i - 1 ]) {
            i++;
        }
        if (start == i || (i < n && A[ i ] == A[ i - 1 ])) {
            i++;
            continue;
        }
        while (i < n && A[ i ] < A[ i - 1 ]) {
            i++;
            res = max(res, i - start + 1);
        }
        if (i < n) {
            res = max(res, i - start + 1);
        }
    }
    return res;
}

int longestMountain2(vector<int> &A) {
    int i   = 1;
    int res = 0;
    int n   = A.size();
    while (i < n) {
        if (A[ i ] <= A[ i - 1 ]) {
            i++;
            continue;
        }
        int start = i;
        while (i < n && A[ i ] > A[ i - 1 ]) {
            i++;
        }
        while (i < n && A[ i ] < A[ i - 1 ]) {
            i++;
            res = max(res, i - start + 1);
        }
    }
    return res;
}

int main() {
    vector<int> arr = {1, 2, 2, 2, 1};
    cout << longestMountain2(arr) << endl;
    return 0;
}
