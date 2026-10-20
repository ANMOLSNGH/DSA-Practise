// Last updated: 10/20/2026, 11:50:21 AM
1class Solution {
2public:
3    int search(vector<int>& nums, int target) {
4        int n = nums.size();
5        int low = 0;
6        int high = n-1;
7        int res = -1;
8
9        while(low<=high) {
10            int mid = low + (high-low)/2;
11              if(target==nums[mid]) {
12                    return mid;
13                }
14            if(nums[mid]>=nums[low]) {
15                if(target>=nums[low]&&target<nums[mid]) {
16                    high = mid - 1;
17                }
18                else {
19                    low = mid + 1;
20                }
21            }
22            else {
23                if(target>nums[mid]&&target<=nums[high]) {
24                     low = mid + 1;
25                }
26                else high = mid - 1;
27            }
28        }
29        return res;
30    }
31};