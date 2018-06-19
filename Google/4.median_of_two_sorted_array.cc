#include <iostream>
#include <vector>
using namespace std;

double findK(vector<int> num1, vector<int> num2, int K) {
    int l1 = num1.size();
    int l2 = num2.size();
    if(l2 < l1) return findK(num2, num1, K);
    if(l1 == 0) return num2[K-1]; 
    if(K == 1) return min(num1[0], num2[0]);
    int k1 = min(l1, K/2);
    int k2 = K - k1;

    if(num1[k1-1] < num2[k2-1]) {
    	num1.erase(num1.begin(), num1.begin() + k1);
    	return findK(num1, num2, K - k1);
    }     	
    num2.erase(num2.begin(), num2.begin() + k2);
    return findK(num1, num2, K - k2);
}

