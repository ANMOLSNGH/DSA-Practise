// Last updated: 8/26/2026, 9:31:16 AM
1class Solution {
2public:
3    int minDistance(string word1, string word2) {
4        int n = word1.size();
5        int m = word2.size();
6        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
7        for(int i = 0;i<=n;i++) dp[i][0] = i;
8
9        for(int j = 0;j<=m;j++) dp[0][j] = j;
10
11        for(int i = 1;i<=n;i++) {
12            for(int j = 1;j<= m ;j++) {
13                if(word1[i-1]==word2[j-1]) dp[i][j] = dp[i-1][j-1];
14                else {
15                    dp[i][j] = 1 + min(dp[i-1][j],dp[i][j-1]);
16                }
17            }
18        }
19        return dp[n][m];
20        
21    }
22};