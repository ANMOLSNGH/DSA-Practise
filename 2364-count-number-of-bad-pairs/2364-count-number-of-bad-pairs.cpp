class Solution {
public:
    using ll = long long;
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<ll,ll>mpp;
        for(int i = 0;i<n;i++) {
            ll val = nums[i] - i;
            mpp[val]++;
        }

        ll ans = 0;
        for(int i = n-1;i>=0;i--) {
            ll val = nums[i] - i;
            ll cnt = 0;
            if(mpp.find(val)!=mpp.end()) {
                cnt = mpp[val] - 1;
                mpp[val]--;
                if(mpp[val]==0) mpp.erase(val);
            }
            ans += (i-cnt);
        }
        return ans;
    }
};