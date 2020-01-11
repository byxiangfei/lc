bool canWin(vector<int> nums, int sum1, int sum2, int player) {
  if (nums.empty())
    return sum1 >= sum2;
  if (nums.size() == 1) {
    if (player == 1)
      return sum1 + nums[0] >= sum2;
    else if (player == 2)
      return sum2 + nums[0] > sum1;
  }
  vector<int> va = vector<int>(nums.begin() + 1, nums.end());
  vector<int> vb = vector<int>(nums.begin(), nums.end() - 1);
  if (player == 1) {
    return !canWin(va, sum1 + nums[0], sum2, 2) ||
           !canWin(vb, sum1 + nums.back(), sum2, 2);
  }
  return !canWin(va, sum1, sum2 + nums[0], 1) ||
         !canWin(vb, sum1, sum2 + nums.back(), 1);
}

// {1,5,2}

// play1 = -1
// https://liuqinh2s.gitbooks.io/leetcode/%E4%B8%AD%E6%96%87%E7%89%88/%E7%AC%AC%E4%B8%80%E9%81%8D/486.%20Predict%20the%20Winner.html
bool canWin(vector<int> nums, int s, int e, int sum1, int sum2, int player) {
  if (player = -1) {
    if (s == e)
      return sum1 >= sum2;
    return !canWin(nums, s + 1, e, sum1 + nums[s], sum2, -player) ||
           !canWin(nums, s, e - 1, sum1 + nums[e], sum2, -player);
  }
  // player == 2
  if (s == e)
    return sum1 >= sum2;
  return !canWin(nums, s + 1, e, sum1, sum2 + nums[s], -player) ||
         !canWin(nums, s, e - 1, sum1, sum2 + nums[e], -player);
}
