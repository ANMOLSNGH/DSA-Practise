// Last updated: 9/26/2026, 9:57:38 PM
1class Solution {
2public:
3    int longestSubarray(vector<int>& nums, int k) {
4        int ans = 0;
5        
6        for(int i = 0; i < nums.size(); i++){
7            int sum = 0;
8            unordered_set<int>comp;
9            for(int j = i; j < nums.size(); j++){
10                sum += nums[j];
11
12                int rem = ((sum % k) + k) % k;
13
14                if(rem == 0) ans = max(ans, j - i + 1);
15
16                int x = (((nums[j] * 2) % k) + k) % k;
17                comp.insert(x);
18
19                if(comp.count(rem)) ans = max(ans, j - i + 1);
20            }
21        }
22        return ans;
23    }
24};