class Solution {
public:
    typedef long long ll;
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        vector<ll> pref(n + 1, 0);
        for (int i = 0; i < n; i++) pref[i + 1] = pref[i] + nums[i];

        vector<ll> dp(n + 1, 0);      
        ll ans = LLONG_MIN;

        for (int i = k; i <= n; i++) {
            ll window = pref[i] - pref[i - k];      
            dp[i] = window + max(0LL, dp[i - k]);    
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};