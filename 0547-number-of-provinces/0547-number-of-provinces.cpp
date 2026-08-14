class Solution {
public:
    void dfs(int node,vector<bool>&visited,vector<vector<int>>&adj) {
        visited[node] = true;

        for(auto ngbr : adj[node]) {
            if(!visited[ngbr]) {
                dfs(ngbr,visited,adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>>adj(n+1);

        for(int i = 0;i<n;i++) {
            for(int j = 0;j<isConnected[i].size();j++) {
                if(i==j) continue;
                if(isConnected[i][j]==1) {
                    adj[i+1].push_back(j+1);
                }
            }
        }
        int cnt = 0;
        vector<bool>visited(n+1,false);
        for(int i = 0;i<n;i++) {
            if(!visited[i+1]) {
             dfs(i+1,visited,adj);
             cnt++;
            }
        }
        return cnt;
    }
};