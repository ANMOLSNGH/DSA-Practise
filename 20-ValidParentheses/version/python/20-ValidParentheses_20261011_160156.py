# Last updated: 10/11/2026, 4:01:56 PM
1class Solution(object):
2    def isValid(self, s):
3        ans = []
4
5        for indx, paran in enumerate(s):
6            if paran == '(' or paran == '{' or paran == '[':
7                ans.append(paran)
8            else:
9                if paran == ')' and (len(ans) == 0 or ans[-1] != '('):
10                    return False
11                elif paran == '}' and (len(ans) == 0 or ans[-1] != '{'):
12                    return False
13                elif paran == ']' and (len(ans) == 0 or ans[-1] != '['):
14                    return False
15                else:
16                    ans.pop()
17
18        return len(ans) == 0