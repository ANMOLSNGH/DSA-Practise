class Solution {
public:
    using ll = long long;
    int n;
    long long minCost(vector<int>& nums) {
        n = nums.size();
        vector<int> last_seen(n), ahead_seen(n);
        
        last_seen[0] = 0;
        for (int i = 1; i < n; i++) {
            last_seen[i] = nums[i] == nums[i - 1] ? last_seen[i - 1] : i;
        }
        
        ahead_seen[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            ahead_seen[i] = nums[i] == nums[i + 1] ? ahead_seen[i + 1] : i;
        }

        if (last_seen[n - 1] == 0) return 0;

        ll ans = LLONG_MAX;
        for (int i = 1; i < n - 1; i++) {
            ll result = 0;
            result += 1LL * last_seen[i] * nums[i];
            result += 1LL * (n - 1 - ahead_seen[i]) * nums[i];

            ans = min(ans, result);
        }
        return ans;
    }
};