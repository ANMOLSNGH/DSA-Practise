class Solution {
public:
    using v = vector<int>;
    using vv = vector<v>;
    vv ancestor;
    v intime, outtime, eulerPath, depth;
    int timer;
    v segt;
    int n;

    void dfs(int node, int parent, vv &adj, string &s) {
         intime[node] = timer;
         eulerPath[timer] = 1 << (s[node] - 'a');
         ancestor[node][0] = parent;
         timer++;

         for(auto &ngbr : adj[node]) {
             if(ngbr == parent) continue;

             depth[ngbr] = depth[node] + 1;
             dfs(ngbr, node, adj, s);
         }

         outtime[node] = timer;
         eulerPath[timer] = 1 << (s[node] - 'a');
         timer++;
    }

    void buildSegt(int indx, int low, int high) {
        if(low == high) {
            segt[indx] = eulerPath[low];
            return;
        }

        int mid = low + (high - low) / 2;

        buildSegt(2 * indx + 1, low, mid);
        buildSegt(2 * indx + 2, mid + 1, high);

        segt[indx] = segt[2 * indx + 1] ^ segt[2 * indx + 2];
    }

    void updateSegt(int node, int indx, int val, int low, int high) {
        if(low == high) {
            segt[node] = val;
            return; 
        }
          
        int mid = low + (high - low) / 2;

        if(indx > mid) {
            updateSegt(2 * node + 2, indx, val, mid + 1, high);
        }
        else {
            updateSegt(2 * node + 1, indx, val, low, mid);
        }

        segt[node] = segt[2 * node + 1] ^ segt[2 * node + 2];
    }

    int query(int indx, int start, int end, int l, int r) {
        if(l > end || r < start) return 0;

        if(start >= l && end <= r) return segt[indx]; 

        int mid = start + (end - start) / 2;

        int left = query(2 * indx + 1, start, mid, l, r);
        int right = query(2 * indx + 2, mid + 1, end, l, r); 
        return left ^ right;
    }

    void binarylifting(int colms, int n) {
        for(int j = 1; j < colms; j++) {
            for(int i = 0; i < n; i++) {
                if(ancestor[i][j - 1] != -1) {
                    ancestor[i][j] = ancestor[ancestor[i][j - 1]][j - 1];
                }
            }
        }
    }

    int lca(int node1, int node2, int colms) {
        if(depth[node1] < depth[node2]) swap(node1, node2);
        int k = depth[node1] - depth[node2];

        for(int j = 0; j < colms; j++) {
            if(k & (1 << j)) {
                node1 = ancestor[node1][j];
            }
        }

        if(node1 == node2) return node1;

        for(int j = colms - 1; j >= 0; j--) {
            if(ancestor[node1][j] != ancestor[node2][j]) {
                node1 = ancestor[node1][j];
                node2 = ancestor[node2][j];
            }
        }
        
        return ancestor[node1][0];
    }

    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
         this->n = n;
         int colms = 0;
         while((1 << colms) <= n) colms++;
         
         vv adj(n);
         for(int i = 0; i < n - 1; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
         }
         
         ancestor = vv(n, v(colms, -1));
         intime.resize(n);
         outtime.resize(n);
         eulerPath.resize(2 * n);
         depth.assign(n, 0);
         
         int N = 2 * n;
         segt.resize(4 * N);
        
         timer = 0;
         dfs(0, -1, adj, s);
         
         buildSegt(0, 0, 2 * n - 1);
         binarylifting(colms, n);

         vector<bool> result;

         for(string &q : queries) {
            stringstream ss(q);
            string type;
            ss >> type;

            if(type == "update") {
                int node;
                char c;
                ss >> node >> c;

                int chartype = (1 << (c - 'a'));
                s[node] = c;

                updateSegt(0, intime[node], chartype, 0, 2 * n - 1);
                updateSegt(0, outtime[node], chartype, 0, 2 * n - 1);
            }
            else {
                int u, v;
                ss >> u >> v;

                int getLca = lca(u, v, colms);

                char ch = s[getLca];
                int charvalue = (1 << (ch - 'a'));

                int maskU = query(0, 0, 2 * n - 1, 0, intime[u]);
                int maskV = query(0, 0, 2 * n - 1, 0, intime[v]);
                
                int mask = maskU ^ maskV ^ charvalue;

                result.push_back((mask & (mask - 1)) == 0);  
            }
         }
         
         return result;
    }
};