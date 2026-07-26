class Solution {
public:
    int MOD = 1e9 + 7;
    int memo[51][51][51];
    int rows, cols;
    vector<pair<int, int>> direc = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int solve(int maxMove, int r, int c) {
        if (r < 0 || r >= rows || c < 0 || c >= cols) return 1;
        if (maxMove == 0) return 0;
        if (memo[maxMove][r][c] != -1) return memo[maxMove][r][c];

        long long total_paths = 0;
        for (auto [dr, dc] : direc) {
            total_paths = (total_paths + solve(maxMove - 1, r + dr, c + dc)) % MOD;
        }

        return memo[maxMove][r][c] = total_paths;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        rows = m;
        cols = n;
        memset(memo, -1, sizeof(memo));
        return solve(maxMove, startRow, startColumn);
    }
};