// Last updated: 9/27/2026, 11:57:23 PM
1class Solution {
2public:
3    vector<int> rearrangeArray(vector<int>& nums) {
4        int n = nums.size();
5        vector<int>ans;
6        vector<int>cnt(101,0);
7        for(int i = 0;i<n;i++) cnt[nums[i]]++;
8        
9
10        while(ans.size()!=n) {
11           for(int i = 0;i<cnt.size();i++) {
12             if(cnt[i]==0) continue;
13             ans.push_back(i);
14             cnt[i]--;
15           }
16        }
17        return ans;
18
19    }
20};