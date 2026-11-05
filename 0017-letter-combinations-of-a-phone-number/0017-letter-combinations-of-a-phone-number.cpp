class Solution {
public:
    int n;
    unordered_map<char,string>mpp;
    void solve(int indx,string digits,vector<string>&ans,string &res) {
        if(indx==n) {
           ans.push_back(res);
           return;
        }
        char c = digits[indx];
        string get = mpp[c];

        for(int i = 0;i<get.size();i++) {
            res.push_back(get[i]);
            solve(indx+1,digits,ans,res);
            res.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        n = digits.size();
        mpp = {
        {'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},
        {'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
        string res = "";
        vector<string>ans;
        solve(0,digits,ans,res);
        return ans;
    }
};