// Last updated: 10/15/2026, 6:31:18 PM
1class Solution {
2public:
3    int sumCounts(vector<int>& nums) {
4        int n = nums.size();
5        int sum = 0;
6        for(int i = 0;i<n;i++) {
7            int cnt = 0;
8            vector<bool>visited(101,false);
9            for(int j = i;j<n;j++) {
10                 if(!visited[nums[j]]) {
11                    cnt++;
12                    visited[nums[j]] = true;
13                 }
14                 sum += cnt*cnt;
15            }
16        }
17        return sum;
18    }
19};