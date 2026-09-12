// Last updated: 9/12/2026, 8:53:22 PM
1class Solution {
2public:
3    int minDays(int n) {
4        if (n == 0) return 0;
5        vector<int> dp(n + 1, 1e9);
6        vector<int> streaks;
7        for (int k = 1; ; k++) {
8            long long score = (long long)k * (k + 1) / 2;
9            if (score > n) break;
10            streaks.push_back(k);
11        }
12        dp[0] = 0;
13        for (int i = 1; i <= n; i++) {
14            for (int k : streaks) {
15                int score = k * (k + 1) / 2;
16                if (i >= score) {
17                  
18                    int cost = (i == score) ? k : dp[i - score] + k + 1;
19                    
20                    if (cost < dp[i]) {
21                        dp[i] = cost;
22                    }
23                } else {
24                    break;
25                }
26            }
27        }
28        
29        return dp[n];
30    }
31};