/*
Given an array of meeting time intervals consisting of start and end times
[[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

For example,
Given [[0, 30],[5, 10],[15, 20]],
return 2.
*/

#include <iostream>
#include <map>
#include <vector>


using namespace std;
int minMeetingRoom(vector<pair<int,int>> intervals) {
    int res = 0;
    map<int, int> m;
    for(auto i : intervals) {
        m[i.first]++;
        m[i.second]--;
    }
    int cnts = 0;
    for(auto v : m) {
        res = max(res, cnts += v.second);
    }
    return res;
}
int main() {
    vector<pair<int,int>> a = {{0,30},{5,10},{15,20}};
    cout<<minMeetingRoom(a);
    return 0;
}
