class Solution {
public:
   typedef long long ll;
    int minOperations(vector<int>& nums, int x) {
        unordered_map<ll,int>mpp;
        int n = nums.size();
        ll suff = 0;
        int ans = 1e9;
        for(int i = nums.size()-1;i>=0&&suff<x;i--) {
            suff += nums[i];
            if(suff==x) ans = min(ans,n-i);
            mpp[suff] = i;
        }

        ll pref = 0;
        for(int i = 0;i<nums.size();i++) {
            pref += nums[i];
            if(pref==x) ans = min(ans,i+1);
            ll target = x-pref;
            if(mpp.find(target)!=mpp.end()) {
                int indx = mpp[target];
                if(indx>i)
                ans = min(ans,i+1+n-indx);
            }
        }
        return ans==1e9?-1:ans;
    }
};