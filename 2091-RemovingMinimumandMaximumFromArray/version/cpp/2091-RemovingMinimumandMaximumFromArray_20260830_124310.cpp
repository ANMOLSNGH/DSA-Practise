// Last updated: 8/30/2026, 12:43:10 PM
1class Solution {
2public:
3    int minimumDeletions(vector<int>& nums) {
4        int n = nums.size();
5        int mini_indx = 0;
6        int maxi_indx = 0;
7        for(int i = 0;i<nums.size();i++) {
8            if(nums[i]>nums[maxi_indx]) {
9                maxi_indx = i;
10            }
11            if(nums[i]<nums[mini_indx]) {
12                mini_indx = i;
13            }
14        }
15        int poss1 = max(mini_indx,maxi_indx)+1;
16        int poss2 = max(n-mini_indx,n-maxi_indx);
17        int poss3 = min(mini_indx+1+n-maxi_indx,n-mini_indx+maxi_indx+1);
18
19        int ans = min({poss1,poss2,poss3});
20        return ans;
21    }
22};