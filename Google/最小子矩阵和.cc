//给一个int二维array，求所有sub rectangle中，最小的和是多少
#include "../common.h"
vector<vector<int>> presum;

void setup(vector<vector<int>> &matrix) {
    int m = matrix.size();
    if (m == 0)
        return;
    int n = matrix[ 0 ].size();
    presum.resize(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            presum[ i + 1 ][ j + 1 ] =
                matrix[ i ][ j ] + presum[ i ][ j + 1 ] + presum[ i + 1 ][ j ] - presum[ i ][ j ];
            cout << presum[ i + 1 ][ j + 1 ] << " ";
        }
        cout << endl;
    }
}
int sumRegion(int row1, int col1, int row2, int col2) {
    int minRow = min(row1, row2);
    int minCol = min(col1, col2);
    int maxRow = max(row1, row2);
    int maxCol = max(col1, col2);
    return presum[ maxRow + 1 ][ maxCol + 1 ] - presum[ maxRow + 1 ][ minCol ] -
           presum[ minRow ][ maxCol + 1 ] + presum[ minRow ][ minCol ];
}

int continueMax(vector<int> dp) {
    int sum = 0;
    int res = dp[ 0 ];
    for (auto d : dp) {
        if (sum > 0) {
            sum += d;
        } else {
            sum = d;
        }
        res = max(res, sum);
    }
    return res;
}

int continueMax2(vector<int> dp) {
    int sum = 0;
    int res = dp[ 0 ];
    for (auto d : dp) {
        sum = max(d, sum + d);
        res = max(res, sum);
    }
    return res;
}

int maxRegion(int m, int n) {
    vector<int> dp(m, 0);
    int         globalMax = 0;
    for (int col1 = 0; col1 < n - 1; col1++) {
        for (int col2 = col1 + 1; col2 < n; col2++) {
            for (int row = 0; row < m; row++) {
                dp[ row ] = sumRegion(row, col1, row, col2);
                cout << "**" << dp[ row ] << " ";
            }
            cout << endl;
            globalMax = max(continueMax2(dp), globalMax);
        }
    }
    return globalMax;
}

int maxRegionWithK(int m, int n, int k) {
    vector<int> dp(m, 0);
    int         globalMax = 0;
    for (int col1 = 0; col1 < n; col1++) {
        for (int col2 = col1 + 1; col2 < n; col2++) {
            for (int row = 0; row < m; row++) {
                for (int row2 = row + 1; row2 < m; row2++) {
                    int d = sumRegion(row, col1, row2, col2);
                    if (d <= k)
                        globalMax = max(globalMax, d);
                }
            }
        }
    }
    return globalMax;
}

int main(int argc, char *argv[]) {
    // vector<vector<int>> matrixs = {{10, -2, 3}, {3, -5, 7}, {0, 1, 9}};
    vector<vector<int>> matrixs = {{5, -4, -3, 4}, {-3, -4, 4, 5}, {5, 1, 5, -4}};
    setup(matrixs);
    int m = matrixs.size();
    int n = matrixs[ 0 ].size();

    cout << maxRegionWithK(m, n, 10) << endl;
    return 0;
};
