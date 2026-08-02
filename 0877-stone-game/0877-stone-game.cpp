class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
         for (int i = 0; i < n; i++) {
        dp[i][i] = piles[i];
    }


        for(int len = 2;len<=n;len += 2) {
            for(int i = 0;i<=n-len;i++) {
                int j = i+len-1;

                int op1 = piles[i] - dp[i+1][j];
                int op2 = piles[j] - dp[i][j-1];
                dp[i][j] = max(op1,op2);
            }
        }
         return dp[0][n-1]>0;
    }
};