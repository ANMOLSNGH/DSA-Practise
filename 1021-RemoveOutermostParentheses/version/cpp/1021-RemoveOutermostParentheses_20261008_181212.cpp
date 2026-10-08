// Last updated: 10/8/2026, 6:12:12 PM
1class Solution {
2public:
3    string removeOuterParentheses(string s) {
4        int depth = 0;
5        string ans = "";
6        for(int i=0;i<s.size();i++) {
7            if(s[i]=='(') depth++;
8            else depth--;
9
10            if((depth==1&&s[i]=='(')||depth==0) continue;
11            ans += s[i];          
12        }
13        return ans;
14    }
15};