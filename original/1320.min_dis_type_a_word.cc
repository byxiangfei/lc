#include "common.h"

int dp[ 27 ][ 27 ][ 301 ] = {};

int cost(char from, char to) {
    if (from == 26)
        return 0; // 这个终止条件比较厉害
    return abs(from / 6 - to / 6) + abs(from % 6 - to % 6);
}

int helper(string word, int pos, char left, char right) {
    if (pos >= word.size())
        return 0;

    if (dp[ left ][ right ][ pos ])
        return dp[ left ][ right ][ pos ];

    auto cur = word[ pos ] - 'A';

    dp[ left ][ right ][ pos ] = min(cost(left, cur) + helper(word, pos + 1, cur, right),
                                     cost(right, cur) + helper(word, pos + 1, left, cur));
    return dp[ left ][ right ][ pos ];
}

int minimumDistance(string word) {
    return helper(word, 0, 26, 26); // 开始的手指为空
}

int main() {
    cout << minimumDistance("TUGR") << endl;
    return 0;
}
