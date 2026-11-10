class Solution {
public:
    const int INF = 1e9;
    int minDays(int n) {
        vector<int>dp(n+1,INF);
        dp[0] = 0;

        for(int i = 1;i<=n;i++) {
            for(int k = 1;k*(k+1)/2<=i;k++) {
                int days = k * (k+1)/2;
                if(i==days) dp[i] = k;

                dp[i] = min(dp[i],dp[i-days]+ k + 1);

            }
        }
        return dp[n];
    }
};