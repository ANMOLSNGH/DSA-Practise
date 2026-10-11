
class Solution(object):
    def maxProfit(self, prices):
        n = len(prices)
        suff = [0] * n

        for i in range(n - 1, -1, -1):
            if i == n - 1:
                suff[i] = prices[i]
            else:
                if suff[i + 1] < prices[i]:
                    suff[i] = prices[i]
                else:
                    suff[i] = suff[i + 1]

        ans = 0

        for i in range(n):
            ans = max(ans, suff[i] - prices[i])

        return ans
