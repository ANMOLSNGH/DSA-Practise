class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>>dp(n,vector<int>(n,1));
        int maxi = 1;

        for(int len = 2;len<=n;len++) {
            for(int i = 0;i<n-len+1;i++) {
                int j = i+len-1;
                if(len==2) dp[i][j] = s[i]==s[j]?2:1;
                else {
                    if(s[i]==s[j]) dp[i][j] = 2 + dp[i+1][j-1];
                    else dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
                }
                maxi = max(maxi,dp[i][j]);
            }
        }
        return maxi;
    }
};