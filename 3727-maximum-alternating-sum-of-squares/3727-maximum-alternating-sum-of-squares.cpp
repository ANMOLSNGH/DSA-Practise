class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(int i = 0;i<nums.size();i++) {
            if(nums[i]<0) nums[i] = -1*nums[i];
        }

        sort(nums.begin(),nums.end(),greater<int>());
        int n = nums.size();
        long long maxi_sum = 0;
        for(int i = 0;i<n/2;i++) {
              maxi_sum += nums[i]*nums[i] - nums[n-i-1]*nums[n-i-1];
        }
        if(n&1) maxi_sum += nums[n/2]*nums[n/2];

        return maxi_sum;
    }
};