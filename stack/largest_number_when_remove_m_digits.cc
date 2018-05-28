#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
a N digit number, remove M digit and get the largest number
*/
vector<int> removeMdigit(vector<int> nums, int m) {
	vector<int> res;
	int n = nums.size();
	if(n <= m) return res;

	stack<int> s;
	for(int i = 0; i < n; ) {
		if(s.empty() || nums[i] < nums[s.top()]) {   // maintain a decrease stack
			s.push(i++);
			continue;
		}
		int t = s.top(); s.pop();
		res.push_back(t);
		if(--m == 0) break;
	}
	while(m != 0) {
		int t = s.top(); s.pop();
		res.push_back(t);
		m--;
	}
	return res;
}


int main() {
	vector<int> nums = {5,0,4,0,0};
	auto res = removeMdigit(nums, 1);

	for(auto i: res) {
		cout<<i<<" ";
	} 
	cout<<endl;
	return 0;
}