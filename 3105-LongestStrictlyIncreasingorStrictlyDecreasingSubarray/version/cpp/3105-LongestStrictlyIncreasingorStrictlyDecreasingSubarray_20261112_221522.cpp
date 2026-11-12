// Last updated: 11/12/2026, 10:15:22 PM
1class Solution {
2public:
3    int longestMonotonicSubarray(vector<int>& nums) {
4        int maxi = 1;
5        int inc_cnt =  1;
6        int dec_cnt =  1;
7        int n  = nums.size();
8        for(int i = 0;i<n-1;i++) {
9            if(nums[i]>nums[i+1]) {
10                inc_cnt++;
11                dec_cnt = 1;
12            }
13            else if(nums[i]<nums[i+1]) {
14                dec_cnt++;
15                inc_cnt = 1;
16            }
17            else {
18                inc_cnt = 1;
19                dec_cnt = 1;
20            }
21            maxi = max(maxi,max(inc_cnt,dec_cnt));
22        }
23        return maxi;
24    }
25};