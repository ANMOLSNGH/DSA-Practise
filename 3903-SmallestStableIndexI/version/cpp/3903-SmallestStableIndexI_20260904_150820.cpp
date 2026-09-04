// Last updated: 9/4/2026, 3:08:20 PM
1class Solution {
2public:
3    int large = 1e9+7;
4    int firstStableIndex(vector<int>& nums, int k) {
5        int n = nums.size();
6        vector<int>pref(n+1,0);
7        vector<int>suff(n+1,large);
8        for(int i = 1;i<=n;i++) {
9            pref[i] = max(pref[i-1],nums[i-1]);
10        }
11
12        for(int i = n-1;i>=0;i--) {
13            suff[i] = min(suff[i+1],nums[i]);
14        }
15        
16        int indx = -1;
17        int val = large;
18        for(int i = 0;i<n;i++) {
19            int maxi = pref[i+1];
20            int mini = suff[i];
21            int diff = maxi-mini;
22            if(diff<=k) {
23                indx = i;
24                break;
25            }
26
27    }
28    return indx;
29    }
30};