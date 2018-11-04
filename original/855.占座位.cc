//https://leetcode.com/problems/exam-room/

#include "common.h"

set<int> seats;
int size = 5;  //总长度

int seat() {
    if(seats.size() == 0) {// no one in the room
        seats.insert(0);
        return 0;
    }
    int res = 0;
    int maxLen = 0;
    // no one sit on the 0
    if(!seats.count(0)) {
        maxLen = *seats.begin();
    }
    int pre = 0; //记录上一个人的位置
    for(auto it = seats.begin(); it != seats.end(); it++) {
        int len = (*it - pre) / 2;
        if(len > maxLen) {
            maxLen = len;
            res = (*it + pre) / 2;
        }
        pre = *it;
    }
    // 最后的位置没有被占
    if(!seats.count(size - 1)) {
        int len = size - 1 - *seats.rbegin();
        if(len > maxLen) {
            maxLen = len;
            res = size - 1;
        }
    }
    seats.insert(res);
    return res;
}
