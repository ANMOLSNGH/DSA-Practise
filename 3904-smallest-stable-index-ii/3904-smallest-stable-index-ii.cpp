class Solution {
public:
    int large = 1e9+7;
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>pref(n+1,0);
        vector<int>suff(n+1,large);
        for(int i = 1;i<=n;i++) {
            pref[i] = max(pref[i-1],nums[i-1]);
        }

        for(int i = n-1;i>=0;i--) {
            suff[i] = min(suff[i+1],nums[i]);
        }
        
        int indx = -1;
        int val = large;
        for(int i = 0;i<n;i++) {
            int maxi = pref[i+1];
            int mini = suff[i];
            int diff = maxi-mini;
            if(diff<=k) {
                indx = i;
                break;
            }

    }
    return indx;
    }
};