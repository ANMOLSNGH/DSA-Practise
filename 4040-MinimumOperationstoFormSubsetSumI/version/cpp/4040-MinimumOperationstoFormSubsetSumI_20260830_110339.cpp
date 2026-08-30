// Last updated: 8/30/2026, 11:03:39 AM
1class Solution {
2public:
3    int INF = 1e9 + 7;
4    int minOperations(vector<int>& nums, int sum) {
5        int n = nums.size();
6        vector<vector<int>>dp(n+1,vector<int>(sum+1,INF));
7        
8        dp[0][0] = 0; // Base case: 0 sum with 0 elements takes 0 ops
9
10        for(int i = 1;i<=n;i++) {
11            vector<pair<int,int>>states;
12            int curr = nums[i-1];
13            int cost = 0;
14
15            // Divison
16            while(curr>0) {
17                if(curr<=sum) states.push_back({curr,cost});
18
19                curr /= 2;
20                cost++;
21            }
22            
23            curr = nums[i-1] * 2; // Fix: Reset to original number before multiplying
24            cost = 1;
25            while (curr <= sum) {
26                states.push_back({curr, cost});
27                curr *= 2;
28                cost++;
29            }
30            
31            for(int k = 0;k<=sum;k++) {
32                dp[i][k] = dp[i-1][k]; // Fix: Carry over state without using current element
33                
34                for(auto state : states) {
35                   int val = state.first;
36                   int op = state.second;
37
38                   if(k>=val&&dp[i-1][k-val]!=INF) {
39                    dp[i][k] = min(dp[i][k],dp[i-1][k-val]+op); // Fix: Compare against dp[i][k]
40                   }
41                }
42            }
43        }
44        return dp[n][sum] == INF ? -1 : dp[n][sum];
45    }
46};