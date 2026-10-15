// Last updated: 10/15/2026, 4:48:26 PM
1class Solution {
2public:
3    void moveZeroes(vector<int>& nums) {
4          ios::sync_with_stdio(false);
5          cin.tie(NULL);
6          int cnt_0 = 0;
7          for(auto num : nums) {
8            if(num==0) cnt_0++;
9          }
10          int i = 0;
11          for(auto num : nums) {
12            if(num!=0) {
13                nums[i++] = num;
14            }
15          }
16          while(cnt_0!=0) {
17            nums[i++] = 0;
18            cnt_0--;
19          }
20    }
21};