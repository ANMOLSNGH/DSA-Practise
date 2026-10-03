// Last updated: 10/4/2026, 1:12:47 AM
1class Solution {
2public:
3    int longestValidParentheses(string s) {
4        stack<int> st;
5        st.push(-1); 
6        int maxi = 0;
7        
8        for (int i = 0; i < s.size(); i++) {
9            if (s[i] == '(') {
10                st.push(i);
11            } else {
12                st.pop(); 
13                
14                if (st.empty()) {
15                   
16                    st.push(i);
17                } else {
18                    
19                    maxi = max(maxi, i - st.top());
20                }
21            }
22        }
23        return maxi;
24    }
25};