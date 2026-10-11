# Last updated: 10/11/2026, 7:14:37 PM
1
2class Solution(object):
3    def maxProfit(self, prices):
4        n = len(prices)
5        suff = [0] * n
6
7        for i in range(n - 1, -1, -1):
8            if i == n - 1:
9                suff[i] = prices[i]
10            else:
11                if suff[i + 1] < prices[i]:
12                    suff[i] = prices[i]
13                else:
14                    suff[i] = suff[i + 1]
15
16        ans = 0
17
18        for i in range(n):
19            ans = max(ans, suff[i] - prices[i])
20
21        return ans
22