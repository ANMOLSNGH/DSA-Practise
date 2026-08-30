// Last updated: 8/30/2026, 8:26:33 AM
1class Solution {
2public:
3    int countSpecialIntegers(vector<int>& nums) {
4        int n = nums.size();
5        vector<int>indx(101,0);
6        indx[nums[0]] = 1;
7        for(int i = 1;i<n;i++) {
8            if(indx[nums[i]]==0&&indx[nums[i]]!=-1)
9            indx[nums[i]] = 1;
10
11            else if(indx[nums[i]]==1&&nums[i]!=nums[i-1]) {
12                 indx[nums[i]] = -1;
13            }  
14        }
15        int cnt = 0;
16        for(int i = 0;i<indx.size();i++) {
17            if(indx[i]==1) cnt++;
18        }
19        return cnt;
20    }
21};