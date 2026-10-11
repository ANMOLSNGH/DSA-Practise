class Solution(object):
    def solve(self,open,close,k,s,li):
        if open>k//2:
            return
        if close>open:
            return
        if open + close==k:
            li.append(s)
            return
        
        # take
        s += '('
        self.solve(open+1,close,k,s,li)
        s = s[:-1]
        s += ')'
        self.solve(open,close+1,k,s,li)
        s = s[:-1]

    def generateParenthesis(self, n):
        s = ""
        li = []
        self.solve(0,0,2*n,s,li)

        return li
        
        