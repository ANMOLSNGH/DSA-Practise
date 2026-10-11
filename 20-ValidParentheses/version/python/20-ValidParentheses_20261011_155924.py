# Last updated: 10/11/2026, 3:59:24 PM
1
2class Solution(object):
3    def isValid(self, s):
4        ans = ""
5
6        for indx, paran in enumerate(s):
7            if paran == '(' or paran == '{' or paran == '[':
8                ans += paran
9            else:
10                if paran == ')' and (len(ans) == 0 or ans[-1] != '('):
11                    return False
12                elif paran == '}' and (len(ans) == 0 or ans[-1] != '{'):
13                    return False
14                elif paran == ']' and (len(ans) == 0 or ans[-1] != '['):
15                    return False
16                else:
17                    ans = ans[:-1]
18
19        return len(ans) == 0
20