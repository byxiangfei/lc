#include "../common.h"

int scoreOfParentheses(string S) {
    if (S.size() == 0)
        return 0;
    if (S.size() == 2)
        return 1;

    int        right = 1;
    stack<int> st;
    st.push(0);

    for (; right < S.size(); right++) {
        if (S[ right ] == ')') {
            st.pop();
            if (st.empty()) {
                break;
            }
        } else {
            st.push(right);
        }
    }
    if (right == S.size() - 1) {
        cout << "next:" << S.substr(1, right - 1) << endl;
        int res = 2 * scoreOfParentheses(S.substr(1, right - 1));
        return res;
    }
    cout << "next1:" << S.substr(0, right + 1) << endl;
    cout << "next2:" << S.substr(right + 1) << endl;
    int res = scoreOfParentheses(S.substr(0, right + 1)) + scoreOfParentheses(S.substr(right + 1));
    return res;
}

/*
借鉴别人的 (()(())) = (()) + ((())) , 且  分数 = 2^(层数-1)
出现 '(' 代表层数+1 ， 出现 ')' 代表层数 -1
*/
int scoreOfParentheses2(string S) {
    int deep = 0, ans = 0;
    for (int i = 0; i < S.length(); i++) {
        if (S[ i ] == '(')
            deep++;
        else
            deep--;
        if (S[ i ] == ')' && S[ i - 1 ] == '(')
            ans += 1 << deep;
    }
    return ans;
}

int main() {
    cout << "res:" << scoreOfParentheses2("(()())()") << endl;
    return 0;
}
