class Solution {
public:
    int n;
    vector<vector<int>> memo;

    int maxi(vector<int>& nums, int indx, int taken) {

        if (indx >= n) return 0;
        if (taken && indx == n - 1) return 0;
        

        if (memo[indx][taken] != -1) return memo[indx][taken];


        int next_take = (indx == 0) ? 1 : taken;
        

        int take = nums[indx] + maxi(nums, indx + 2, next_take);
        int skip = maxi(nums, indx + 1, taken);
        

        int ans = max(take, skip);
        return memo[indx][taken] = ans;
    } 

    int rob(vector<int>& nums) {
        n = nums.size();
        
        if (n == 1) return nums[0];
        
   
        memo.assign(n, vector<int>(2, -1));
        
        return maxi(nums, 0, 0);
    }
};