// Last updated: 10/28/2026, 2:18:09 PM
1class Solution {
2public:
3    int minCost(vector<vector<int>>& grid) {
4        int n = grid.size();
5        int m = grid[0].size();    
6
7        vector<vector<bitset<1024>>>dp(n,vector<bitset<1024>>(m));  
8        dp[0][0].set(grid[0][0]);
9
10        for(int i = 0;i<n;i++) {
11            for(int j = 0;j<m;j++) {
12                if(i==0&&j==0) continue;
13                bitset<1024>prev;
14
15                if(i>0) prev |= dp[i-1][j];
16                if(j>0) prev |= dp[i][j-1];
17
18                for(int v = 0;v<1024;v++) {
19                    if(prev.test(v)) {
20                        dp[i][j].set(v^grid[i][j]);
21                    }
22                } 
23            }
24        } 
25
26        for(int v = 0;v<1024;v++) {
27            if(dp[n-1][m-1].test(v)) return v;
28        }   
29
30        return 0;               
31    }
32};