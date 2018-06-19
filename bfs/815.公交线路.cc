/*
我们有一系列公交路线。每一条路线 routes[i] 上都有一辆公交车在上面循环行驶。
例如，有一条路线 routes[0] = [1, 5, 7]，表示第一辆 (下标为0) 
公交车会一直按照 1->5->7->1->5->7->1->... 的车站路线行驶。

假设我们从 S 车站开始（初始时不在公交车上），要去往 T 站。 期间仅可乘坐公交车，求出最少乘坐的公交车数量。返回 -1 表示不可能到达终点车站。
*/


int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
    if(S == T) return 0;
    map<int, vector<int>> m;  // m[bus_stop] = {bus_id,...}
    for(int i = 0; i < routes.size(); i++) {
        for(auto stop: routes[i]) {
            m[stop].push_back(i);
        }
    }
    queue<int> q;  // q[bus_stop]
    q.push(S);
    set<int> visited;   // visited bus_id
   
    int cnt = 0;
    while(!q.empty()) {
        cnt++;
        int s = q.size();    
        for(int i = 0; i < s; i++) {
            int top = q.front(); q.pop();
            vector<int> busIDs = m[top];
            for(auto b : busIDs) {
                if(visited.count(b)) continue;
                visited.insert(b);
                
                for(auto stop : routes[b]) {
                    if(stop == T) return cnt;
                    q.push(stop);
                }
            }                
        }
    }
    return -1;
}