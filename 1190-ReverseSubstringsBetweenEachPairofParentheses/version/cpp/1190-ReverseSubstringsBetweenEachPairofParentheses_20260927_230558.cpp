// Last updated: 9/27/2026, 11:05:58 PM
1class Solution {
2public:
3    string reverseParentheses(string s) {
4        int n = s.size();
5        stack<int> st;
6        unordered_map<int, int> mpp; 
7        
8        for (int i = 0; i < n; i++) {
9            if (s[i] == '(') {
10                st.push(i);
11            } else if (s[i] == ')') {
12                int j = st.top();
13                st.pop();
14                mpp[i] = j;
15                mpp[j] = i; 
16            }
17        }
18        
19        string ans = "";
20        int dir = 1; 
21        
22        for (int i = 0; i < n; i += dir) {
23            if (s[i] == '(' || s[i] == ')') {
24                i = mpp[i]; 
25                dir = -dir; 
26            } else {
27                ans += s[i]; 
28            }
29        }
30        
31        return ans;
32    }
33};