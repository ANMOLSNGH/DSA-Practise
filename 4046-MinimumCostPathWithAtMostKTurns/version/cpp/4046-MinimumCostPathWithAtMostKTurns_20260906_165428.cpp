// Last updated: 9/6/2026, 4:54:28 PM
1class Solution {
2public:
3    int n, m;
4    
5    bool isvalid(int i, int j) {
6        return i >= 0 && i < n && j >= 0 && j < m;
7    }
8    
9    vector<pair<int, int>> direc = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
10    int INF = 1e9 + 7;
11    typedef tuple<int, int, int, int, int> t;
12    
13    int minCost(vector<vector<int>>& grid, int k) {
14        n = grid.size();
15        m = grid[0].size();
16        
17        vector<vector<vector<vector<int>>>> path(
18            n, vector<vector<vector<int>>>(
19                m, vector<vector<int>>(
20                    k + 1, vector<int>(5, INF)
21                )
22            )
23        );
24        
25        priority_queue<t, vector<t>, greater<t>> pq;
26        
27        path[0][0][k][4] = grid[0][0]; 
28        pq.push({grid[0][0], 0, 0, k, 4});
29        
30        while (!pq.empty()) {
31            auto [val, i, j, curr_k, prev] = pq.top();
32            pq.pop();
33            
34            if (i == n - 1 && j == m - 1) return val;
35            
36            if (val > path[i][j][curr_k][prev]) continue;
37            
38            for (int d = 0; d < 4; ++d) {
39                int new_i = i + direc[d].first;
40                int new_j = j + direc[d].second;
41                
42                if (isvalid(new_i, new_j)) {
43                    bool dir_changed = (prev != 4 && prev != d);
44                    int new_k = curr_k - (dir_changed ? 1 : 0);
45                    
46                    if (new_k >= 0) {
47                        int new_cost = val + grid[new_i][new_j];
48                        
49                        if (new_cost < path[new_i][new_j][new_k][d]) {
50                            path[new_i][new_j][new_k][d] = new_cost;
51                            pq.push({new_cost, new_i, new_j, new_k, d});
52                        }
53                    }
54                }
55            }
56        }
57        
58        return -1;
59    }
60};