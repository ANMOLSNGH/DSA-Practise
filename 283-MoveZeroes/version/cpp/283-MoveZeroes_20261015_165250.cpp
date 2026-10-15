// Last updated: 10/15/2026, 4:52:50 PM
1class Solution {
2public:
3    void moveZeroes(vector<int>& nums) {
4          ios::sync_with_stdio(false);
5          cin.tie(NULL);
6          int left = 0;
7          for(int right = 0;right<nums.size();right++) {
8            if(nums[right]!=0) {
9                swap(nums[right],nums[left]);
10                left++;
11            }
12          }
13    }
14};