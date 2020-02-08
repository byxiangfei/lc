#include "../common.h"
int maxProfitwithK(int k, vector<int> &prices) {
    int n = prices.size();
    int dp[ n + 1 ][ k + 1 ][ 2 ];

    for (int i = 0; i <= n; i++) {
        for (int ki = 0; ki <= k; ki++) {
            dp[ i ][ ki ][ 0 ] = 0;
            dp[ i ][ ki ][ 1 ] = INT_MIN;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int ki = 0; ki < k; ki++) {
            dp[ i + 1 ][ ki + 1 ][ 0 ] =
                max(dp[ i ][ ki + 1 ][ 0 ], dp[ i ][ ki + 1 ][ 1 ] + prices[ i ]);
            dp[ i + 1 ][ ki + 1 ][ 1 ] =
                max(dp[ i ][ ki + 1 ][ 1 ], dp[ i ][ ki ][ 0 ] - prices[ i ]);
        }
    }
    return dp[ n ][ k ][ 0 ];
}

int maxProfit(int k, vector<int> &prices) {
    if (prices.size() == 0) {
        return 0;
    }
    if (k >= prices.size() / 2) {
        return maxProfit2(prices);
    }
    int         K = k;
    vector<int> dp(K + 1, 0);
    vector<int> buy(K + 1, INT_MAX);

    for (auto p : prices) {
        for (int kk = 1; kk <= K; kk++) {
            buy[ kk ] = min(buy[ kk ], p - dp[ kk - 1 ]);
            dp[ kk ]  = max(dp[ kk ], p - buy[ kk ]);
        }
    }
    return dp[ K ];
}

int main() {
    vector<int> prices = {2, 4, 1};
    cout << maxProfitwithK(2, prices) << endl;
    return 0;
}
