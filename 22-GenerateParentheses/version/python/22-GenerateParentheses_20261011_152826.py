# Last updated: 10/11/2026, 3:28:26 PM
1class Solution:
2    def solve(self,open,close,k,s,li):
3        if open>k//2:
4            return
5        if close>open:
6            return
7        if open + close==k:
8            li.append(s)
9            return
10        
11        # take
12        s += '('
13        self.solve(open+1,close,k,s,li)
14        s = s[:-1]
15        s += ')'
16        self.solve(open,close+1,k,s,li)
17        s = s[:-1]
18
19    def generateParenthesis(self, n: int) -> list[str]:
20
21        s = ""
22        li = []
23        self.solve(0,0,2*n,s,li)
24
25        return li
26        