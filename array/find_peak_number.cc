#include <iostream>
#include <vector>
using namespace std;

int peak(vector<int> &a) {
    int beg = 0;
    int end = a.size() - 1;
    while(beg < end) {
        int mid = beg + (end - beg) / 2;
        if (a[mid] < a[mid+1]) beg = mid + 1;
        else end = mid;
    }
    return beg;
}

int main() {
    vector<int> a = {1,2,3,4,3,2,1};
    cout<<peak(a)<<endl;
    return 0;
}
