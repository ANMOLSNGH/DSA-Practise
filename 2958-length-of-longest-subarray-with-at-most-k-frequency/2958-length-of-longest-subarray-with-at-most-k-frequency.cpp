class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n  = nums.size();
        int maxilen = 1;
        if(k<=0) return 0;
        int i = 0,j = 0;
        unordered_map<int,int>mpp;
        for(int j = 0;j<n;j++) {
            mpp[nums[j]]++;
            if(mpp[nums[j]]>k) {
                while(nums[i]!=nums[j]) {
                    mpp[nums[i]]--;
                    if(mpp[nums[i]]==0) mpp.erase(nums[i]);
                    i++;
                }
                mpp[nums[i]]--;
                if(mpp[nums[i]]==0) mpp.erase(nums[i]);
                i++;
            }
            maxilen = max(maxilen,j-i+1);
        }
        return maxilen;
    }
};