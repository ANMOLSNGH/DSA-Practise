class Solution {
public:
    void solve(set<vector<int>>& ans, vector<int>& res, int k, int n, int sum, int bitmask) {
        if(sum > n || res.size() > k) return;
        
        if(sum == n && res.size() == k) {
            vector<int> temp = res;
            sort(temp.begin(), temp.end());
            ans.insert(temp);
            return;
        }
        
        for(int i = 1; i < 10; i++) {
            if(((1 << i) & bitmask) == 0) {
                sum += i;
                res.push_back(i);
                solve(ans, res, k, n, sum, bitmask | (1 << i));
                sum -= i;
                res.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        set<vector<int>> st;
        vector<int> res;
        solve(st, res, k, n, 0, 0);
        
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};