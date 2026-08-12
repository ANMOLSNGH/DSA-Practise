class Solution {
public:
    int dp[20001];
    int n; 

    int solve(int indx, vector<int>& sum) {
        if(indx >= n) return 0;
        if(dp[indx] != -1) return dp[indx];

        int take = sum[indx] + solve(indx + 2, sum);
        int skip = solve(indx + 1, sum);
        
        return dp[indx] = max(take, skip);
    }

    int deleteAndEarn(vector<int>& nums) {
        int max_val = 0;
        for(int num : nums) {
            max_val = max(max_val, num);
        }
        vector<int> sum(max_val + 1, 0);
        for(int num : nums) {
            sum[num] += num;
        }
        n = sum.size();
        memset(dp, -1, sizeof(dp));
        
        return solve(0, sum);   
    }
};