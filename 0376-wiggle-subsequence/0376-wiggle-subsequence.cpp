class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n<2) return n;
        vector<vector<int>>dp(n,vector<int>(2,1));
        int maxi = 1;
      

        for(int i = 1;i<n;i++) {
            int diff = nums[i] - nums[i-1];
            if(diff>0) {
                dp[i][1] = 1 + dp[i-1][0];
                dp[i][0] = dp[i-1][0];
            }
            else if(diff<0) {
                dp[i][0] = 1 + dp[i-1][1];
                dp[i][1] = dp[i-1][1];
            }
            else {
                dp[i][0] = dp[i-1][0];
                dp[i][1] = dp[i-1][1];
            }
        }
        maxi = max(dp[n-1][0],dp[n-1][1]);
        return maxi;

    }
};