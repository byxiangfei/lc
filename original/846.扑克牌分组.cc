/*
手牌是无序整数，问能否分成每组是K个连续的元素
例如[1,2,3,6,2,3,4,7,8] 分成每组3个 => [1,2,3][2,3,4][6,7,8]
*/

#include "common.h"

bool solve(std::vector<int> cards, int K) {
    map<int, int> m;
    for(auto c : cards) m[c]++;

    for(auto it: m) {
        if(m[it.first] == 0) continue;
        if(m[it.first] < 0) return false;
        for(int i = K-1; i>=0; i--) {
            m[it.first + i] -= m[it.first];
        }
    }
    return true;
}

int main() {
    std::vector<int> cards = {1,2,3,6,2,3,4,7,8};
    cout<<solve(cards, 3)<<endl;
}
