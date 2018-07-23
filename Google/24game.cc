#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


void helper(vector<double>& nums, double eps, bool& res) {
    if (res) return;
    if (nums.size() == 1) {
        if (abs(nums[0] - 24) < eps) res = true;
        return;
    }
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            double p = nums[i], q = nums[j];
            vector<double> t{p + q, p - q, q - p, p * q};
            if (p > eps) t.push_back(q / p);
            if (q > eps) t.push_back(p / q);
            nums.erase(nums.begin() + i);   // 注意：先 erase 高位的
            nums.erase(nums.begin() + j);
            for (double d : t) {
                nums.push_back(d);
                helper(nums, eps, res);
                nums.pop_back();
            }
            nums.insert(nums.begin() + j, q);
            nums.insert(nums.begin() + i, p);
        }
    }
}

bool judgePoint24(vector<int>& nums) {
    bool res = false;
    double eps = 0.001;
    vector<double> arr(nums.begin(), nums.end());
    helper(arr, eps, res);
    return res;
}

int main() {
    vector<int> nums = {1,2,3,4};
    cout<<judgePoint24(nums`);
    return 0;
}
