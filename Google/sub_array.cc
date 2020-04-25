#include "../common.h"

int getlen(vector<int> &arr, int x) {
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

int lessKMaxLength(vector<int> &arr, int k) {
    map<int, int> m;
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

int main() {
    vector<int> arr = {10, -10, 5, 4, 1};
    cout << getlen(arr, 12) << endl;
    cout << lessKMaxLength(arr, 12) << endl;
}
