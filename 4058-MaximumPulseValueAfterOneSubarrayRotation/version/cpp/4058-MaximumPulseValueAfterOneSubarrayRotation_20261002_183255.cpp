// Last updated: 10/2/2026, 6:32:55 PM
1class Solution {
2public:
3    typedef long long ll;
4    long long maxValue(vector<int>& nums) {
5        int n = nums.size();
6        ll S = 0;
7        vector<ll> b(n);
8        for (int i = 0; i < n; i++) {
9            int sign = (i % 2 == 0) ? 1 : -1;
10            S += sign * nums[i];
11            b[i] = -2LL * sign * nums[i];
12        }
13
14        vector<ll> dp(n, 0);   // dp[i] = best even-length sum of b ending at i
15        ll gain = 0;           //
16        for (int i = 1; i < n; i++) {
17            dp[i] = b[i - 1] + b[i] + max(0LL, dp[i - 2 < 0 ? 0 : i - 2]);
18            gain = max(gain, dp[i]);
19        }
20        return S + gain;
21    }
22};