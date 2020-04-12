#include <iostream>
#include <vector>
using namespace std;

int findK(vector<int> arr, int k, int c) {
    int s = 0, e = arr.size() - c - 1;
    while(s <= e) {
        int mid = s + (e - c)/2;
        if(k - arr[mid] <= arr[mid+c] - k) e = mid - 1;
        else s = mid+1;
    }
      return s;
}

int main() {
    vector<int> a = {1,2,3,4,6,7,8};
    cout<<findK(a, 4, 2);
    return 0;

}
