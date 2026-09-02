class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        int possi_indx = 0;
        int negi_indx = 1;
        for(int i = 0;i<n;i++) {
            if(nums[i]>0) {
                ans[possi_indx] = nums[i];
                possi_indx += 2;
            }
            else {
                ans[negi_indx] = nums[i];
                negi_indx += 2;
            }
        }
        return ans;
    }
};