// Last updated: 10/2/2026, 1:59:20 AM
1class Solution {
2public:
3    bool isValid(string s) {
4        stack<char>st;
5        int i =0;
6        int n = s.size();
7        
8      for(int i = 0;i<n;i++) {
9            if(!st.empty()&&(s[i]==')'&&st.top()=='('||s[i]=='}'&&st.top()=='{'||s[i]==']'&&st.top()=='[')) {
10                st.pop();
11            }
12            else {
13            st.push(s[i]);
14            }
15        }
16    
17        bool ans = st.empty()? true : false;
18        return ans;
19    }
20};