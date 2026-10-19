// Last updated: 10/19/2026, 1:12:28 PM
1class Solution {
2public:
3    vector<int> singleNumber(vector<int>& nums) {
4        int n = nums.size();
5        unsigned int xori = 0;
6        for(auto num:nums) {
7            xori ^= num;
8        }
9       unsigned int right_most1 = xori&(-xori);
10        int num1 = 0;
11        int num2 = 0;
12        for(auto num : nums) {
13            if ((num & right_most1) != 0) {
14                num1 ^= num;
15            }
16            else num2 ^= num;
17        }
18        return {num1,num2};
19    }
20};