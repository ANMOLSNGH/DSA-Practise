class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)

        dp = [[False] * (n + 1) for _ in range(n + 1)]

        for i in range(0, n + 1):
            dp[i][i] = True

        ans = 1
        start = 0  

        for length in range(2, n + 1):
            for i in range(0, n - length + 1):
                j = i + length - 1

                if length == 2:
                    if s[i] == s[j]:
                        dp[i][j] = True
                else:
                    if s[i] == s[j] and dp[i + 1][j - 1]:
                        dp[i][j] = True

                if dp[i][j] == True:
                    if length > ans:
                        ans = length
                        start = i

        return s[start:start + ans]