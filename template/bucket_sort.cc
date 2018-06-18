#include <iostream>
#include <vector>
using namespace std;

void bucket_sort(vector<int> arr) {
	int max_a = INT_MIN;
	int min_a = INT_MAX;
	for(auto a : arr) {
		max_a = max(max_a, a);
		min_a = min(min_a, a);
	}
	int b_cap =(max_a - min_a) / arr.size() + 1;
	int b_num = (max_a - min_a) / b_cap + 1;
	vector<vector<int>> buckets(b_num, vector<int>({})); 

	for(auto a : arr) {
		int idx = (a - min_a)/b_cap;
		buckets[idx].push_back(a); 
	}

	for(auto b : buckets) {
		for(auto i : b) {
			cout<<i<<" ";
		}
		cout<<endl;
	}
	return;
}


int main() {
	vector<int> arr = {4,3,5,10,2};
	bucket_sort(arr);
	return 0;
}