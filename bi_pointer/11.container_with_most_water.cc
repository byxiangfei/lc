#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int maxArea(vector<int>& height) {
    int beg = 0, end = height.size() - 1;
    int res = 0;
    while(beg < end) {
        res = max(res, min(height[beg], height[end]) * (end - beg));
        if(height[beg] < height[end]) {
            beg++;
        } else {
            end--;
        }
    }
    return res;
}
