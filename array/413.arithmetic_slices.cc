#include <vector>
using namespace std;
// A sequence of number is called arithmetic if it consists of at least three elements
// and if the difference between any two consecutive elements is the same.
int numberOfArithmeticSlices(vector<int>& A) {
    int n = A.size();
    if(n < 3) return 0;
    int dp = 0, res = 0;
    for(int i = 2; i < n; i++) {
        if(A[i-2] - A[i-1] == A[i-1]-A[i]) dp++;
        else dp = 0;
        res += dp;
    }
    return res;
}
