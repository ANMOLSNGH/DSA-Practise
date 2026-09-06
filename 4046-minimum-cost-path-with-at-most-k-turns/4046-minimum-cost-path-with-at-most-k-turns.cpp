class Solution {
public:
    int n, m;
    
    bool isvalid(int i, int j) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    
    vector<pair<int, int>> direc = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int INF = 1e9 + 7;
    typedef tuple<int, int, int, int, int> t;
    
    int minCost(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        
        vector<vector<vector<vector<int>>>> path(
            n, vector<vector<vector<int>>>(
                m, vector<vector<int>>(
                    k + 1, vector<int>(5, INF)
                )
            )
        );
        
        priority_queue<t, vector<t>, greater<t>> pq;
        
        path[0][0][k][4] = grid[0][0]; 
        pq.push({grid[0][0], 0, 0, k, 4});
        
        while (!pq.empty()) {
            auto [val, i, j, curr_k, prev] = pq.top();
            pq.pop();
            
            if (i == n - 1 && j == m - 1) return val;
            
            if (val > path[i][j][curr_k][prev]) continue;
            
            for (int d = 0; d < 4; ++d) {
                int new_i = i + direc[d].first;
                int new_j = j + direc[d].second;
                
                if (isvalid(new_i, new_j)) {
                    bool dir_changed = (prev != 4 && prev != d);
                    int new_k = curr_k - (dir_changed ? 1 : 0);
                    
                    if (new_k >= 0) {
                        int new_cost = val + grid[new_i][new_j];
                        
                        if (new_cost < path[new_i][new_j][new_k][d]) {
                            path[new_i][new_j][new_k][d] = new_cost;
                            pq.push({new_cost, new_i, new_j, new_k, d});
                        }
                    }
                }
            }
        }
        
        return -1;
    }
};