class Solution {
public:
    int INF = 1e9 + 7;
    int minOperations(vector<int>& nums, int sum) {
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,INF));
        
        dp[0][0] = 0; 

        for(int i = 1;i<=n;i++) {
            vector<pair<int,int>>states;
            int curr = nums[i-1];
            int cost = 0;

            // Divison
            while(curr>0) {
                if(curr<=sum) states.push_back({curr,cost});

                curr /= 2;
                cost++;
            }
            
            curr = nums[i-1] * 2; 
            cost = 1;
            while (curr <= sum) {
                states.push_back({curr, cost});
                curr *= 2;
                cost++;
            }
            
            for(int k = 0;k<=sum;k++) {
                dp[i][k] = dp[i-1][k]; 
                
                for(auto state : states) {
                   int val = state.first;
                   int op = state.second;

                   if(k>=val&&dp[i-1][k-val]!=INF) {
                    dp[i][k] = min(dp[i-1][k],dp[i-1][k-val]+op); 
                   }
                }
            }
        }
        return dp[n][sum] == INF ? -1 : dp[n][sum];
    }
};