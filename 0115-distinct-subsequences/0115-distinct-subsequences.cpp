class Solution {
public:
    int dp[1001][1001];
    int n, m;
    
    int solve(int i, int j, string& s1, string& s2) {
        if (j >= m) return 1;
        if (i >= n) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        if (s1[i] == s2[j]) {
            return dp[i][j] = (unsigned int)solve(i + 1, j, s1, s2) + solve(i + 1, j + 1, s1, s2);
        } else {
            return dp[i][j] = solve(i + 1, j, s1, s2);
        }
    }
    
    int numDistinct(string s, string t) {
        n = s.size();
        m = t.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, s, t);
    }
};