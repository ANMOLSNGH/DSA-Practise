// Last updated: 10/2/2026, 9:23:16 PM
1class Solution {
2public:
3    int subarraysDivByK(vector<int>& nums, int k) {
4        int n = nums.size();
5        unordered_map<int,int>mpp;
6        int sum = 0;
7        int ans=  0;
8        mpp[0]++;
9        for(int i = 0;i<n;i++) {
10            sum += nums[i];
11            int rem = ((sum%k)+k)%k;
12            if(mpp.find(rem)!=mpp.end()) ans += mpp[rem];
13            mpp[rem]++;
14        }
15        return ans;
16    }
17};