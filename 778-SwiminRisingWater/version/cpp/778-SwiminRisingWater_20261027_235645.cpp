// Last updated: 10/27/2026, 11:56:45 PM
1class Solution {
2public:
3    int n, m;
4    vector<pair<int,int>> direc = {{1,0}, {0,1}, {-1,0}, {0,-1}};
5    using t = tuple<int, int, int>;
6    
7    bool isvalid(int i, int j) {
8        return i >= 0 && i < n && j >= 0 && j < m;
9    }
10    
11    int swimInWater(vector<vector<int>>& grid) {
12        n = grid.size();
13        m = grid[0].size();
14        
15        priority_queue<t, vector<t>, greater<t>> pq;
16        vector<vector<bool>> visited(n, vector<bool>(m, false));
17        
18        visited[0][0] = true;
19        pq.push({grid[0][0], 0, 0}); 
20        
21        while(!pq.empty()) {
22            auto [time, row, col] = pq.top();
23            pq.pop();
24
25            if(row == n - 1 && col == n - 1) return time;
26
27            for(int k = 0; k < 4; k++) {
28                int r = row + direc[k].first;
29                int c = col + direc[k].second;
30                
31                if(isvalid(r, c) && !visited[r][c]) {
32                    visited[r][c] = true;
33                    pq.push({max(time, grid[r][c]), r, c});
34                }
35            }
36        }
37
38        return -1;
39    }
40};