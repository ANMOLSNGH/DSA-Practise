class Solution {
public:
    using LL = long long;
    long long incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        while(left+1<n&&nums[left]<nums[left+1])  left++;

        if(left==n-1) return (LL)n * (LL)(n+1)/2;

        int right = n-1;

        while(right-1>=0&&nums[right]>nums[right-1]) right--;

        long long ans = n-right+1;

        for(int i = 0;i<=left;i++) {
            while(right<n&&nums[right]<=nums[i]) right++;
            ans += n-right+1;
        }

        return ans;
    }
};