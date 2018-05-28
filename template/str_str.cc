// http://blog.csdn.net/starstar1992/article/details/54913261
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> nex(string needle) {
	int n = needle.size();
	vector<int> arr(n, 0);
    arr[0] = -1;
	int j = 0, k = -1;
	while(j < n - 1) {
		if(k == -1 || needle[j] == needle[k]) {
            arr[++j] = ++k;
		} else {
			k = arr[k];
		}
	}
	return arr;
}


int strStr(string haystack, string needle) {
	int m = haystack.size();
	int n = needle.size();
    auto next = nex(needle);
    int l = 0; // hay
    int s = 0; // short
    while(l < m) {
        if(s == -1 || haystack[l] == needle[s]) {
            l++; s++;
            if(s == n) {
                return l - s;
            }
        } else {
            s = next[s];
        }
    }
	return -1;
}
int main() {
	//cout<<strStr("hello", "ll")<<endl;
	vector<int> arr = nex("abaaabab");
	for(auto a: arr) {
		cout<<a<<" ";
	}
	cout<<endl;
	return 0;
}
