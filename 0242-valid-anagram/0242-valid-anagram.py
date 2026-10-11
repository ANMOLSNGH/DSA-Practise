class Solution(object):
    def isAnagram(self, s, t):
        mpp = {}
        for i in s:
            if mpp.get(i,0):
                mpp[i] += 1
            else:
                mpp[i] = 1

        for i in t:
            if mpp.get(i,0):
                mpp[i] -= 1

                if mpp[i] ==0:
                   del mpp[i]
            else:
                return False
                break

        if len(mpp)==0 :
            return True
         
        return False
            
            
        