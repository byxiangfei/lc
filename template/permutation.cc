#include <vector>
#include <string>
#include <iostream>

using namespace std;

void permutation(vector<string>& res, vector<char> nums, int start) {
	if(start == nums.size()) {
		string one = "";
		for(auto n: nums) {
			one.push_back(n);
		}
		res.push_back(one);
		return;
	}

	for(int i = start; i < nums.size(); i++) {
		swap(nums[i], nums[start]);
		permutation(res, nums, start+1);
		//swap(nums[i], nums[start]);
	}

}

// abc acb bac bca cba cab 


int main() {
	vector<string> res;
	vector<char> nums = {'a','b','c'};

	permutation(res, nums, 0);

	for(auto r : res) {
		cout<<r<<" ";
	}
	cout<<endl;
	return 0;
}