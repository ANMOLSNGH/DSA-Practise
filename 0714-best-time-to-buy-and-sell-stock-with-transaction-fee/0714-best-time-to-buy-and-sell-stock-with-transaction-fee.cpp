class Solution {
public:
    int maxProfit(std::vector<int>& prices, int fee) {
        if (prices.empty()) return 0;

        int hold = -prices[0];
        int free = 0;

        for (int i = 1; i < prices.size(); ++i) {
            int prev_hold = hold;
            int prev_free = free;
            hold = std::max(prev_hold, prev_free - prices[i]);
            free = std::max(prev_free, prev_hold + prices[i] - fee);
        }
        return free;
    }
};