#include <iostream>
#include <time.h>
#include <algorithm>
using namespace std;

#define N 10

void print(int *a, int n) {
    for (int i = 0; i < N; i++) {
        cout << a[i] << " ";
    }
    cout<<endl;
}
/*
调整堆：默认最大堆，每次调整结束后，堆顶即为最大值。
类似于：向上冒泡的过程。
*/
void maxheapfixdown(int a[], int i, int n){
    // check children, iterately
    for (int j = 2 * i + 1; j < n; j = 2 * i + 1){
        if (j + 1 < n && a[j] < a[j+1]) ++j;  //左还是右
        if (a[j] < a[i])  // 最大的都比 a[i] 小，就不换了
            break;
        swap(a[i], a[j]);
        i = j;
    }
}
/*
堆排序：1. 建堆 2. n-1次调整和n-1次swap()
*/
void heap_sort(int a[], int n){
    for (int i = n / 2  - 1; i >= 0; --i) {
        maxheapfixdown(a, i, n);//建堆，从末尾的第一个非叶节点，即i=(n-2)/2处开始。
    }
    // 建堆时相当于完成了一次堆调整，还需要n-1次堆调整。
    for (int k = 1; k <= n - 1; ++k) {
        swap(a[0], a[n - k]);//上次调整完之后，把最大值放到末尾。
        maxheapfixdown(a, 0, n-k);
    }
}



int main() {
    srand((unsigned)time(NULL));
    int a[N];
    for (int i = 0; i < N; i++) {
        a[i] = rand() % (N + 1);
    }
    print(a, N);
    heap_sort(a, N);
    print(a, N);
    return 0;
}
