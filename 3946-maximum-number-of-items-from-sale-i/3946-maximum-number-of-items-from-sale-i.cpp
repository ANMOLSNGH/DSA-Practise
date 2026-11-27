class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> copies(1501, 0);
        for (auto& item : items) {
            int factor = item[0];
            for (int i = 1; i * i <= factor; i++) {
                if (factor % i == 0) {
                    copies[i]++;
                    if (i * i != factor) copies[factor / i]++;
                }
            }
        }

        vector<vector<int>> dp(n + 1, vector<int>(budget + 1, 0));

        for (int i = 1; i <= n; i++) {
            int f = items[i - 1][0];
            int p = items[i - 1][1];

            for (int b = 0; b <= budget; b++) {
                // 1. Skip current item
                dp[i][b] = dp[i - 1][b];

                if (b >= p) {
                    // 2. First copy (from previous row): gain copies[f]
                    dp[i][b] = max(dp[i][b], dp[i - 1][b - p] + copies[f]);

                    // 3. Additional copy (from current row): gain 1
                    dp[i][b] = max(dp[i][b], dp[i][b - p] + 1);
                }
            }
        }

        return dp[n][budget];
    }
};