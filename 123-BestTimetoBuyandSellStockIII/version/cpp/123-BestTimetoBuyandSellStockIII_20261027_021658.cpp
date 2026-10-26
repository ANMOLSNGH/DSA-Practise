// Last updated: 10/27/2026, 2:16:58 AM
1class Solution {
2public:
3    int n;
4    vector<vector<vector<int>>> dp;
5
6    int solve(int i, int buy, vector<int>& prices, int cnt) {
7        if (i >= n) return 0;
8        if (cnt == 0) return 0;
9        
10        if (dp[i][buy][cnt] != -1) {
11            return dp[i][buy][cnt];
12        }
13        
14        int profit = 0;
15        
16        if (buy == 1) {
17            int skip = solve(i + 1, 1, prices, cnt);
18            int take = -prices[i] + solve(i + 1, 0, prices, cnt);
19            profit = max(skip, take);
20        } 
21        else {
22            int skip = solve(i + 1, 0, prices, cnt);
23            int take = prices[i] + solve(i + 1, 1, prices, cnt - 1);
24            profit = max(skip, take);
25        }
26        
27        return dp[i][buy][cnt] = profit;
28    }
29
30    int maxProfit(vector<int>& prices) {
31        n = prices.size();
32        int max_t = 2; 
33        
34        dp = vector<vector<vector<int>>>(n, vector<vector<int>>(2, vector<int>(max_t + 1, -1)));
35        
36        return solve(0, 1, prices, max_t);
37    }
38};