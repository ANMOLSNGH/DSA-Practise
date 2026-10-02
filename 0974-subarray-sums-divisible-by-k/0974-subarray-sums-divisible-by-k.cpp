class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mpp;
        int sum = 0;
        int ans=  0;
        mpp[0]++;
        for(int i = 0;i<n;i++) {
            sum += nums[i];
            int rem = ((sum%k)+k)%k;
            if(mpp.find(rem)!=mpp.end()) ans += mpp[rem];
            mpp[rem]++;
        }
        return ans;
    }
};