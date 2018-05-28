#include <iostream>
#include <vector>
using namespace std;

int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
   	int lo = matrix[0][0];
   	int hi = matrix[n-1][n-1];
   	while(lo < hi) {
   		int mid = (lo + hi)/2;
   		for(int i = 0; i < n; i++) {
   			int cnt = 0, j = n - 1;
   			while(j >= 0 && matrix[i][j] > mid) j--;
   			cnt += (j+1);
   		}
   		if (cnt < k) {
   			lo = mid + 1;	
   		} else {
   			hi = mid;
   		}
   	}
    return l;
}	
