void genPaths(const string &word, const string& beginWord, const unordered_map<string, unordered_set<string>> &parents, vector<string> &acc, vector<vector<string>> &res) {
    if (word == beginWord) {
        auto path = acc;
        path.push_back(beginWord);
        reverse(path.begin(), path.end());
        sln.push_back(path);
    } else {
        acc.push_back(word);
        for (auto &w : parents.at(word)) {
            genPaths(w, beginWord, parents, acc, res);
        }
        acc.pop_back();
    }
}

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    // convert for O(1) word presence lookup.
    unordered_set<string> dict(wordList.begin(), wordList.end());

    // the standard BFS bookkeeping. we treat each word as a graph node.
    queue<string> q;
    unordered_set<string> visited;

    // initialize BFS
    q.push(beginWord);
    visited.insert(beginWord);

    // during BFS, this map records the parent word nodes for each word W,
    // those parents are the words that can transform to word W.
    unordered_map<string, unordered_set<string>> parents;

    while (!q.empty()) {
        // each iteration of the while loop proccess a complete BFS level.
        // save the current level node count because we will push new
        // nodes after visiting the current level nodes.
        auto lvl_count = q.size();

        // if we discover endWord, then we discovered the shortest path.
        // break from the loop after visiting all nodes in the current level.
        // going levels deeper in BFS has no value.
        bool finished = false;
        unordered_set<string> lvl_visited;

        // the next lvl_count nodes in the queue are exactly the nodes in the
        // current level.
        for (int i = 0; i < lvl_count; ++i) {
            auto curr = q.front();
            q.pop();

            // generate all possible transformations for W.
            string w = curr;
            for (int j = 0; j < w.size(); ++j) {
                char cw = w[j];
                for (char c = 'a'; c <= 'z'; ++c) {
                    w[j] = c;
                    // skip invalid transformations.
                    if (!dict.count(w) || visited.count(w)) continue;
                    // record how we reached this node to help us
                    // building the shortest path later.
                    parents[w].insert(curr);

                    // this level has the answer.
                    if (w == endWord) finished = true;
                    else if (lvl_visited.count(w) == 0) {
                        q.push(w);
                        lvl_visited.insert(w);
                    }
                }
                w[j] = cw;
            }
        }
        if (finished) break;
        visited.insert(lvl_visited.begin(), lvl_visited.end());
    }

    vector<vector<string>> res;
    // if the endWord has no parent, then it is unreachable and there is no
    // path discovered from beginWord to endWord.
    if (!parents[endWord].empty()) {
        vector<string> acc;
        genPaths(endWord, beginWord, parents, acc, res);
    }
    return res;
}
