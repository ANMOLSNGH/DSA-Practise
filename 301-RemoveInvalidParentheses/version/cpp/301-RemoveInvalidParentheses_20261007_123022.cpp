// Last updated: 10/7/2026, 12:30:22 PM
1class Solution {
2public:
3    int n;
4    unordered_set<string> validSet; 
5
6    void allpossible(int open, int close, int indx, int n_open, int n_close, string &s, string &given) {
7        if(indx == n) {
8            if(n_open == 0 && n_close == 0 && open == 0 && close == 0) {
9                validSet.insert(s);
10            }
11            return;
12        }
13
14        char ch = given[indx];
15        
16        if(ch == '(') {
17            if(open > 0)  {
18                s.push_back('(');
19                allpossible(open, close, indx+1, n_open+1, n_close, s, given);
20                s.pop_back();
21                allpossible(open-1, close, indx+1, n_open, n_close, s, given);
22            }
23            else if(open == 0) { 
24                s.push_back('(');
25                allpossible(open, close, indx+1, n_open+1, n_close, s, given);
26                s.pop_back(); 
27            }
28        }
29        else if(ch == ')') {
30            if(close > 0) {
31                s.push_back(')');
32                if(n_open > 0)
33                    allpossible(open, close, indx+1, n_open-1, n_close, s, given);
34                else 
35                    allpossible(open, close, indx+1, n_open, n_close+1, s, given);
36                s.pop_back();
37                allpossible(open, close-1, indx+1, n_open, n_close, s, given);
38            }
39            else if(close == 0) {
40                s.push_back(')');
41                if(n_open > 0)
42                    allpossible(open, close, indx+1, n_open-1, n_close, s, given);
43                else 
44                    allpossible(open, close, indx+1, n_open, n_close+1, s, given);
45                s.pop_back(); 
46            }
47        }
48        else { 
49            s.push_back(ch);
50            allpossible(open, close, indx+1, n_open, n_close, s, given);
51            s.pop_back();
52        }
53    }
54    
55    vector<string> removeInvalidParentheses(string s) {
56        n = s.size();
57        
58        int open_rem = 0, close_rem = 0;
59        for (char ch : s) {
60            if (ch == '(') {
61                open_rem++;
62            } else if (ch == ')') {
63                if (open_rem > 0) open_rem--;
64                else close_rem++;
65            }
66        }
67
68        string temp = "";
69        allpossible(open_rem, close_rem, 0, 0, 0, temp, s);
70        
71        return vector<string>(validSet.begin(), validSet.end());
72    }
73};