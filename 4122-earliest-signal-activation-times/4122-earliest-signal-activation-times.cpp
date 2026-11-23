class Solution {
public:
    using ll = long long;
    vector<long long> earliestActivationTimes(int n, vector<vector<int>>& edges, vector<int>& requiredSignals) {
        vector<vector<pair<int,int>>>adj(n);
        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            int d = e[2];

            adj[u].push_back({v, d});
        }

         vector<int> received(n, 0);
        vector<ll> ans(n, -1);
         priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > pq;
        ans[0] = 0;

         for (auto [v, d] : adj[0]) {
            if (v != 0)
                pq.push({d, v});
        }

         while (!pq.empty()) {
            auto [time, u] = pq.top();
            pq.pop();

            if (ans[u] != -1)
                continue;

            received[u]++;

            if (received[u] < requiredSignals[u])
                continue;

            ans[u] = time;
              for (auto [v, d] : adj[u]) {
                if (ans[v] == -1) {
                    pq.push({time + d, v});
                }
            }
         }
         return ans;
    }
};