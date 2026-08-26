// Last updated: 8/26/2026, 9:14:47 AM
1class Solution {
2public:
3    int minInsertions(string s) {
4        int n = s.size();
5        vector<vector<int>>dp(n,vector<int>(n,0));
6        for(int len = 2;len<=n;len++) {
7            for(int i = 0;i<n-len+1;i++) {
8                int j = i+len-1;
9                if(len==2) dp[i][j] = (s[i]==s[j])?0:1;
10                else {
11                    if(s[i]==s[j]) dp[i][j] = dp[i+1][j-1];
12                    else dp[i][j] = min(dp[i+1][j]+1,dp[i][j-1]+1);
13                }
14            }
15        }
16        return dp[0][n-1];
17    }
18};