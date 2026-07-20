class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        unordered_set<int>mpp(restricted.begin(),restricted.end());
        vector<vector<int>>adj(n);

        for(int i = 0;i<edges.size();i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int cnt = 1;
        queue<int>q;
        if(mpp.count(0)) return 0;

        q.push(0);
        mpp.insert(0);
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(auto ngbr : adj[node]) {
                if(!mpp.count(ngbr)) {
                    mpp.insert(ngbr);
                    q.push(ngbr);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};