// Last updated: 9/12/2026, 8:43:28 PM
1class Solution {
2public:
3    int countSpecialIntegers(vector<int>& nums) {
4        vector<pair<int,int>>sorted;
5        for(int i = 0;i<nums.size();i++) {
6            sorted.push_back({nums[i],i});
7        }
8
9        sort(sorted.begin(),sorted.end());
10
11        int cnt = 0;
12        int ans = 0;
13        int n = sorted.size();
14        for(int i = 0;i<sorted.size();i++) {
15            int j = i+1;
16            if(j<n&&sorted[i].first==sorted[j].first) {
17            int diff = sorted[j].second-sorted[i].second;
18            bool same = true;
19            cnt = 0;
20            while(j<n&&(sorted[i].first==sorted[j].first)) {
21                if(diff!=(sorted[j].second-sorted[i].second))  {
22                    same = false;
23                }
24                cnt++;
25                j++;
26                i++;
27            }
28            if(cnt>=2&&same) {
29                ans++;
30           
31            }
32        }
33           
34        }
35        return ans;
36    }
37};