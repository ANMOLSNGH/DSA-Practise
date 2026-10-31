class Solution {
public:
    using v = vector<int>;
    using vv = vector<v>;
    vector<int>depth;
    vv ancestor;

    int M = 1e9 + 7;

    void dfs(int node,int parent,vv&adj,v&visited) {
          visited[node] = true;
          ancestor[node][0] = parent;
          for(auto ngbr:adj[node]) {
            if(!visited[ngbr]) {
                depth[ngbr] = depth[node] + 1;
                dfs(ngbr,node,adj,visited);
            }
          }
    }
    void binarylifting(int colms,int n) {
        for(int j = 1;j<colms;j++) {
            for(int i = 0;i<=n;i++) {
                if(ancestor[i][j-1]!=-1) {
                    ancestor[i][j] = ancestor[ancestor[i][j-1]][j-1];
                }
            }
        }
    }

    int lca(int node1,int node2,int colms) {
        if(depth[node1]<depth[node2]) swap(node1,node2);
        int k = depth[node1] - depth[node2];

        for(int j = 0;j<colms;j++) {
            if(k&(1<<j)) {
                node1 = ancestor[node1][j];
            }
        }

        if(node1==node2) return node1;

        for(int j = colms-1;j>=0;j--) {

            if(ancestor[node1][j] != ancestor[node2][j]) {
                node1 = ancestor[node1][j];
                node2 = ancestor[node2][j];
            }
        }
        int ans = ancestor[node1][0];

        return ans;
    
    }
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size();
        vv adj(n+1);
        v visited(n+1,false);

        v precompute_power(n+1,1);

        for(int i = 1;i<n;i++) {
            precompute_power[i] = (precompute_power[i-1]%M * 2)%M;
        }

        int colms = 0;
        while((1<<colms)<=n) colms++;
        ancestor = vv(n+1,v(colms,-1));
        depth = v(n+1);




        for(int i = 0;i<edges.size();i++) {
            int u = edges[i][0] - 1;
            int v = edges[i][1] - 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(0,-1,adj,visited);
        int m = queries.size();
        v ans(m);



        binarylifting(colms,n);
        for(int i = 0;i<m;i++) {
            int node1 = queries[i][0]-1;
            int node2 = queries[i][1]-1;
            int total = depth[node1] + depth[node2] - 2*depth[lca(node1,node2,colms)];
            int val = (total == 0) ? 0 : precompute_power[total - 1] % M;

            ans[i] = val;

        }
        return ans;
    }
};