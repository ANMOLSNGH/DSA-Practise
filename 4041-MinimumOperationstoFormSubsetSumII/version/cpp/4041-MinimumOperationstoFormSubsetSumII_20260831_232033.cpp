// Last updated: 8/31/2026, 11:20:33 PM
1class Solution {
2public:
3    int INF  = 1e9 + 7;
4    
5    int minOperations(vector<int>& nums, int sum) {
6        int n = nums.size();
7        vector<vector<int>> dp(n+1, vector<int>(sum+1, INF));
8        dp[0][0] = 0;
9        
10        for(int i = 1; i <= n; i++) {
11            vector<pair<int,int>> states;
12            int curr = nums[i-1];
13            int divs = 0; 
14            
15            while(curr > 0) {
16                int val = curr;
17                int cost = divs;
18                
19                while(val <= sum) {
20                    states.push_back({val, cost});
21                    val *= 2;
22                    cost++; 
23                }
24                
25                curr /= 2;
26                divs++;
27            }
28
29            for(int k = 0; k <= sum; k++) {
30                dp[i][k] = dp[i-1][k];
31                
32                for(auto state : states) {
33                    int val = state.first;
34                    int ops = state.second;
35                    
36                    if(k >= val && dp[i-1][k-val] != INF) {
37                        dp[i][k] = min(dp[i][k], dp[i-1][k-val] + ops);
38                    }
39                }
40            }
41        }
42        
43        return dp[n][sum] == INF ? -1 : dp[n][sum];
44    }
45};