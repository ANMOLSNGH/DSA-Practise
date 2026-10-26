class Solution {
public:
    int n;
    vector<vector<vector<int>>> dp;

    int solve(int i, int buy, vector<int>& prices, int cnt) {
        if (i >= n) return 0;
        if (cnt == 0) return 0;
        
        if (dp[i][buy][cnt] != -1) {
            return dp[i][buy][cnt];
        }
        
        int profit = 0;
        
        if (buy == 1) {
            int skip = solve(i + 1, 1, prices, cnt);
            int take = -prices[i] + solve(i + 1, 0, prices, cnt);
            profit = max(skip, take);
        } 
        else {
            int skip = solve(i + 1, 0, prices, cnt);
            int take = prices[i] + solve(i + 1, 1, prices, cnt - 1);
            profit = max(skip, take);
        }
        
        return dp[i][buy][cnt] = profit;
    }

    int maxProfit(vector<int>& prices) {
        n = prices.size();
        int max_t = 2; 
        
        dp = vector<vector<vector<int>>>(n, vector<vector<int>>(2, vector<int>(max_t + 1, -1)));
        
        return solve(0, 1, prices, max_t);
    }
};