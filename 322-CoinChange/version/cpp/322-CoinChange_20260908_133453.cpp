// Last updated: 9/8/2026, 1:34:53 PM
1class Solution {
2public:
3    int INF = 1e9 + 7;
4    int coinChange(vector<int>& coins, int amount) {
5        int n = coins.size();
6        vector<int>dp(amount+1,INF);
7        dp[0] = 0;
8
9        for(int i = 1;i<=amount;i++) {
10            for(int j = 0;j<n;j++) {
11                // take all 
12                // if(i%coins[j]==0) dp[i] = i/coins[j];
13                // skip or take all min
14                // take or skip
15                if(i>=coins[j])
16                dp[i] = min(dp[i],1+dp[i-coins[j]]);
17            }
18        }
19        return dp[amount]==INF?-1:dp[amount];
20    }
21};