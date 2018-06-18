#include <iostream>
#include <vector>
using namespace std;


void quick_sort(vector<int> &arr, int beg, int end) {
	if(beg >= end) return;
	int b = beg, e = end, p = arr[b];
	while(beg < end) {
		while(beg < end && p <= arr[end]) {   // find the first small
			end--;
		}
		while(beg < end && arr[beg] <= p) {
			beg++;  // find the first big
		}
		cout<<beg<<" "<<end<<endl;
		swap(arr[beg], arr[end]);
	}
	swap(arr[beg], arr[b]);
	quick_sort(arr, b, beg-1);
	quick_sort(arr, beg+1, e);
}




int main() {
	vector<int> arr = {4,1,2,3,4,5,6,7,8};  // 4, 1, 3, 6
	quick_sort(arr, 0, arr.size() - 1);
	for(auto a: arr){
		cout<<a<<" ";
	}
	return 0;
}