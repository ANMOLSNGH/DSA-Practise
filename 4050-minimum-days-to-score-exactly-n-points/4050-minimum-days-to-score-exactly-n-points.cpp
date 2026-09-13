class Solution {
public:
    int minDays(int n) {
        vector<long long>dp(n+1,1e9);
        dp[0] = 0;


        for(int i = 1;i<=n;i++) {
            for(int k = 1;k*(k+1)/2<=i;k++) {
                long long score = k*(k+1)/2;
                long long ans = 1e9;
                if(score<=i) {
                    ans = (score==i)?k:k+dp[i-score]+1;
                }
                dp[i] = min(dp[i],ans);
            }
        }
        return dp[n];
    }
};