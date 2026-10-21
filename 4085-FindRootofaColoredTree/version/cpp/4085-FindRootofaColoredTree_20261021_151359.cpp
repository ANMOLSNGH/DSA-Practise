// Last updated: 10/21/2026, 3:13:59 PM
1class Solution {
2public:
3    char get_next_color(char colr) {
4        if(colr=='R') return 'B';
5        else if(colr=='B') return 'W';
6
7        return 'R';
8    }
9    int findColoredRoot(vector<vector<int>>& edges, string colors) {
10        int n = edges.size();
11        int m = colors.size();
12        
13        vector<int>possible_roots;
14        vector<vector<int>>adj(m);
15        for(int i = 0;i<n;i++) {
16            int u = edges[i][0];
17            int v = edges[i][1];
18            adj[u].push_back(v);
19            adj[v].push_back(u);
20        }
21
22        for(int i = 0;i<m;i++) {
23            if(adj[i].size()==1) {
24                possible_roots.push_back(i);
25            }
26
27            else if(adj[i].size()==2) {
28                int j = 0;
29                if(colors[adj[i][j]]==colors[adj[i][j+1]]) {
30                    possible_roots.push_back(i);
31                }
32             }
33        }
34        for(auto &root : possible_roots) {
35            queue<int>q;
36            q.push(root);
37            vector<bool>visited(m,false);
38            bool possible = true;
39            while(!q.empty()) {
40                if(!possible) break;
41                int node = q.front();
42                q.pop();
43                char col = colors[node];
44                char expected_colr = get_next_color(col);
45                visited[node] = true;
46                for(auto connected : adj[node]) {
47                    int clr = colors[connected];
48                    if(!visited[connected]) {
49                    if(clr!=expected_colr) {
50                        possible = false;
51                        break;
52                    }
53                    else {
54                        q.push(connected);
55                    }
56                  }
57                }
58            }
59            if(possible) return root;
60        }
61        return -1;
62    }
63};