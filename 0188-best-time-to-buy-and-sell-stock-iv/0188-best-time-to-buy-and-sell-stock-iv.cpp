class Solution {
public:
    int maxProfit(int k, std::vector<int>& prices) {
        int n = prices.size();
        if (n == 0 || k == 0) return 0;

        if (k >= n / 2) {
            int max_profit = 0;
            for (int i = 1; i < n; ++i) {
                if (prices[i] > prices[i - 1]) {
                    max_profit += prices[i] - prices[i - 1];
                }
            }
            return max_profit;
        }

        std::vector<int> buy(k + 1, INT_MIN);
        std::vector<int> sell(k + 1, 0);

        for (int price : prices) {
            for (int i = 1; i <= k; ++i) {
                buy[i]  = std::max(buy[i], sell[i - 1] - price);
                
                sell[i] = std::max(sell[i], buy[i] + price);
            }
        }

        return sell[k];
    }
};