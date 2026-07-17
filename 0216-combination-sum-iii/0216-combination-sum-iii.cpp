class Solution {
public:
    void solve(vector<vector<int>>& ans, vector<int>& res, int k, int n, int sum, int start) {
        if (sum > n || res.size() > k) return;
        
        if (sum == n && res.size() == k) {
            ans.push_back(res);
            return;
        }
        
        for (int i = start; i <= 9; i++) {
            res.push_back(i);
            solve(ans, res, k, n, sum + i, i + 1);
            res.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> res;
        solve(ans, res, k, n, 0, 1);
        return ans;
    }
};