#include <iostream>
#include <stack>
#include <vector>
using namespace std;
/*
There are N children standing in a line. Each child is assigned a rating value.
You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?
*/

//遍历两遍

int candy(vector<int> arr) {
    vector<int> c(arr.size(), 1);

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > arr[i - 1])
            c[i] = c[i - 1] + 1;
    }
    for (int i = arr.size() - 1; i > 0; i--) {
        if (arr[i - 1] > arr[i])
            c[i - 1] = max(c[i - 1], c[i] + 1);
    }
    int res = 0;
    for (auto x : c) {
        res += x;
    }
    return res;
}
