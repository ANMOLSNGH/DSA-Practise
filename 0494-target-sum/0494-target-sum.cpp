class Solution {
public:
    int dp[21][2001];
    int n;
    int solve(int i,int j,int target,vector<int>&nums) {
        if(i==n) {
            if(j==target) return 1;
            return 0;
        }

        if(dp[i][j+1000]!=-1) return dp[i][j+1000];

        int add = solve(i+1,j+nums[i],target,nums);
        int sub = solve(i+1,j-nums[i],target,nums);
        return dp[i][j+1000] = add+sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        n  = nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,target,nums);
    }
};