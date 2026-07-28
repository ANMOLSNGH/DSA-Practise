class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,1);
        vector<int>count(n,1);
        int max_len = 1;

        for(int i = 0;i<n;i++) {
            for(int j = 0;j<i;j++) {
                if(nums[j]<nums[i]) {
                    if(dp[j]+1>dp[i]) {
                        dp[i] = dp[j]+1;
                        count[i] = count[j]; 
                    }
                    else if(dp[j]+1==dp[i]) count[i] += count[j];
                

                }
                max_len = max(max_len,dp[i]);
            }
        }
        int total_cnt = 0;
        for(int j = 0;j<n;j++) {
            if(dp[j]==max_len) total_cnt += count[j];
        }
        return total_cnt;
    }
};