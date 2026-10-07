// Last updated: 10/8/2026, 12:21:56 AM
1class Solution {
2public:
3    void sortColors(vector<int>& nums) {
4        int low = 0;
5        int mid = 0;
6        int high = nums.size()-1;
7        while(mid<=high) {
8            if(nums[mid]==0) {
9                swap(nums[mid],nums[low]);
10                low++;
11                mid++;
12            }
13            else if(nums[mid]==2) {
14                swap(nums[mid],nums[high]);
15                high--;
16            }
17            else mid++;
18        }
19    }
20};