#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
   histo: 1 4 5 6 4 2
*/

int largestRetangle(vector<int> &histo) {
    histo.push_back(0);
    stack<int> s;  // 存入的是递增，这样每次 pop 之后，才能算出更宽的
                   // stack 里存的是索引
    int res = 0;
    for(int i = 0; i < histo.size(); ) {
        if(s.empty() || histo[s.top()] < histo[i]) {
            s.push(i++);
            continue;
        }
        int t = s.top(); s.pop();
        res = max(res, histo[t] * (s.empty() ? i :  i - s.top() - 1));
    }
    return res;
}

int main() {
    vector<int> res = {1,4,5,6,4,2};
    cout<<largestRetangle(res)<<endl;
    return 0;
}
