class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int mini_indx = 0;
        int maxi_indx = 0;
        for(int i = 0;i<nums.size();i++) {
            if(nums[i]>nums[maxi_indx]) {
                maxi_indx = i;
            }
            if(nums[i]<nums[mini_indx]) {
                mini_indx = i;
            }
        }
        int poss1 = max(mini_indx,maxi_indx)+1;
        int poss2 = max(n-mini_indx,n-maxi_indx);
        int poss3 = min(mini_indx+1+n-maxi_indx,n-mini_indx+maxi_indx+1);

        int ans = min({poss1,poss2,poss3});
        return ans;
    }
};