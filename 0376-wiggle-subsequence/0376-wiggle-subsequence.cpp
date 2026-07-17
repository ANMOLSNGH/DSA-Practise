class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n<2) return n;

        int up = 1;
        int down = 1;

        for(int i = 1;i<n;i++) {
            int diff = nums[i] - nums[i-1];
            if(diff>0) {
                up  = 1 + down;
            }
            else if(diff<0) {
                down = 1 + up;
            }
        }
        return max(up,down);
    }
};