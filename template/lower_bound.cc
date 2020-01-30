#include <iostream>
#include <set>
using namespace std;
int main() {
    std::set<int>           myset;
    std::set<int>::iterator itlow, itup;

    for (int i = 1; i < 10; i++)
        myset.insert(i * 10); // 10 20 30 40 50 60 70 80 90

    itlow = myset.lower_bound(40); //       ^
    itup  = myset.upper_bound(40); //                   ^

    cout << *itlow << endl;
    cout << *itup << endl;

    myset.erase(itlow, itup); // 10 20 70 80 90

    std::cout << "myset contains:";
    for (std::set<int>::iterator it = myset.begin(); it != myset.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';

    return 0;
}
