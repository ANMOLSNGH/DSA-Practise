// Last updated: 11/3/2026, 8:18:31 PM
1class Solution {
2public:
3    int dp[501][501][2];
4    int n,m;
5    int mod = 1e9+7;
6    int solve(int i , int j ,int posn ,vector<vector<int>>& grid ) {
7        if(i==n-1&&j==m-1) return 1;
8        if(i>=n||j>=m) return 0;
9
10        if(dp[i][j][posn]!=-1) return dp[i][j][posn];
11        if(grid[i][j]==0) {
12            dp[i][j][posn] = (solve(i,j+1,0,grid) + solve(i+1,j,1,grid))%mod;
13        }
14        else {
15            if(posn==0) {
16                dp[i][j][posn] = (solve(i+1,j,1,grid));
17            }
18            else dp[i][j][posn] = (solve(i,j+1,0,grid));
19        }
20        return dp[i][j][posn];
21    }
22    int uniquePaths(vector<vector<int>>& grid) {
23        n =grid.size();
24        m = grid[0].size();
25        memset(dp,-1,sizeof(dp));
26        return solve(0,0,0,grid);
27    }
28};