class Solution {
public:
    typedef long long ll;
    long long countPairs(vector<int>& nums, int k) {
        unordered_map<ll,ll>mpp;
        ll cnt = 0;
        for(int i = 0;i<nums.size();i++) {
            int curr_div = gcd(nums[i],k);
            for(auto it : mpp) {
                if((curr_div*it.first)%k==0) cnt += it.second;
            }
            mpp[curr_div]++;
        }
        return cnt;
    }
};