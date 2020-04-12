#include <iostream>
#include <vector>
using namespace std;

vector<int> tree;

void build(vector<int> &nums, int pos, int l, int r) {
    if (l == r) {
        tree[pos] = nums[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(nums, (pos << 1) + 1, l, mid);
    build(nums, (pos << 1) + 2, mid + 1, r);
    tree[pos] = tree[(pos << 1) + 1] + tree[(pos << 1) + 2];
}

int query(int pos, int l, int r, int qi, int qj) {
    if (qi > r || qj < l)
        return 0;
    // if current pos in query range, return pos
    if (qi <= l && r <= qj) {
        return tree[pos];
    }
    //分别从左右子树查询，返回两者查询结果的较小值
    int mid = (l + r) >> 1;
    return query((pos << 1) + 1, l, mid, qi, qj) + query((pos << 1) + 2, mid + 1, r, qi, qj);
}
// update 某个点
void update() {
}

// 区间更新是 线段数的精华

int main() {
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    tree.resize(4 * nums.size(), 0);

    build(nums, 0, 0, nums.size() - 1);

    for (auto t : tree)
        cout << t << " ";
    cout << endl;

    cout << query(0, 0, nums.size() - 1, 0, 3) << endl;
    return 0;
}
