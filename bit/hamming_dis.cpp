#include <iostream>
using namespace std;

int hammingDistance(int x, int y) {
    int res = 0;
    while (x > 0 || y > 0) {
        if ((x & 1) != (y & 1)) {
            res++;
        }
        if (x > 0)
            x = x >> 1;
        if (y > 0)
            y = y >> 1;
    }
    return res;
}

int main() {
    cout << hammingDistance(1, 4);
    return 0;
}
