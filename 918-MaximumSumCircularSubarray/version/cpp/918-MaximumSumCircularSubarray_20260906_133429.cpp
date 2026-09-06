// Last updated: 9/6/2026, 1:34:29 PM
1class Solution {
2public:
3    int maxSubarraySumCircular(vector<int>& nums) {
4        int n = nums.size();
5        int total_sum = 0;
6        int curr_max = 0;
7        int mini_sum = INT_MAX;
8        int curr_min = 0;
9        int maxi_sum = INT_MIN;
10        for(int i = 0;i<n;i++) {
11            total_sum += nums[i];
12            curr_max += nums[i];
13            curr_min += nums[i];
14            maxi_sum = max(maxi_sum,curr_max);
15            mini_sum = min(mini_sum,curr_min);
16            if(curr_max<0) curr_max = 0;  
17            if(curr_min > 0) curr_min = 0;
18        }
19        if(maxi_sum<0) return maxi_sum;
20        int wrap = total_sum - mini_sum;
21        int ans = max(maxi_sum,wrap);
22        return ans;
23    }
24};