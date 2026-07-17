class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int sum = 0;
        int total = 0;
        int mini_len = n;
        while(j<n) {
            sum += nums[j];
            total += nums[j];
            while(sum>=target) {
                mini_len = min(mini_len,j-i+1);
                sum -= nums[i];
                i++;
            }
            j++;
        }
        if(total<target) return 0;
        return mini_len;
    }
};