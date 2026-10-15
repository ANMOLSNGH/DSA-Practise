// Last updated: 10/15/2026, 5:47:59 PM
1class Solution {
2public:
3    int missingNumber(vector<int>& nums) {
4        int n = nums.size();
5        int ans =0;
6        for(int i =1;i<=n;i++){
7            ans = ans ^ i;
8        }
9        for(int i =0;i<nums.size();i++){
10            ans= ans^nums[i];
11        }
12        return ans;
13    }
14};
15
16