class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>>adj(n);
        vector<int>indegree(n);
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<graph[i].size();j++) {
                   if(!graph[i].empty()) {
                   adj[graph[i][j]].push_back(i);
                   indegree[i]++;
             }
            }
        }
            queue<int>q;
            vector<int>ans;
            for(int i = 0;i<n;i++) {
                if(indegree[i]==0) {
                    q.push(i);
                    ans.push_back(i);
                }
            }

            while(!q.empty()) {
                auto top = q.front();
                q.pop();
                for(auto ngbr : adj[top]) {
                    indegree[ngbr]--;
                    if(indegree[ngbr]==0) {
                        ans.push_back(ngbr);
                        q.push(ngbr);
                    }
                }
            }
           sort(ans.begin(),ans.end());
           return ans;
    }
};