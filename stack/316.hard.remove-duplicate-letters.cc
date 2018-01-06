/*
 [316] Remove Duplicate Letters

https://leetcode.com/problems/remove-duplicate-letters

* algorithms
* Hard (29.99%)


Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.



Example:


Given "bcabc"
Return "abc"


Given "cbacdcbc"
Return "acdb"
*/

string removeDuplicateLetters(string s) {
    vector<int> m(256,0);
    for(auto c: s) {
        m[c]++;
    }
    
    vector<bool> visited(256, false);
    string res = "";
    for(auto c : s) {
        m[c]--;
        if(visited[c]) continue;
        // res.back() 未来还有， 当前c比它还小
        while( c < res.back() && m[res.back()] ){
            visited[res.back()] = false;
            res.pop_back();
        }
        res +=c;
        visited[c] = true;
    }
    return res;
}
