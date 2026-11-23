class Solution {
public:
    typedef long long ll;
    long long minCost(vector<int>& nums) {
        int n = nums.size();
        ll even = 0;
        ll odd = LLONG_MAX/4;
        ll base_case = nums[0] + nums[n-1];
        for(int i = 1;i<n-1;i++) {
            ll newEven = min(even,odd+nums[i]);
            ll newOdd = min(odd,even+nums[i]);

            even = newEven;
            odd = newOdd;
        }
        return base_case + even;
    }
};