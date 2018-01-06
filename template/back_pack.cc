#include <iostream>
#include <vector>
using namespace std;


//0-1 back pack
//F(i, v) 前i个item ，背包最大v的情况下 最大能装多少
//F(i, v) = max(F(i-1, v),  F(i - 1, v - vi) + vi)
//如果想省一维，就倒着遍历v  idx_v 从 V 到 vi

int back_pack01(vector<int> arr, int V) {
    vector<int> dp(V + 1, 0);
    for(auto vi : arr) {
        for(int v = V; v >= vi; v--) {
            dp[v] = max(dp[v], dp[v-vi] + vi);
        }
    }
    return dp[V];
}

//complete back pack

int back_pack_complete(vector<int> arr, int V) {
    vector<int> dp(V + 1, 0);
    for(auto vi : arr) {
        for(int v = vi; v <= V; v++) {
            dp[v] = max(dp[v], dp[v-vi] + vi);
        }
    }
    return dp[V];
}




int main() {
    vector<int> arr = {3,4,5,8};
    cout<<back_pack01(arr, 10)<<endl;
    return 0;
}
