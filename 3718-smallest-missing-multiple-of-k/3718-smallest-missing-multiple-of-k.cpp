class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
            int n = nums.size();
            sort(nums.begin(),nums.end());
            bool found = false;
            int indx = 0;
            for(int i = 0;i<n;i++) {
                if(nums[i]==k) {
                    indx = i;
                    found = true;
                    break;
                }
            }
            if(found==false) return k;
            int j = 2; 
            for(int i = indx;i<nums.size();i++) {
                 if(nums[i]==j*k) j++;
            }
            return j*k;
    }
};