class Solution {
public:
    int dp[501][501];
    int solve(int i ,int j,vector<int>&stoneValue,vector<int>&pref_sum) {
        if(i==j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        long long maxi_sum = 0;
        for(int k = i;k<j;k++) {
           long long left_sum = pref_sum[k+1] - pref_sum[i];
           long long right_sum = pref_sum[j+1] - pref_sum[k+1];
           if(left_sum>right_sum) {
               maxi_sum = max(maxi_sum,right_sum+solve(k+1,j,stoneValue,pref_sum));
           }

           else if(left_sum<right_sum) {
            maxi_sum = max(maxi_sum,left_sum+solve(i,k,stoneValue,pref_sum));
           }

           else {
             long long option1 = left_sum + solve(i,k,stoneValue,pref_sum);
             long long option2 = right_sum+solve(k+1,j,stoneValue,pref_sum);
             maxi_sum = max(option1,option2);
           }
        }
        return dp[i][j] = maxi_sum;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        
        memset(dp, -1, sizeof(dp));
        vector<int> pref_sum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pref_sum[i + 1] = pref_sum[i] + stoneValue[i];
        }
        return solve(0,n-1,stoneValue,pref_sum);
    }
};