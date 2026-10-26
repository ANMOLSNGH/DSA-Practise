class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int min_prev = matrix[i-1][j]; 
                
                if (j > 0) {
                    min_prev = min(min_prev, matrix[i-1][j-1]);
                }
                
                if (j < n - 1) {
                    min_prev = min(min_prev, matrix[i-1][j+1]);
                }
                
                matrix[i][j] += min_prev;
            }
        }
        
        int ans = INT_MAX;
        for(int j = 0; j < n; j++) {
            ans = min(ans, matrix[n-1][j]);
        }
        
        return ans;
    }
};