#include "common.h"

bool isSub(string a, string b) {
    int l1 = a.size();
    int l2 = b.size();
    int j = 0;
    for(int i = 0; i < l1; i++) {
        if(a[i]!= b[j]) continue;
        if(++j == l2) return true;
    }
    return false;
}

bool isSub2(string a, string b) {
    vector<int> map(256, 0);
    for(auto c: a) map[c]++;
    for(auto c: b) {
        if(--map[c] < 0) return false;
    }
    return true;
}


vector<string> solve(vector<string> &A, vector<string> &B) {
    vector<string> res;
    for(auto a: A) {
        bool ok = true;
        for(auto b: B) {
            if(!isSub2(a, b)) {
                ok = false;
                break;
            }
        }
        if(ok) {
            res.push_back(a);
        }
    }
    return res;
}

int main() {
    vector<string> A = {"amazon","apple","facebook","google","leetcode"};
    vector<string> B = {"e","oo"};
    vector<string> res = solve(A,B);
    for(auto r: res) cout<<r<<" ";
    cout<<endl;
    return 0;
}
