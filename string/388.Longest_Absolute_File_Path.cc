#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;
//The string "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" represents

vector<string> split(string s, string del) {
	vector<string> res;
	istringstream iss(s);
	string word;
	int pos = 0;
	while((pos = s.find(del)) != string::npos) {
	 	word = s.substr(0, pos);
		s = s.substr(pos+ del.size());
		res.push_back(word);
	}
    res.push_back(s);
	return res;
}


int lengthLongestPath(string input) {
	auto paths = split(input, "\n");
	if(paths.size() == 0) return 0;

	vector<int> lens(paths.size(), 0);
	int level = 0;
	int res = 0;

	for(int i = 0; i < paths.size(); i++) {
		int level = paths[i].find_last_of('\t')+1;  // 有一个t就是第二层
		int len = paths[i].substr(level).size();
		if(paths[i].find(".") != string::npos) {
			res = max(res, lens[level] + len);
		} else {
			lens[level+1]  = lens[level] + len + 1;
		}

	} 
	return res;
}


int main() {
	string input = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\t\t\tfile2.ext\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext";
	//input = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext";
	input = "dir\n     sub.a";
	cout<<lengthLongestPath(input)<<endl;
}