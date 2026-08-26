// Last updated: 8/26/2026, 1:02:14 PM
1class Solution {
2public:
3    int dp[1001][1001];
4    int n, m;
5    
6    int solve(int i, int j, string& s1, string& s2) {
7        if (j >= m) return 1;
8        if (i >= n) return 0;
9
10        if (dp[i][j] != -1) return dp[i][j];
11
12        if (s1[i] == s2[j]) {
13            return dp[i][j] = (unsigned int)solve(i + 1, j, s1, s2) + solve(i + 1, j + 1, s1, s2);
14        } else {
15            return dp[i][j] = solve(i + 1, j, s1, s2);
16        }
17    }
18    
19    int numDistinct(string s, string t) {
20        n = s.size();
21        m = t.size();
22        memset(dp, -1, sizeof(dp));
23        return solve(0, 0, s, t);
24    }
25};