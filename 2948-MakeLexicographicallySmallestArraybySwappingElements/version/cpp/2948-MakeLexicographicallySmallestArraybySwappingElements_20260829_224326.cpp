// Last updated: 8/29/2026, 10:43:26 PM
1class Solution {
2public:
3    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
4        int n = nums.size();
5        vector<pair<int,int>>temp(n);
6        for(int i = 0;i<n;i++) {
7            temp[i].first = nums[i];
8            temp[i].second = i;
9        }
10        sort(temp.begin(),temp.end());
11        vector<int>ans(n);
12        int i = 0;
13        while(i<n) {
14            int j = i+ 1;
15            while(j<n&&temp[j].first-temp[j-1].first<=limit) j++;
16
17            vector<int>grpindx;
18            for(int k = i;k<j;k++) grpindx.push_back(temp[k].second);
19            sort(grpindx.begin(),grpindx.end());
20
21            for(int k = 0;k<grpindx.size();k++) {
22                ans[grpindx[k]] = temp[i+k].first;
23            }
24            i = j;
25        }
26        return ans;
27    }
28};