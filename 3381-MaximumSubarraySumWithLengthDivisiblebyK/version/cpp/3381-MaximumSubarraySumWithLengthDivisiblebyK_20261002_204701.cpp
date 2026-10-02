// Last updated: 10/2/2026, 8:47:01 PM
1class Solution {
2public:
3    typedef long long ll;
4    long long maxSubarraySum(vector<int>& nums, int k) {
5        int n = nums.size();
6
7        vector<ll> pref(n + 1, 0);
8        for (int i = 0; i < n; i++) pref[i + 1] = pref[i] + nums[i];
9
10        vector<ll> dp(n + 1, 0);      
11        ll ans = LLONG_MIN;
12
13        for (int i = k; i <= n; i++) {
14            ll window = pref[i] - pref[i - k];      
15            dp[i] = window + max(0LL, dp[i - k]);    
16            ans = max(ans, dp[i]);
17        }
18        return ans;
19    }
20};