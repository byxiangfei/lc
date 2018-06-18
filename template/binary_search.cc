#include <vector>
#include <iostream>
#include <string>
using namespace std;


int lower_bound(vector<int> &nums, int target) {
    int beg = 0, end = nums.size() - 1;
    while(beg <= end) {
        int mid = beg + (end - beg)/2;
        if( nums[mid] < target) {
            beg = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return beg; 
}


int upper_bound(vector<int> &nums, int target) {
    int beg = 0, end = nums.size() - 1;
    while(beg <= end) {
        int mid = beg + (end - beg)/2;
        if( nums[mid] <= target) {
            beg = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return beg; 
}

int longestString(string s) {
    vector<int> m(256, -1);
    int res = 0;
    for(int i = 0; i < s.size(); i++) {
        if(m[s[i]] < 0) m[s[i]] = i;
        else {
           res = max(res, i - m[s[i]] + 1);
        }
    }
    return res;
}

// 给一个数组，n的长度（n >=1），含有所有1 - n的数字，要求得到一个最小的index，
// 满足条件: 如果把数组小于等于index的部分排序好，并且把数组大于index的部分排序好，那么整个数组就排序好了.

int findIdx(vector<int> &nums) {
	int start = 0;
	int end = nums[start];
	for(int i = 0; i < end; i++) {
		if(nums[i] > end) {
			end = nums[i];
		}
	}
	return end - 1;
} 

// find unique num in paired group by binary search
int findSingle(vector<int> nums) {
    int n = nums.size(), lo=0, hi=n/2;
    while (lo < hi) {
        int m = (lo + hi) / 2;
        if (nums[2*m] != nums[2*m+1]) hi = m; // 只要不等就说明前面有问题
        else lo = m+1;          // 如果相等就说明前面没问题了，可以往m+1试了
    }
    return nums[2*lo];
}

int main() {
	//vector<int> a = {1,2,2,3,3,3,4,5};
	//cout<<lower_bound(a,3)<<endl;
	//cout<<lower_bound(a,4)<<endl;
	vector<int> nums = {1,1,2,3,3}; 
	cout<<findSingle(nums)<<endl;
	cout<<(4^1)<<endl;
	//vector<int> a = {2, 4, 3, 1};
	//cout<<findIdx(a)<<endl;
}