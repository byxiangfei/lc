输入是一个正整数数组，有两个 player， 可以从数组的两端取走一个数， 两个玩家交替这样，问 player1能不能赢
e.g [1,5,2], player1 will never win

思路1：递归想法，如果 player1能不能赢，取决于上一次 player2能不能输

```
//player1 = 1, player2 = -1
bool canWin(vector<int> nums, int sum1, int sum2, int player) {
    if (nums.empty()) return sum1 >= sum2;
    if (nums.size() == 1) {
        return player == 1? sum1 + nums[0] >= sum2: sum2 + nums[0] > sum1;
    }

    vector<int> va = vector<int>(nums.begin() + 1, nums.end());
    vector<int> vb = vector<int>(nums.begin(), nums.end() - 1);
    if (player == 1) {
        return !canWin(va, sum1 + nums[0], sum2, -player) || !canWin(vb, sum1 + nums.back(), sum2, -player);
    }
    // 对于 player 胜利的条件和 player1是一样的
    return !canWin(va, sum1, sum2 + nums[0], -player) || !canWin(vb, sum1, sum2 + nums.back(), -player);
}
```

思路2：dp, 初始化 dp[s][e] 是从s到 e, player1 能胜利的 diff， gain + lose (-other)

dp[s][e] = max(nums[s] - canWin(nums, s+1, e, dp)  // 自己去 s，然后剩余的让另外一个取一个最小的

So assuming the sum of the array it SUM, so eventually player1 and player2 will split the SUM between themselves. 
For player1 to win, has to get more than what player2 gets. If we think from the prospective of one player, 
then what he/she gains each time is a plus, while, what the other player gains each time is a minus. 
Eventually if player1 can have a >0 total, player1 can win.

Helper function simulate this process. In each round:
if e==s, there is no choice but have to select nums[s]
otherwise, this current player has 2 options:
--> nums[s]-helper(nums,s+1,e): this player select the front item, leaving the other player a choice from s+1 to e
--> nums[e]-helper(nums,s,e-1): this player select the tail item, leaving the other player a choice from s to e-1

```
bool PredictTheWinner(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return canWin(nums, 0, n - 1, dp) >= 0;
}
int canWin(vector<int>& nums, int s, int e, vector<vector<int>>& dp) {
    if (dp[s][e] == -1) {
        dp[s][e] = (s == e) ? nums[s] : max(nums[s] - canWin(nums, s + 1, e, dp), nums[e] - canWin(nums, s, e - 1, dp));
    }
    return dp[s][e];
}
```

https://leetcode.com/problems/predict-the-winner/discuss/96838/java-1-line-recursion-solution
