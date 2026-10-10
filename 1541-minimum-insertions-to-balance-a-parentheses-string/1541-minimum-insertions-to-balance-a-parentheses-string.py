class Solution(object):
    def minInsertions(self, s):
        n = len(s)
        open = 0
        ans = 0

        i = 0
        while i < n:
            if s[i] == '(':
                open += 1
            else:
                if open > 0 and (i + 1 < n and s[i + 1] == ')'):
                    open -= 1
                    i += 1
                elif open > 0:
                    ans += 1
                    open -= 1
                else:
                    if i + 1 < n and s[i + 1] == ')':
                        ans += 1
                        i += 1
                    else:
                        ans += 2

            i += 1

        ans += 2 * open
        return ans