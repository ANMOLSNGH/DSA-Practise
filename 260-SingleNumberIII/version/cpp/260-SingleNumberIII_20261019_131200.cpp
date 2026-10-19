// Last updated: 10/19/2026, 1:12:00 PM
1class Solution {
2public:
3    vector<int> singleNumber(vector<int>& nums) {
4        int n = nums.size();
5        unsigned int xori = 0;
6        for(auto num : nums) {
7            xori ^= num;
8        }
9        unsigned int right_most1 = (xori)&(-xori);
10
11        int num1 = 0;
12        int num2 = 0;
13        for(auto num : nums) {
14            if ((num & right_most1) != 0) {
15                num1 ^= num;
16            }
17            else num2 ^= num;
18        }
19        return {num1,num2};
20    }
21};