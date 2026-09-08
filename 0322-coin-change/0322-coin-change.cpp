class Solution {
public:
    int INF = 1e9 + 7;
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int>dp(amount+1,INF);
        dp[0] = 0;

        for(int i = 1;i<=amount;i++) {
            for(int j = 0;j<n;j++) {
                // take all 
                // if(i%coins[j]==0) dp[i] = i/coins[j];
                // skip or take all min
                // take or skip
                if(i>=coins[j])
                dp[i] = min(dp[i],1+dp[i-coins[j]]);
            }
        }
        return dp[amount]==INF?-1:dp[amount];
    }
};