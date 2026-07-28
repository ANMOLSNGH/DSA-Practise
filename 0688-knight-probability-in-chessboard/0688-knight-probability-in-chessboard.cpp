class Solution {
public:
    vector<pair<int,int>>direc = {{-2,-1},{2,-1},{-2,1},{2,1},{-1,-2},{1,-2},{-1,2},{1,2}};
    double dp[26][26][101];

    double solve(int r,int c,int k,int n) {
        if(r<0||r>=n||c<0||c>=n) return 0.0;

        if(k==0) return 1.0;

        if(dp[r][c][k]!=-1.0) return dp[r][c][k];
        double probability = 0.0;

        for(auto [u,v]:direc) {
            int new_r = r + u;
            int new_c = c + v;
            probability += solve(new_r,new_c,k-1,n)/8.0;
        }
        return dp[r][c][k] = probability;
    }

    double knightProbability(int n, int k, int row, int column) {
        for (int i = 0; i <n; i++) {
            for (int j = 0; j < n; j++) {
                for (int l = 0; l <=k; l++) {
                    dp[i][j][l] = -1.0;
                }
            }
        }
        return solve(row,column,k,n);
    }
};



