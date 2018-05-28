int longestSubstring(string str) {
    int res = 0;
    int ignored = -1;
    vector<int> m(256, -1);
    for(int i = 0; i < str.size(); i++) {
        ignored = max(m[str[i]], ignored);
        res = max(res, i - ignored);
        m[str[i]] = i;
    }
    return res;
}
