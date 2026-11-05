// Last updated: 11/5/2026, 9:42:00 AM
1class Solution {
2public:
3    int n;
4    unordered_map<char,string>mpp;
5    void solve(int indx,string digits,vector<string>&ans,string &res) {
6        if(indx==n) {
7           ans.push_back(res);
8           return;
9        }
10        char c = digits[indx];
11        string get = mpp[c];
12
13        for(int i = 0;i<get.size();i++) {
14            res.push_back(get[i]);
15            solve(indx+1,digits,ans,res);
16            res.pop_back();
17        }
18    }
19    vector<string> letterCombinations(string digits) {
20        n = digits.size();
21        mpp = {
22        {'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},
23        {'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
24        string res = "";
25        vector<string>ans;
26        solve(0,digits,ans,res);
27        return ans;
28    }
29};