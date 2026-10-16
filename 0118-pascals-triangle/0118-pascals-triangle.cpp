class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for (int i = 0; i < numRows; i++) {
            vector<int> res;
            long long val = 1;
            for (int j = 0; j <= i; j++) {
                if (j != 0) {
                    val = val * (i - j + 1) / j;
                }
                res.push_back(val);
            }
            ans.push_back(res);
        }
        return ans;
    }
};