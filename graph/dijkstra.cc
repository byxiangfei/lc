
#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9; // int范围约为 (-2.15e9, 2.15e9)

/*Dijkstra算法解决的是单源最短路径问题，即给定图G(V,E)和起点s(起点又称为源点),边的权值为非负，
求从起点s到达其它顶点的最短距离，并将最短距离存储在矩阵d中
o(n^3)
*/
void Dijkstra(int n, int s, vector<vector<int>> G, vector<bool> &vis, vector<int> &d,
              vector<int> &pre) {
    /*
     *   n:        顶点个数
     *   s:        源点
     *   G:        图的邻接矩阵
     * vis:        标记顶点是否已被访问
     *   d:        存储源点s到达其它顶点的最短距离
     * pre:        最短路径中v的前驱结点
     */

    // 初始化
    fill(vis.begin(), vis.end(), false);
    fill(d.begin(), d.end(), INF);
    d[ s ] = 0;
    for (int i = 0; i < n; ++i) {
        pre[ i ] = i;
    }
    // n次循环,确定d[n]数组
    for (int i = 0; i < n; ++i) {
        // 找到距离s最近的点u,和最短距离d[u]
        int u   = -1;
        int MIN = INF;
        for (int j = 0; j < n; ++j) {
            if (!vis[ j ] && d[ j ] < MIN) {
                u   = j;
                MIN = d[ j ];
            }
        }
        // 找不到小于INF的d[u],说明剩下的顶点与起点s不连通
        if (u == -1) {
            return;
        }
        vis[ u ] = true;
        for (int v = 0; v < n; ++v) {
            // 遍历所有顶点，如果v未被访问 && 可以达到v && 以u为中介点使d[v]更小
            if (!vis[ v ] && G[ u ][ v ] != INF && d[ u ] + G[ u ][ v ] < d[ v ]) {
                d[ v ]   = d[ u ] + G[ u ][ v ]; // 更新d[v]
                pre[ v ] = u;                    // 记录v的前驱顶点为u（新添加）
            }
        }
    }
}

// 输出从起点s到顶点v的最短路径
void DFSPrint(int s, int v, vector<int> pre) {
    if (v == s) {
        cout << s << " ";
        return;
    }
    DFSPrint(s, pre[ v ], pre);
    cout << v << " ";
}

typedef pair<int, int> ii;
vector<vector<ii>>     a;
vector<int>            d;
vector<int>            pre;

// https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-priority_queue-stl/
void dijkstra(int s, int n) {
    d.resize(n, INT_MAX);
    pre.resize(n, -1);
    d[ s ] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> Q;
    Q.push({d[ s ], s});
    while (!Q.empty()) {
        auto [ dd, u ] = Q.top();
        Q.pop();
        if (dd != d[ u ])
            continue;
        for (auto &[ v, w ] : a[ u ]) {
            if (d[ v ] > d[ u ] + w) {
                d[ v ]   = d[ u ] + w;
                pre[ v ] = u;
                Q.push({d[ v ], v});
            }
        }
    }
}

string happy(int n, vector<vector<int>> &roads, vector<string> &codes) {
    a.resize(n);
    for (auto &road : roads) {
        int u = road[ 0 ], v = road[ 1 ], w = road[ 2 ];
        a[ u ].emplace_back(v, w);
        a[ v ].emplace_back(u, w);
    }
    int s = 11, t = 0;
    dijkstra(s, t, n);
    vector<string> cities;
    for (int u = t; u != -1; u = pre[ u ]) {
        cities.emplace_back(codes[ u ]);
    }
    reverse(cities.begin(), cities.end());
    string ret;
    for (auto &it : cities)
        ret += it;
    return ret;
}

int main() {
    int n = 6;
    /*邻接矩阵*/
    vector<vector<int>> G = {{0, 4, INF, INF, 1, 2}, {4, 0, 6, INF, INF, 3}, {INF, 6, 0, 6, INF, 5},
                             {INF, INF, 6, 0, 4, 5}, {1, INF, INF, 4, 0, 3}, {2, 3, 5, 5, 3, 0}};
    vector<bool>        vis(n);
    vector<int>         d(n);
    vector<int>         pre(n);

    Dijkstra(n, 0, G, vis, d, pre);

    for (size_t i = 0; i < d.size(); ++i) {
        cout << "the shortest path " << i << " is: " << d[ i ] << endl;
    }
    cout << endl;

    // v = 2: 0->5->2  cost = 2 + 5 = 7
    // v = 3: 0->4->3  cost = 1 + 4 = 5
    int v = 2;
    DFSPrint(0, v, pre);
    cout << endl << "cost = " << d[ v ] << endl;

    return 0;
}
