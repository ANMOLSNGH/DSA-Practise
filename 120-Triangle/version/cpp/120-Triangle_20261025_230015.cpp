// Last updated: 10/25/2026, 11:00:15 PM
1class Solution {
2public:
3    int minimumTotal(vector<vector<int>>& triangle) {
4        int n = triangle.size();
5        int m = triangle[n-1].size();
6        vector<vector<int>> dp(n, vector<int>(m, 0));
7        
8        // Base case: initialize the bottom row
9        for(int j = 0; j < triangle[n-1].size(); j++) {
10            dp[n-1][j] = triangle[n-1][j];
11        }
12
13        // Bottom-up DP: from the second-to-last row up to the top
14        for(int i = n-2; i >= 0; i--) {
15            for(int j = 0; j < triangle[i].size(); j++) {
16                // Add current node's value to the minimum of the two adjacent paths below it
17                dp[i][j] = triangle[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
18            }
19        }
20        
21        return dp[0][0];
22    }
23};