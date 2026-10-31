// Last updated: 10/31/2026, 4:27:12 PM
1class Solution {
2public:
3    using v = vector<int>;
4    using vv = vector<v>;
5    vv ancestor;
6    v intime, outtime, eulerPath, depth;
7    int timer;
8    v segt;
9    int n;
10
11    void dfs(int node, int parent, vv &adj, string &s) {
12         intime[node] = timer;
13         eulerPath[timer] = 1 << (s[node] - 'a');
14         ancestor[node][0] = parent;
15         timer++;
16
17         for(auto &ngbr : adj[node]) {
18             if(ngbr == parent) continue;
19
20             depth[ngbr] = depth[node] + 1;
21             dfs(ngbr, node, adj, s);
22         }
23
24         outtime[node] = timer;
25         eulerPath[timer] = 1 << (s[node] - 'a');
26         timer++;
27    }
28
29    void buildSegt(int indx, int low, int high) {
30        if(low == high) {
31            segt[indx] = eulerPath[low];
32            return;
33        }
34
35        int mid = low + (high - low) / 2;
36
37        buildSegt(2 * indx + 1, low, mid);
38        buildSegt(2 * indx + 2, mid + 1, high);
39
40        segt[indx] = segt[2 * indx + 1] ^ segt[2 * indx + 2];
41    }
42
43    void updateSegt(int node, int indx, int val, int low, int high) {
44        if(low == high) {
45            segt[node] = val;
46            return; 
47        }
48          
49        int mid = low + (high - low) / 2;
50
51        if(indx > mid) {
52            updateSegt(2 * node + 2, indx, val, mid + 1, high);
53        }
54        else {
55            updateSegt(2 * node + 1, indx, val, low, mid);
56        }
57
58        segt[node] = segt[2 * node + 1] ^ segt[2 * node + 2];
59    }
60
61    int query(int indx, int start, int end, int l, int r) {
62        if(l > end || r < start) return 0;
63
64        if(start >= l && end <= r) return segt[indx]; 
65
66        int mid = start + (end - start) / 2;
67
68        int left = query(2 * indx + 1, start, mid, l, r);
69        int right = query(2 * indx + 2, mid + 1, end, l, r); 
70        return left ^ right;
71    }
72
73    void binarylifting(int colms, int n) {
74        for(int j = 1; j < colms; j++) {
75            for(int i = 0; i < n; i++) {
76                if(ancestor[i][j - 1] != -1) {
77                    ancestor[i][j] = ancestor[ancestor[i][j - 1]][j - 1];
78                }
79            }
80        }
81    }
82
83    int lca(int node1, int node2, int colms) {
84        if(depth[node1] < depth[node2]) swap(node1, node2);
85        int k = depth[node1] - depth[node2];
86
87        for(int j = 0; j < colms; j++) {
88            if(k & (1 << j)) {
89                node1 = ancestor[node1][j];
90            }
91        }
92
93        if(node1 == node2) return node1;
94
95        for(int j = colms - 1; j >= 0; j--) {
96            if(ancestor[node1][j] != ancestor[node2][j]) {
97                node1 = ancestor[node1][j];
98                node2 = ancestor[node2][j];
99            }
100        }
101        
102        return ancestor[node1][0];
103    }
104
105    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
106         this->n = n;
107         int colms = 0;
108         while((1 << colms) <= n) colms++;
109         
110         vv adj(n);
111         for(int i = 0; i < n - 1; i++) {
112            int u = edges[i][0];
113            int v = edges[i][1];
114            adj[u].push_back(v);
115            adj[v].push_back(u);
116         }
117         
118         ancestor = vv(n, v(colms, -1));
119         intime.resize(n);
120         outtime.resize(n);
121         eulerPath.resize(2 * n);
122         depth.assign(n, 0);
123         
124         int N = 2 * n;
125         segt.resize(4 * N);
126        
127         timer = 0;
128         dfs(0, -1, adj, s);
129         
130         buildSegt(0, 0, 2 * n - 1);
131         binarylifting(colms, n);
132
133         vector<bool> result;
134
135         for(string &q : queries) {
136            stringstream ss(q);
137            string type;
138            ss >> type;
139
140            if(type == "update") {
141                int node;
142                char c;
143                ss >> node >> c;
144
145                int chartype = (1 << (c - 'a'));
146                s[node] = c;
147
148                updateSegt(0, intime[node], chartype, 0, 2 * n - 1);
149                updateSegt(0, outtime[node], chartype, 0, 2 * n - 1);
150            }
151            else {
152                int u, v;
153                ss >> u >> v;
154
155                int getLca = lca(u, v, colms);
156
157                char ch = s[getLca];
158                int charvalue = (1 << (ch - 'a'));
159
160                int maskU = query(0, 0, 2 * n - 1, 0, intime[u]);
161                int maskV = query(0, 0, 2 * n - 1, 0, intime[v]);
162                
163                int mask = maskU ^ maskV ^ charvalue;
164
165                result.push_back((mask & (mask - 1)) == 0);  
166            }
167         }
168         
169         return result;
170    }
171};