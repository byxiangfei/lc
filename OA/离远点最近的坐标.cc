#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//小于就是从小到大
struct Mycmp {
    Mycmp(pair<int,int> original) {
            org = original;
    }
    bool operator() (pair<int,int> a, pair<int,int> b) {
        return (a.first-org.first)*(a.first-org.first) + (a.second-org.second)*(a.second-org.second) <
         (b.first-org.first)*(b.first-org.first) + (b.second-org.second)*(b.second-org.second);
    }
    pair<int,int> org;
};

bool cmp(pair<int,int> a, pair<int,int> b) {
    return a.first*a.first + a.second*a.second < b.first*b.first + b.second*b.second;
}

vector<pair<int,int>> FindKclosestPoint2(vector<pair<int,int>> &points, int k) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, std::greater<pair<int,int>>> pq;  // 默认是小的
    vector<pair<int,int>> res;
    for(int i = 0; i < points.size(); i++) {
        pq.push(points[i]);
    }
    for(int i = 0; i < k; i++) {
        res.push_back(pq.top());
        pq.pop();
    }
    return res;
}

vector<pair<int,int>> FindKclosestPoint(vector<pair<int,int>> &points, int k) {
    sort(points.begin(), points.end(), Mycmp(pair<int,int>{0,-1}));
    vector<pair<int,int>> res;
    for(int i = 0; i < k; i++) {
        res.push_back(points[i]);
    }
    return res;
}

int main() {
    vector<pair<int,int>> points = {{1,2}, {3,4},{-1,0}};
    auto res = FindKclosestPoint(points,2);
    for(auto r: res) {
        cout<<r.first<<" "<<r.second<<endl;
    }
    return 0;
}
