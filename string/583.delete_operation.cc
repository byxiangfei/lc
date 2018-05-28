#include <iostream>
#include <string>
#include <vector>
using namespace std;

int minDistance(string word1, string word2) {
	vector<int> m(256,0);
	for(auto w : word1) {
		m[w]++;
	}
	for(auto w: word2) {
		m[w]++;
	}

	int res = 0;
	for(auto w: m) {
		if(w % 1) res++;
	}

	int i = 0, j = 0;

	while(i < word2.size() && j < word2.size()) {
		if (m[word1[i]] == 1) i++;
		else if (m[word2[j]] == 1) j++;
		else if (word1[i] == word2[j]) {i++; j++;}
		else {
			res++;
			j++;
		}
	}

	res += (word1.size() - i);
	return res;
}

int main() {
	cout<<minDistance("aebea","eaabe")<<endl;
	return 0;
}

