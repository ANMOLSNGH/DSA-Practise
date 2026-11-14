class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        vector<int>pref(n);
        pref[0] = nums[0];
        for(int i = 1;i<n;i++) {
            pref[i] = nums[i] + pref[i-1];
        }
        int mini_sum = INT_MAX;
        for(int i = l ;i<=r;i++) {
            for(int j = 0;j<=n-i;j++) {
                int k = j + i - 1;
                int sum = pref[k] - (j>0?pref[j-1]:0);
                if(sum>0) mini_sum = min(mini_sum,sum);
            }
        }
        return mini_sum==INT_MAX?-1:mini_sum;
    }
};