#include <iostream>
#include <string>
using namespace std;

bool isSubSeq(string l, string s) {
    int cur = 0;
    for(int i = 0; i < s.size(); i++) {
        cur = l.find(s[i]);
        if(cur == string::npos) return false;
        l = l.substr(cur+1);
    }
    return true;
}

bool isSubSequence(string l, string s) {
    auto i = s.begin();
    for(auto c: l) {
        i += (*i == c);
        if(i == s.end()) return true;
    }
    return i == s.end();
}

int main() {
    cout<<isSubSeq("abcdef","acf")<<endl;
    cout<<isSubSequence("abcfff","acf")<<endl;
    return 0;
}
