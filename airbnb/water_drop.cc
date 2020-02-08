#include <vector>
#include <set>
using namespace std;

vector<int> pourWater(vector<int>& heights, int V, int K) {
    vector<int> water(heights.size(), 0);
    for (int i = 0; i < V; ++i) {
        int l = K, r = K, n = heights.size();
        while (l > 0 && heights[l] + water[l] >= heights[l - 1] + water[l-1]) --l;
        while (l < K && heights[l] + water[l] == heights[l + 1] + water[l+1]) ++l;
        while (r < n - 1 && heights[r] + water[r] >= heights[r + 1] + water[r+1]) ++r;
        while (r > K && heights[r] + water[r] == heights[r - 1] + water[r-1]) --r;
        if (heights[l] + water[l] < heights[K] + water[K]) {
            water[l]++;
        } else {
            water[r]++;
        }
    }
    return water;
}

int main() {
    vector<int> heights = {3,3,2,1,2,3};

    auto res = pourWater(heights, 6, 2);
    for (auto r: res) {
        cout<<r<<" ";
    }
}
