class Solution {
public:
    using v = vector<int>;
    using vv = vector<v>;


    // we can reduce space cmplexity as well easily as we are dependent only 
//  on prev row we can just loop one more time to see it ........
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // base case
        v prev = matrix[0];

        for(int i = 1;i<n;i++) {
            v curr(n,0);
            for(int j = 0;j<n;j++) {
                int min_value = prev[j];
                
                if(j>0)
                min_value = min(min_value,prev[j-1]);

                if(j<n-1)
                min_value = min(min_value,prev[j+1]);

                curr[j] = min_value + matrix[i][j];
            }
            prev = curr;
        }
        int ans = INT_MAX;
        for(int i = 0;i<n;i++) {
            ans = min(ans,prev[i]);
        }
        return ans;
    }
};