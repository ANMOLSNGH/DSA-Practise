class Solution {
public:
    int mod = 1e9+7;

    // Fixed DFS with Memoization
    int totalpaths(int node, vector<long long>& dist, vector<vector<pair<int, long long>>>& adj, int dst, vector<int>& memo) {
        // Base case: Reached the destination
        if(node == dst) {
            return 1;
        }
        
        // If we have already calculated the ways from this node, return it
        if(memo[node] != -1) {
            return memo[node];
        }

        long long cnt = 0;
        for(auto [ngbr, wt] : adj[node]) {
            // Only travel down this edge if it is strictly part of a shortest path
            if(dist[node] + wt == dist[ngbr]) {
                cnt = (cnt + totalpaths(ngbr, dist, adj, dst, memo)) % mod;
            }
        }
        
        // Save to memo and return
        return memo[node] = cnt;
    }

    int countPaths(int n, vector<vector<int>>& roads) {
        // Use long long for weights to prevent overflow
        vector<vector<pair<int, long long>>> adj(n);
        for(int i = 0; i < roads.size(); i++) {
            int u = roads[i][0];
            int v = roads[i][1];
            long long wt = roads[i][2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        // Use long long for distances
        vector<long long> dist(n, LONG_MAX);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        
        pq.push({0, 0});
        dist[0] = 0;
        
        // 1. Run Dijkstra completely to populate the dist array
        while(!pq.empty()) {
            auto [dis, node] = pq.top();
            pq.pop();

            // Optimization: skip outdated pairs in the priority queue
            if(dis > dist[node]) continue;

            for(auto [ngbr, wt] : adj[node]) {
                if(dis + wt < dist[ngbr]) {
                    dist[ngbr] = dis + wt;
                    pq.push({dist[ngbr], ngbr});
                }
            }
        }
        
        // 2. DFS to count valid paths using the dist array
        vector<int> memo(n, -1);
        return totalpaths(0, dist, adj, n - 1, memo);
    }
};