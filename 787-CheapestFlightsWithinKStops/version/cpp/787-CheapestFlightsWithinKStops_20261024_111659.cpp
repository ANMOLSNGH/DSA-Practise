// Last updated: 10/24/2026, 11:16:59 AM
1class Solution {
2public:
3    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
4        vector<vector<pair<int, int>>> adj(n);
5        for (auto& f : flights) adj[f[0]].push_back({f[1], f[2]});
6
7        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));
8        
9        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
10
11        dist[src][0] = 0;
12        pq.push({0, src, 0});
13
14        while (!pq.empty()) {
15            auto [cost, u, stops] = pq.top();
16            pq.pop();
17
18            if (u == dst) return cost;
19            if (stops > k) continue;
20
21            if (cost > dist[u][stops]) continue;
22
23            for (auto& [v, wt] : adj[u]) {
24                if (cost + wt < dist[v][stops + 1]) {
25                    dist[v][stops + 1] = cost + wt;
26                    pq.push({cost + wt, v, stops + 1});
27                }
28            }
29        }
30
31        return -1;
32    }
33};