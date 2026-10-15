class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int maxi_cons = 0;
        int j = 0;
        for(int i = 0;i<n;i++) {
           if(nums[i]!=1) {
              j = i+1;
           }
           maxi_cons = max(maxi_cons,i-j+1);
        }
        return maxi_cons;
    }
};