class Solution {
public:
    char get_next_color(char colr) {
        if(colr=='R') return 'B';
        else if(colr=='B') return 'W';

        return 'R';
    }
    int findColoredRoot(vector<vector<int>>& edges, string colors) {
        int n = edges.size();
        int m = colors.size();
        
        vector<int>possible_roots;
        vector<vector<int>>adj(m);
        for(int i = 0;i<n;i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int i = 0;i<m;i++) {
            if(adj[i].size()==1) {
                possible_roots.push_back(i);
            }

            else if(adj[i].size()==2) {
                int j = 0;
                if(colors[adj[i][j]]==colors[adj[i][j+1]]) {
                    possible_roots.push_back(i);
                }
             }
        }
        for(auto &root : possible_roots) {
            queue<int>q;
            q.push(root);
            vector<bool>visited(m,false);
            bool possible = true;
            while(!q.empty()) {
                if(!possible) break;
                int node = q.front();
                q.pop();
                char col = colors[node];
                char expected_colr = get_next_color(col);
                visited[node] = true;
                for(auto connected : adj[node]) {
                    int clr = colors[connected];
                    if(!visited[connected]) {
                    if(clr!=expected_colr) {
                        possible = false;
                        break;
                    }
                    else {
                        q.push(connected);
                    }
                  }
                }
            }
            if(possible) return root;
        }
        return -1;
    }
};