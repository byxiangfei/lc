#include "../common.h"
//------------------------------- 大于等于k系列---------------------
// 209 【正数】，>=s 【最小长度】 ：滑动窗
int largeKPositiveMinLengthWindow(vector<int> &nums, int s) {
    int res = INT_MAX;
    int n = nums.size();
    int left = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += nums[i];
        while (sum >= s) {
            res = min(res, i - left + 1);
            sum -= nums[left++];
        }
    }
    return res == INT_MAX ? 0 : res;
}

// 209 【正数】，>=s 【最小长度】 ：lower_bound
int largeKPositiveMinLengthMap(vector<int> &nums, int s) {
    int mi = INT_MAX;
    vector<int> sums(nums.size() + 1, 0);
    for (int i = 1; i < sums.size(); i++) {
        sums[i] = sums[i - 1] + nums[i - 1];
    }
    for (int i = 1; i < sums.size(); i++) {
        auto it = lower_bound(sums.begin(), sums.end(), s + sums[i - 1]); //小于等于
        if (it != sums.end()) {
            int cur = it - sums.begin() - i + 1;
            mi = min(mi, cur);
        }
    }
    return mi == INT_MAX ? 0 : mi;
}

// 【正数】，>=s 【总和】
int largeKPostiveCount(vector<int> &nums, int s) {
    int ma = 0;
    vector<int> sums(nums.size() + 1, 0);
    for (int i = 1; i < sums.size(); i++) {
        sums[i] = sums[i - 1] + nums[i - 1];
    }
    for (int i = 1; i < sums.size(); i++) {
        auto it = upper_bound(sums.begin(), sums.end(), s + sums[i - 1]); //小于等于
        if (it != sums.end()) {
            ma += (sums.end() - it);
        }
    }
    return ma;
}

// 【最大长度】[>=s] == largeKPositiveMinLengthMap
int largeKMaxLength(vector<int> &nums, int s) {
    int ma = INT_MIN;
    vector<int> sums(nums.size() + 1, 0);
    for (int i = 1; i < sums.size(); i++) {
        sums[i] = sums[i - 1] + nums[i - 1];
    }
    for (int i = 1; i < sums.size(); i++) {
        auto it = lower_bound(sums.begin(), sums.end(), s + sums[i - 1]); //小于等于
        if (it != sums.end()) {
            int cur = it - sums.begin() - i + 1;
            ma = max(ma, cur);
        }
    }
    return ma == INT_MIN ? 0 : ma;
}

// 【最小长度】862. 和至少为k的最短子数组
int largeKMinLength(vector<int> &A, int K) {
    deque<int> d;
    int n = A.size();
    vector<int> presum(n + 1, 0);
    for (int i = 1; i < n + 1; i++) {
        presum[i] = presum[i - 1] + A[i - 1];
    }
    int res = INT_MAX;
    for (int i = 0; i <= n; i++) {
        while (!d.empty() && presum[i] - presum[d.front()] >= K) {
            res = min(res, i - d.front());
            d.pop_front();
        }
        while (!d.empty() && presum[i] <= presum[d.back()]) {
            d.pop_back();
        }
        d.push_back(i);
    }
    return res == INT_MAX ? -1 : res;
}

// 【最小值】
int largeKMinSum(vector<int> &nums, int s) {
}

//------------------------------- 小于等于k系列---------------------
// 【<=k】【正数】【总个数】【滑动窗】
int lessKPositiveCountWindow(vector<int> &nums, int k) {
    int res = 0;
    int n = nums.size();
    int left = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += nums[i];
        while (sum >= k && left <= i) {
            sum -= nums[left++];
        }
        res += i - left + 1;
    }
    return res;
}

// 【<=k】【正数】【总个数】【map】
int lessKPositiveCountMap(vector<int> &arr, int k) {
    map<int, int> m;
    m[0] = -1;
    int sum = 0;
    int ma = 0;
    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        auto it = m.upper_bound(sum - k); //小于
        // auto it = m.lower_bound(sum - k); //小于等于
        if (it != m.end()) {
            ma += (i - it->second);
        }
        m[sum] = i;
    }
    return ma;
}

// 【<=k】【总个数】[TODO] 难
int lessKCount(vector<int> &arr, int k) {
}

// 【<=k】【正数】【maxLength】
int lessKMaxLength(vector<int> &arr, int k) {
    map<int, int> m; // key:是前缀和的索引
    m[0] = -1;
    int sum = 0;
    int ma = 0;
    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        // auto it = m.upper_bound(sum - k); //小于
        auto it = m.lower_bound(sum - k); //小于等于
        if (it != m.end()) {
            ma = max(ma, i - it->second);
        }
        m[sum] = i;
    }
    return ma;
}
// 【<=k】【可正可负】【maxLength】
int lessKMaxLength2(vector<int> &arr, int x) {
    int n = arr.size();
    vector<int> h(n + 1, 0);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        h[i + 1] = max(h[i], sum);
    }
    sum = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        int idx = lower_bound(h.begin(), h.end(), sum - x) - h.begin();
        ans = max(ans, i - idx + 1);
    }
    return ans;
}

// 【<=k】【最大值】
int lessKMaxSum(vector<int> &arr, int k) {
    set<int> s;
    s.insert(0); // 这个insert很难想到
    int sum = 0;
    int ma = INT_MIN;
    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        auto it = s.lower_bound(sum - k);
        if (it != s.end()) {
            ma = max(ma, sum - *it);
        }
        s.insert(sum);
    }
    return ma;
}

//------------------------------- 等于k系列---------------------

// -------------------------------- other
// 713. 乘积小于k的个数
int numSubarrayProductLessThanK(vector<int> &nums, int k) {
    int n = nums.size();
    if (n == 0)
        return 0;
    int res = 0, left = 0, prod = 1;
    for (int right = 0; right < n; ++right) {
        prod *= nums[right];
        while (prod >= k && left <= right)
            prod /= nums[left++];
        res += (right - left + 1);
    }
    return res;
}

// 974.和被k整除的子数组
int subarraysDivByK(vector<int> &nums, int K) {
    int n = nums.size();
    vector<int> m(K, 0);
    m[0] = 1; //
    int acc = 0;
    int res = 0;
    for (int i = 0; i < n; i++) {
        acc += nums[i];
        // 要考虑一下负数的mod
        res += m[(acc % K + K) % K]++;
    }
    return res;
}

int main() {
    vector<int> arr = {5, -1, 3, 4};
    // cout << arraySumLessK(arr, 7) << endl;
    // cout << minSubArrayLen() << endl;
    // cout << lessKMinLength(arr, 3) << endl;
    cout << lessKMaxLength(arr, 5) << endl;
    // cout << lessKPositiveCountMap(arr, 5) << endl;
    return 0;
}
