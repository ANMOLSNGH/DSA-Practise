class Solution {
public:
    typedef long long ll;
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int n = nums.size();
        int m = numsDivide.size();
        ll gcd1 = numsDivide[0];
        for(int i = 1;i<m;i++) {
            gcd1 = gcd(gcd1,numsDivide[i]);
            if(gcd1==1) break;
        }
        bool got = false;
        int mini = INT_MAX;
        for(int i = 0;i<n;i++) {
            if(gcd1%nums[i]==0) {
                mini = min(mini,nums[i]);
                got = true;
            }
           
        }
        int delete_ = 0;

        if(got) {
            for(int i = 0;i<n;i++) {
                if(nums[i]<mini) delete_++;
            }

            return delete_;
        }
        return -1;
    }
};