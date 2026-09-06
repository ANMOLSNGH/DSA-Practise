// Last updated: 9/6/2026, 12:08:33 PM
1class Solution {
2public:
3    int maxProduct(vector<int>& nums) {
4        int n = nums.size();
5        int pref = 1;
6        int suff = 1;
7        int maxi_prod = nums[0];
8        for(int i = 0;i<n;i++) {
9            if(pref==0) pref = 1;
10            if(suff==0) suff = 1;
11
12            pref = pref*nums[i];
13            suff = suff*nums[n-i-1];
14            maxi_prod = max({maxi_prod,pref,suff});
15        }
16        return maxi_prod;
17    }
18};