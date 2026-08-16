class Solution {
public:

    bool isbipartite(int node,int color,vector<int>&clr,vector<bool>&visited,vector<vector<int>>&adj) {
        visited[node] = true;
        clr[node] = color;

        for(auto ngbr : adj[node]) {
            if(clr[ngbr]==color) return false;
            if(!visited[ngbr]) {
                if(!isbipartite(ngbr,1-color,clr,visited,adj)) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
         vector<vector<int>> adj(graph.size());
        for (int i = 0; i < graph.size(); i++) {
            for (int j = 0; j < graph[i].size(); j++) {
                adj[i].push_back(graph[i][j]);
            }
        }

        vector<bool> visited(graph.size(), false);
        vector<int> color(graph.size(), -1);

        for (int i = 0; i < graph.size(); i++) {
            if (!visited[i]) {
                if (!isbipartite(i,1,color,visited,adj))
                    return false;
            }
        }
        return true;
    }
};