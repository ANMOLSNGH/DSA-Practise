class Solution {
public:
    long long maxDifference(vector<int>& nums) {
        int n = nums.size();
        vector<long long> dp(n + 2, 0);
        
        for (int i = n - 1; i >= 0; i--) {
            long long sum1 = nums[i];
            long long take1 = sum1;
            
            if (sum1 % 3 == 0) {
                take1 -= dp[i + 1];
            } else {
                take1 += dp[i + 1];
            }
            
            long long max_gain = take1;
            
            if (i + 1 < n) {
                long long sum2 = nums[i] + nums[i + 1];
                long long take2 = sum2;
                
                if (sum2 % 3 == 0) {
                    take2 -= dp[i + 2];
                } else {
                    take2 += dp[i + 2];
                }
                
                max_gain = max(take1, take2);
            }
            
            dp[i] = max_gain;
        }
        
        return dp[0];
    }
};