#include <iostream>
#include <vector>
using namespace std;



vector<int> mergeTwo(vector<int> a, vector<int> b) {
    vector<int> res;
    int i = 0, j = 0;
    while(i < a.size() && j < b.size()) {
        if (a[i] < b[j]) {
            res.push_back(a[i++]);
            continue;
        }
        res.push_back(b[j++]);
    }
    while(i < a.size()) {
        res.push_back(a[i++]);
    }
    while(j < b.size()) {
        res.push_back(b[j++]);
    }
    return res;
}

vector<int> merge(vector<vector<int>> lists) {
    vector<int> res = lists[0];
    int n = lists.size();

    for(int j = 1; j < n; j++) {
        res = mergeTwo(res, lists[j]);
    }

    return res;
}

void print(vector<int> res) {
    for(auto a: res) {
        cout<<a<<" ";
    }
    cout<<endl;
}

int main() {
    vector<vector<int>> lists = {
        {1,2,3,4},
        {1,3,5,6,7,8},
        {2,3,4,6},
    };
    print(merge(lists));

    print(mergeTwo(vector<int>{1,2,3,4}, vector<int>{2,3,4,5}));
    return 0;
}
