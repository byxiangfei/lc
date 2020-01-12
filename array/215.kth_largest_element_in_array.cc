#include <iostream>
#include <vector>
using namespace std;

// selection algorithm
// http://blog.csdn.net/u010900754/article/details/55250442

int partion(vector<int> &nums, int beg, int end) {
    int pivot = nums[ beg ];
    int last  = beg;

    for (int i = beg + 1; i <= end; i++) {
        if (nums[ i ] <= pivot) {
            swap(nums[ i ], nums[ ++last ]);
        }
    }
    swap(nums[ last ], nums[ beg ]);
    return last;
}

int findKthLargest(vector<int> &nums, int k) {
    // sort(nums.begin(), nums.end(), greater<int>());
    // return nums[k-1];
    int low = 0, high = nums.size() - 1;
    while (low <= high) {
        int m = partion(nums, low, high);
        if (m == nums.size() - k)
            return nums[ m ];
        else if (m > nums.size() - k)
            high = m - 1;
        else
            low = m + 1;
    }
    return -1;
}

int main() {
    vector<int> nums = {4, 1, 2};
    findKthLargest(nums, 1);
    for (auto i : nums) {
        cout << i << " ";
    }
    return 0;
}
