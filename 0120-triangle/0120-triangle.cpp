class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n-1].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        
        // Base case: initialize the bottom row
        for(int j = 0; j < triangle[n-1].size(); j++) {
            dp[n-1][j] = triangle[n-1][j];
        }

        // Bottom-up DP: from the second-to-last row up to the top
        for(int i = n-2; i >= 0; i--) {
            for(int j = 0; j < triangle[i].size(); j++) {
                // Add current node's value to the minimum of the two adjacent paths below it
                dp[i][j] = triangle[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
            }
        }
        
        return dp[0][0];
    }
};