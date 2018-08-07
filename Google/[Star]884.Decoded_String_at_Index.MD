这种只有一种最优解的题，最难想也最容易被google考察。

Input: S = "leet2code3", K = 10
Output: "o"
Explanation: 
The decoded string is "leetleetcodeleetleetcodeleetleetcode".
The 10th letter in the string is "o".

首先把握一个点： 就是如果总长度是K的倍数，那么返回的就是最后一个字母，比如abab，K=2 返回是b
如果不是倍数怎么办，那就从后往前缩短大小，比如abab， K = 3  当aba 时候就


```
string decodeAtIndex(string S, int K) {
    long size = 0;
    int N = S.size();
    // Find size = length of decoded string
    for (int i = 0; i < N; ++i) {
        if (isdigit(S[i]))
            size *= S[i] - '0';
        else
            size++;
    }
    for (int i = N-1; i >=0; --i) {  // 这里是最难想到的，就是i和size的结合
        K %= size;
        if (K == 0 && isalpha(S[i]))
            return (string) "" + S[i];
        if (isdigit(S[i]))
            size /= S[i] - '0';
        else
            size--;
    }
}
```
