#include "common.h"

bool mycmp(const pair<string, int>& lhs, const pair<string, int>& rhs) {
  return lhs.second > rhs.second && lhs.first < lhs.first;
}


vector<string> topKFrequent(vector<string>& words, int k) {
    vector<string> res;

    map<string, int> m;
    for(auto w: words) {
        m[w]++;
    }
    vector<pair<string,int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), mycmp);

    for(int i = 0; i < k; i++) {
        res.push_back(v[i].first);
    }
    return res;
}


int main() {
    vector<string> a = {
        "hi","hi","ao","ao",
    };
    auto res = topKFrequent(a, 1);
    for(auto r: res) {
        cout<<r<<endl;
    }
    return 0;
}
