/*
给一个string和int k, 找出所有size为k的substring并且这个substring里的每个character都是不同的。
sliding window+map
abcd e fgabc, 4
abcd
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<string> subStingKDist(string str, int k) {
    vector<string> res;
    int len = str.size();
    if (k > len) return res;
    string m;

    for(int i = 0; i < len; i++) {
        auto pre = find(m.begin(), m.end(), str[i]);
        if(pre != m.end()) {
            m.erase(m.begin(), pre+1);
        }
        m += str[i];
        if(m.size() == k) {
            res.push_back(m);
            m.erase(m.begin());  //保证不超过
        }
    }
    return res;
}

int main() {
    auto res = subStingKDist("abecdedcba", 4);
    for(auto r: res) {
        cout<<r<<endl;
    }
    return 0;
}
