// Last updated: 10/2/2026, 11:29:19 AM
1class Solution {
2public:
3    void solve(int k,int open,int close,int cnt,string &s,vector<string>&ans) {
4        if(open>k/2) return;
5        if(close>open) return;
6        if(cnt==0) {
7            ans.push_back(s);
8            return;
9        }
10
11        // take '('
12        s += '(';
13        solve(k,open+1,close,cnt-1,s,ans);
14        s.pop_back();
15        // take ')'
16        s += ')';
17        solve(k,open,close+1,cnt-1,s,ans);
18        s.pop_back();
19    }
20    vector<string> generateParenthesis(int n) {
21        vector<string>ans;
22        string s = "";
23        solve(2*n,0,0,2*n,s,ans);
24        return ans;
25    }
26};