class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        int e =  prerequisites.size();
        vector<vector<int>>adj(n);
        vector<int>ans;
        vector<int>indegree(n);
        for(int i = 0;i<e;i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[v].push_back(u);
            indegree[u]++;
        }
        int cnt = 0;
        queue<int>q;
        for(int i = 0;i<n;i++) {
            if(indegree[i]==0) {
                q.push(i);
                ans.push_back(i);
                cnt++;
            }
        }

        while(!q.empty()) {
           auto top = q.front();
           q.pop();
           for(auto ngbr : adj[top]) {
            indegree[ngbr]--;
            if(indegree[ngbr]==0) {
                q.push(ngbr);
                ans.push_back(ngbr);
                cnt++;
            }
           }
        }
        if(cnt==n) return ans;
        return {};

    }
};