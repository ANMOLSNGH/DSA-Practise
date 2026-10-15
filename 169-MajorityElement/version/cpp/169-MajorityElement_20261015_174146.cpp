// Last updated: 10/15/2026, 5:41:46 PM
1class Solution {
2public:
3    int majorityElement(vector<int>& nums) {
4        int n = nums.size();
5        int cnt = 0;
6        int cand = 0;
7        for(auto num:nums) {
8            if(cnt==0) {
9                cand = num;
10                cnt++;
11            }
12            else if(cand==num) cnt++;
13            else cnt--;
14        }
15        return cand;
16    }
17};