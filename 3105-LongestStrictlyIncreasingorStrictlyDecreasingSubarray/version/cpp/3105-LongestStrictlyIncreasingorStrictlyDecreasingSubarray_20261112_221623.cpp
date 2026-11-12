// Last updated: 11/12/2026, 10:16:23 PM
1class Solution {
2public:
3    int longestMonotonicSubarray(vector<int>& nums) {
4        ios::sync_with_stdio(false);
5        cin.tie(NULL);
6        int maxi = 1;
7        int inc_cnt =  1;
8        int dec_cnt =  1;
9        int n  = nums.size();
10        for(int i = 0;i<n-1;i++) {
11            if(nums[i]>nums[i+1]) {
12                inc_cnt++;
13                dec_cnt = 1;
14            }
15            else if(nums[i]<nums[i+1]) {
16                dec_cnt++;
17                inc_cnt = 1;
18            }
19            else {
20                inc_cnt = 1;
21                dec_cnt = 1;
22            }
23            maxi = max(maxi,max(inc_cnt,dec_cnt));
24        }
25        return maxi;
26    }
27};