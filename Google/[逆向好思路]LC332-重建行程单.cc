// http://www.cnblogs.com/grandyang/p/5183210.html
/*
tickets = [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Return ["JFK", "MUC", "LHR", "SFO", "SJC"].

此题是所有的 pair 一定能串起来的，一个不落
倒着插入， 利用 stack， 然后到最后, 不用 visited
*/

#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;


vector<string> findItinerary(vector<pair<string, string>> tickets) {
    vector<string> res;
    stack<string> st{{"JFK"}};
    unordered_map<string, multiset<string>> m;
    for (auto t : tickets) {
        m[t.first].insert(t.second);
    }
    while (!st.empty()) {
        string t = st.top();
        if (m[t].empty()) {
            res.push_back(t);  //如果 t 的重点有 已经 settle 了，就可以往前放了
            st.pop();
        } else {
            st.push(*m[t].begin());
            m[t].erase(m[t].begin());
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    vector<pair<string,string>> tickets = {{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};
    auto res = findItinerary(tickets);
    for(auto r: res) cout<<r<<" ";
    return 0;
}
