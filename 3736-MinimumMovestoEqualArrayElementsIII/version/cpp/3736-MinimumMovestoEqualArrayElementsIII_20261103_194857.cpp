// Last updated: 11/3/2026, 7:48:57 PM
1class Solution {
2public:
3    int minMoves(vector<int>& nums) {
4        int maxi = *max_element(nums.begin(),nums.end());
5
6        int ans = 0;
7        for(auto num : nums) {
8            ans += maxi-num;
9        }
10
11        return ans;
12    }
13};