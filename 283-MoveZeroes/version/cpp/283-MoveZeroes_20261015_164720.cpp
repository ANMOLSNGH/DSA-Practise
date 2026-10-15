// Last updated: 10/15/2026, 4:47:20 PM
1class Solution {
2public:
3    void moveZeroes(vector<int>& nums) {
4          int cnt_0 = 0;
5          for(auto num : nums) {
6            if(num==0) cnt_0++;
7          }
8          int i = 0;
9          for(auto num : nums) {
10            if(num!=0) {
11                nums[i++] = num;
12            }
13          }
14          while(cnt_0!=0) {
15            nums[i++] = 0;
16            cnt_0--;
17          }
18    }
19};