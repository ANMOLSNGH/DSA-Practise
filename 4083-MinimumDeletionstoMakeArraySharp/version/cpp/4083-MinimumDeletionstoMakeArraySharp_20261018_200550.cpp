// Last updated: 10/18/2026, 8:05:50 PM
1class Solution {
2public:
3    int minDeletions(vector<int>& nums) {
4        int cnt = 0;
5
6        int n = nums.size();
7
8        for(int i = 0;i<n-1;i++) {
9            if(nums[i]==nums[i+1]) cnt++;
10        }
11        return cnt;
12    }
13};