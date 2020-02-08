#include "common.h"

/*
https://leetcode.com/problems/heaters/

Starting from the lowest position house, we find the minimum distance heater to use.
Since the heaters are sorted we know that if the next heater is closer or equal in distance than the current one we can use that one instead,
and it will be closer for all remaining houses since the remaining houses are farther right.
We check if it's equal because it is possible a closer choice will be after the equal distance one.
*/

int findRadius(vector<int>& houses, vector<int>& heaters) {
    if (heaters.size() == 0) {
        return 0;
    }
    sort(houses.begin(), houses.end());
    sort(heaters.begin(), heaters.end());
    int radius = 0;
    int index = 0;
    for (int i = 0; i < houses.size(); i++) {
        while (index + 1 < heaters.size() && (abs(heaters[index+1] - houses[i]) <= abs(heaters[index] - houses[i]))) {
            index++;
        }
        radius = max(radius, abs(heaters[index] - houses[i]));
    }
    return radius;
}
