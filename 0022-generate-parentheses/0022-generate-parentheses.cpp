class Solution {
public:
    void solve(int k,int open,int close,int cnt,string &s,vector<string>&ans) {
        if(open>k/2) return;
        if(close>open) return;
        if(cnt==0) {
            ans.push_back(s);
            return;
        }

        // take '('
        s += '(';
        solve(k,open+1,close,cnt-1,s,ans);
        s.pop_back();
        // take ')'
        s += ')';
        solve(k,open,close+1,cnt-1,s,ans);
        s.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string s = "";
        solve(2*n,0,0,2*n,s,ans);
        return ans;
    }
};