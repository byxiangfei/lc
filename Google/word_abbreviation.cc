#include "../common.h"

string abbre(string raw, int cnt) {
    int n = raw.size();
    if (n <= cnt + 2) { // xxx4x == cnt+2
        return raw;
    }
    return raw.substr(0, cnt) + to_string(n - cnt - 1) + raw.substr(n - 1);
}

vector<string> wordsAbbreviation(vector<string> &dict) {
    vector<string>        res(dict.size(), "");
    map<string, set<int>> m;
    for (int i = 0; i < dict.size(); i++) {
        m[ abbre(dict[ i ], 1) ].insert(i);
    }
    for (auto it : m) {
        string key = it.first;
        auto   se  = it.second;
        if (se.size() == 1) {
            res[ *se.begin() ] = key;
            continue;
        }
        Trie *t = new Trie();
        for (auto p : se) {
            t->insert(dict[ p ]);
        }
        for (int p : se) {
            int idx = t->query(dict[ p ]);
            // cout<<"word:"<<dict[p]<<" idx:"<<idx<<endl;
            res[ p ] = abbre(dict[ p ], idx + 1);
        }
    }
    return res;
}
