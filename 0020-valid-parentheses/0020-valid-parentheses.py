class Solution(object):
    def isValid(self, s):
        ans = []

        for indx, paran in enumerate(s):
            if paran == '(' or paran == '{' or paran == '[':
                ans.append(paran)
            else:
                if paran == ')' and (len(ans) == 0 or ans[-1] != '('):
                    return False
                elif paran == '}' and (len(ans) == 0 or ans[-1] != '{'):
                    return False
                elif paran == ']' and (len(ans) == 0 or ans[-1] != '['):
                    return False
                else:
                    ans.pop()

        return len(ans) == 0