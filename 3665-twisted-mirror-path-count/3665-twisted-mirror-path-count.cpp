class Solution {
public:
    int dp[501][501][2];
    int n,m;
    int mod = 1e9+7;
    int solve(int i , int j ,int posn ,vector<vector<int>>& grid ) {
        if(i==n-1&&j==m-1) return 1;
        if(i>=n||j>=m) return 0;

        if(dp[i][j][posn]!=-1) return dp[i][j][posn];
        if(grid[i][j]==0) {
            dp[i][j][posn] = (solve(i,j+1,0,grid) + solve(i+1,j,1,grid))%mod;
        }
        else {
            if(posn==0) {
                dp[i][j][posn] = (solve(i+1,j,1,grid));
            }
            else dp[i][j][posn] = (solve(i,j+1,0,grid));
        }
        return dp[i][j][posn];
    }
    int uniquePaths(vector<vector<int>>& grid) {
        n =grid.size();
        m = grid[0].size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,0,grid);
    }
};