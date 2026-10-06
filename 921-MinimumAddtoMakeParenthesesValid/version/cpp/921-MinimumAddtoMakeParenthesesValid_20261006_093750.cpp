// Last updated: 10/6/2026, 9:37:50 AM
1class Solution {
2public:
3    int minAddToMakeValid(string s) {
4        stack<int>st;
5        int cnt = 0;
6        for(int i = 0;i<s.size();i++) {
7            if(s[i]==')'&&st.empty()) cnt++;
8            else if(s[i]==')'&&!st.empty()) st.pop();
9            else if(s[i]=='(') st.push(i);
10        }
11        while(!st.empty()) {
12            st.pop();
13            cnt++;
14        }
15        return cnt;
16    }
17};