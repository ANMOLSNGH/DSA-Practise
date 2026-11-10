class Solution {
public:
    const int INF = 1e9;
    int climbStairs(int n, vector<int>& costs) {
        vector<int>dp(n+1,INF);
        
        dp[0] = 0;
        for(int i = 1;i<=n;i++) {
            for(int jump = 1;jump<=3;jump++) {
                if(i-jump>=0) {
                    dp[i] = min(dp[i],dp[i-jump] + costs[i-1]+jump*jump);
                }
            }
        }
        return dp[n];
    }
};