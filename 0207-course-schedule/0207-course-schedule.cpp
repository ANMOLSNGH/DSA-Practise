class Solution {
public:
    bool iscycle(int node,vector<bool>&visited,vector<bool>&inrecur,vector<vector<int>>&adj) {
        visited[node] = true;
        inrecur[node] = true;

        for(auto ngbr : adj[node]) {
            if(visited[ngbr]&&inrecur[ngbr]) return true;

            else if(!visited[ngbr]) {
                if(iscycle(ngbr,visited,inrecur,adj)) return true;
            }
        }
        inrecur[node] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int s = numCourses;
        int n = prerequisites.size();
        vector<vector<int>>adj(s);

        for(int i = 0;i<n;i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[v].push_back(u);
        }

        vector<bool>inrecur(s);
        vector<bool>visited(s);
        bool hascycle = false;
        for(int i = 0;i<s;i++) {
            if(!visited[i]) {
                if(iscycle(i,visited,inrecur,adj)) {
                    hascycle = true;
                    break;
                }
            }
        }
        return !hascycle;
    }
};