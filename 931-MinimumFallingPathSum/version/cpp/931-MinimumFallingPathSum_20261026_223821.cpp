// Last updated: 10/26/2026, 10:38:21 PM
1class Solution {
2public:
3    int minFallingPathSum(vector<vector<int>>& matrix) {
4        int n = matrix.size();
5        
6        for(int i = 1; i < n; i++) {
7            for(int j = 0; j < n; j++) {
8                int min_prev = matrix[i-1][j]; 
9                
10                if (j > 0) {
11                    min_prev = min(min_prev, matrix[i-1][j-1]);
12                }
13                
14                if (j < n - 1) {
15                    min_prev = min(min_prev, matrix[i-1][j+1]);
16                }
17                
18                matrix[i][j] += min_prev;
19            }
20        }
21        
22        int ans = INT_MAX;
23        for(int j = 0; j < n; j++) {
24            ans = min(ans, matrix[n-1][j]);
25        }
26        
27        return ans;
28    }
29};