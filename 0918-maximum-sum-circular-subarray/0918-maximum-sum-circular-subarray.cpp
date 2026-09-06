class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int total_sum = 0;
        int curr_max = 0;
        int mini_sum = INT_MAX;
        int curr_min = 0;
        int maxi_sum = INT_MIN;
        for(int i = 0;i<n;i++) {
            total_sum += nums[i];
            curr_max += nums[i];
            curr_min += nums[i];
            maxi_sum = max(maxi_sum,curr_max);
            mini_sum = min(mini_sum,curr_min);
            if(curr_max<0) curr_max = 0;  
            if(curr_min > 0) curr_min = 0;
        }
        if(maxi_sum<0) return maxi_sum;
        int wrap = total_sum - mini_sum;
        int ans = max(maxi_sum,wrap);
        return ans;
    }
};