class Solution {
public:
    void dfs(vector<vector<int>>&adj,int k,vector<bool>&visited) {
        visited[k] = true;
        for(auto ngb:adj[k]) {
            if(!visited[ngb])
                dfs(adj,ngb,visited);
        }
    }

    bool dfscheck(vector<vector<int>>&adj,int node,vector<bool>&visited) {
        for(auto ngbr : adj[node]) {
            if(visited[ngbr]) return true;
        }
        return false;
    }
    
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>>adj(n);
        for(int i = 0;i<invocations.size();i++) {
            int u = invocations[i][0];
            int v = invocations[i][1];
            adj[u].push_back(v);
        }
        vector<bool>visited(n,false);
        dfs(adj,k,visited);
        bool tovisited = false;
        for(int i = 0;i<=n-1;i++) {
            if(!visited[i]) {
                if(dfscheck(adj,i,visited)) {
                    tovisited = true;
                    break;
                }
            }
        }
        vector<int>ans;
        if(tovisited) {
            for(int i = 0;i<n;i++) ans.push_back(i);
        }
        else {
            for(int i = 0;i<n;i++) {
                if(!visited[i]) ans.push_back(i);
            }
        }
        

        return ans;
    }
};