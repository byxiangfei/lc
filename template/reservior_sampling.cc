#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;


int pick(vector<int> &nums) {
	double wSum = 0, res = 0;
	vector<int> m(256, 0);
	auto it = nums.begin();
	while(it != nums.end()) {
		m[*it]++;
		wSum += m[*it];
		int ra = rand() % wSum;
		if(ra < m[*it]) res = *it;
		it++;
	}
	return res;
}


int main() {
	vector<int> a = {1,2,2,2,3};
	// 第三轮时选中的仍然是2的概率
	// 1/2 +  1/2 * 1/2 = 3/4
	// 3/4 +  1/4 * 3/7 = 6/7
	cout<<pick(a);

}