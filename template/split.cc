#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>


vector<string> split(string str, char del) {
	vector<string> res;
	istringstream iss(str);
	string item;
	while(getline(iss, item, del)) {
		res.push_back(item);
	}
	return res;
}

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


// https://stackoverflow.com/questions/236129/the-most-elegant-way-to-iterate-the-words-of-a-string
int main() {	
	auto v = split("hello\tworld", '\t');
	for (auto i : v) cout<<i<<endl;
	return 0;
}