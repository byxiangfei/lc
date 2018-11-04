/*
背景是无人机送货，无人机有最大里程，然后给了两个list，分别是出发和返回的里程数，
数据类型是List<List<Integer>>，list里面只有id和里程两个值，
要求找出所有出发和返回里程数之和最接近无人机最大里程的pair。
比如，最大里程M = 11000，往 = {{1, 1000},{2, 7000},{3, 12000}},
 返 = {{1, 10000},{2, 9000},{3, 3000},{4, 2000}},
 最接近的里程和是10000，所以结果是{{1, 2},{2, 3}}.
*/
#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool cmp(pair<int,int>a, pair<int,int>b) {
    return a.second < b.second;
}

vector<pair<int,int>> findPair2(vector<pair<int,int>> go, vector<pair<int,int>> back, int target)  {
    vector<pair<int,int>> res;
    sort(go.begin(), go.end(), cmp);
    sort(back.begin(), back.end(), cmp);
    //先找最 closest 的值
    int minDiff = INT_MAX;
    int i = 0, j = back.size() - 1;

    while(i < go.size() && j >= 0) {
        if (go[i].second + back[j].second == target) {
            minDiff = 0;
            break;
        }
        if(go[i].second + back[j].second < target) {
            minDiff = min(minDiff, target - (go[i].second + back[j].second));
            i++;
        } else {
            minDiff = min(minDiff,go[i].second + back[j].second - target);
            j--;
        }
    }
    cout<<"debug:"<<minDiff<<endl;
    //然后 twosum
    map<int,vector<int>> m;  //会有重复
    for(auto g: go) {
        //if (target < g.second) continue;
        m[abs(target - g.second - minDiff)].push_back(g.first);  // 如果是有小于限制，就不行

    }
    for(auto b: back) {
        if(m.count(b.second)) {
            for(auto gid: m[b.second]) {
                res.emplace_back(gid, b.first);
            }
        }
    }

    return res;
}


//        1000, 7000, 12000
// 10000, 9000, 3000, 2000,
//找到每个 go id 里 最近
int findClosestPair(vector<pair<int,int>> &back, int target) {
    int beg = 0, end = back.size() - 1;
    while(beg <= end) {
        int mid = (beg + end) / 2;
        if(back[mid].second < target) {
            beg = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    if(beg == back.size()) return beg-1;
    cout<<"find target:"<<target<<" return idx:"<<beg<<" idxvalue:"<<back[beg].second<<endl;
    return beg;
}

vector<pair<int,int>> findPair(vector<pair<int,int>> go, vector<pair<int,int>> back, int target) {
    vector<pair<int,int>> res;
    sort(back.begin(), back.end(), cmp);
    int minDiff = INT_MAX;

    for(auto g :go) {
        int b = findClosestPair(back, target - g.second);
        int curdiff = abs(back[b].second + g.second - target);
        if (curdiff < minDiff) {
            res = vector<pair<int,int>>{{g.first, back[b].first}};
            minDiff = curdiff;
        } else if (curdiff == minDiff) {
            res.push_back({g.first, back[b].first});
        }
    }
    return res;
}

int main() {
    vector<pair<int,int>> go = {{1, 1000},{2, 1000},{3, 12000}};
    vector<pair<int,int>> back = {{1, 9000},{2, 9000},{3, 3000},{4, 2000}};
    auto res = findPair2(go,back, 12000);

    for(auto r : res){
        cout<<r.first<<" "<<r.second<<endl;
    }
    return 0;
}
