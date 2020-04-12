// 利用了快慢指针的原理
// 如果有重复数字，我每次走一步nums[i] 和走两步nums[nums[i]] 是一定会相遇的
// 0, 1, 2, 3, 4
// 1, 3, 2, 4, 3
int findDuplicate(vector<int> &nums) {
    if (nums.size() < 2)
        return -1;
    int slow = nums[0], fast = nums[nums[0]];
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[nums[fast]];
    }
    fast = 0;
    while (fast != slow) {
        fast = nums[fast];
        slow = nums[slow];
    }
    return slow;
}

// 0->1, 1->3, 3->4, 4->3, (3->4 重复,返回3)
int findDuplicate2(vector<int> &nums) {
    set<pair<int, int>> s;
    int t = nums[0];
    s.insert({0, t});
    while (!s.count({t, nums[t]})) {
        s.insert({t, nums[t]});
        t = nums[t];
    }
    return t;
}

// 利用二分查找原理, 每次都数个数
