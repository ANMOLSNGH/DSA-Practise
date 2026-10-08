class Solution {
public:
    string removeOuterParentheses(string s) {
        int depth = 0;
        string ans = "";
        for(int i=0;i<s.size();i++) {
            if(s[i]=='(') depth++;
            else depth--;

            if((depth==1&&s[i]=='(')||depth==0) continue;
            ans += s[i];          
        }
        return ans;
    }
};