// Last updated: 10/14/2026, 6:49:58 PM
1class Solution {
2public:
3    typedef long long ll;
4    vector<int> maxProductPair(vector<int>& nums, int target) {
5        unordered_map<int, int> mpp;
6        ll maxi_prod = LLONG_MIN;
7        int valid_i = -1;
8        int valid_j = -1;
9        
10        for (int i = 0; i < nums.size(); i++) {
11             int rem = target - nums[i];
12
13             if (mpp.find(rem) != mpp.end()) {
14                 if (nums[i] != rem) {
15                     ll prod = (ll)rem * nums[i];
16                     
17                     if (prod > maxi_prod) {
18                        maxi_prod = prod;
19                        
20                        if (nums[i] > rem) {
21                            valid_i = i;
22                            valid_j = mpp[rem]; 
23                        } else {
24                            valid_i = mpp[rem];
25                            valid_j = i;
26                        }
27                     }
28                 }
29             }
30             mpp[nums[i]] = i;
31        }
32
33        return {valid_i, valid_j};
34    }
35};