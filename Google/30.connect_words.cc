#include "../common.h"

vector<int> findSubstring(string s, vector<string> &words) {
    if (words.empty())
        return {};
    vector<int>      res;
    int              wl = words[ 0 ].size();
    int              ws = words.size();
    int              sl = s.size();
    map<string, int> m;
    map<string, int> curM;
    for (auto w : words)
        m[ w ]++;

    for (int i = 0; i < wl; i++) {
        curM.clear();
        int j = i;
        int k = i;
        for (; j <= sl - wl * ws;) {
            while (k < j + wl * ws) {
                auto tmp = s.substr(k, wl);
                k += wl;
                if (!m.count(tmp)) {
                    j = k;
                    curM.clear();
                    break;
                }
                if (curM[ tmp ] == m[ tmp ]) {
                    while (curM[ tmp ] == m[ tmp ]) {
                        curM[ s.substr(j, wl) ]--;
                        j += wl;
                    }
                    break;
                }
                curM[ tmp ]++;
            }
            if (k == j + wl * ws) {
                curM[ s.substr(j, wl) ]--;
                res.push_back(j);
                cout << "res:" << j << " ";
                j += wl;
            }
        }
    }
    return res;
}

vector<int> findSubstring2(string s, vector<string> &words) {
    if (words.empty())
        return {};
    unordered_map<string, int> wordmap, smap;
    for (string word : words)
        wordmap[ word ]++;
    int         wordlen = words[ 0 ].size();
    int         wordnum = words.size();
    vector<int> ans;
    for (int k = 0; k < wordlen; k++) {
        int i = k, j = k;
        while (i < s.size() - wordnum * wordlen + 1) {
            while (j < i + wordnum * wordlen) {
                string temp = s.substr(j, wordlen);
                smap[ temp ]++;
                j += wordlen;
                if (wordmap[ temp ] == 0) { //情况二，有words中不存在的单词
                    i = j;                  //对i加速
                    smap.clear();
                    break;
                }
                if (smap[ temp ] > wordmap[ temp ]) { //情况三，子串中temp数量超了
                    while (smap[ temp ] > wordmap[ temp ]) {
                        smap[ s.substr(i, wordlen) ]--;
                        i += wordlen; //对i加速
                    }
                    break;
                }
            }
            //正确匹配，由于情况二和三都对i加速了，不可能满足此条件
            if (j == i + wordlen * wordnum) {
                ans.push_back(i);
                cout << "res:" << i << " ";
                smap[ s.substr(i, wordlen) ]--;
                i += wordlen; // i正常前进
            }
        }
        smap.clear();
    }
    return ans;
}

int main() {
    string         a  = "abcfoodeffoobarabc";
    vector<string> ws = {"foo", "bar", "abc", "def"};
    findSubstring(a, ws);
    return 0;
}
