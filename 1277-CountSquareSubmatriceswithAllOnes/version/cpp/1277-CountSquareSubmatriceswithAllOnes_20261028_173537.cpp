// Last updated: 10/28/2026, 5:35:37 PM
1class Solution {
2public:
3    int countSquares(vector<vector<int>>& matrix) {
4        int n = matrix.size();
5        int m = matrix[0].size();
6        vector<vector<int>>dp(n,vector<int>(m,0));
7        int sum = 0;
8        for(int i = 0;i<n;i++) {
9            if(matrix[i][0]==1) dp[i][0] = 1;
10            sum += dp[i][0];
11        }
12
13        for(int i = 1;i<m;i++) {
14            if(matrix[0][i]==1) dp[0][i] = 1;
15            sum += dp[0][i];
16        }
17       
18        for(int i = 1;i<n;i++) {
19            for(int j = 1;j<m;j++) {
20                if(matrix[i][j]==1)
21                dp[i][j] = 1 + min({dp[i][j-1],dp[i-1][j],dp[i-1][j-1]});
22
23                sum += dp[i][j];
24            }
25        }
26        for(int i = 0;i<n;i++) {
27            for(int j = 0;j<m;j++) cout << dp[i][j] << " ";
28            cout << "\n";
29        }
30        return sum;
31    }
32};