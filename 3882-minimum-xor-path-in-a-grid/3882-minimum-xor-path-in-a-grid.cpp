class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();    

        vector<vector<bitset<1024>>>dp(n,vector<bitset<1024>>(m));  
        dp[0][0].set(grid[0][0]);

        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                if(i==0&&j==0) continue;
                bitset<1024>prev;

                if(i>0) prev |= dp[i-1][j];
                if(j>0) prev |= dp[i][j-1];

                for(int v = 0;v<1024;v++) {
                    if(prev.test(v)) {
                        dp[i][j].set(v^grid[i][j]);
                    }
                } 
            }
        } 

        for(int v = 0;v<1024;v++) {
            if(dp[n-1][m-1].test(v)) return v;
        }   

        return 0;               
    }
};