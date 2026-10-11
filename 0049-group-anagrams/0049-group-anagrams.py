class Solution(object):
    def groupAnagrams(self, strs):
        
       mpp = {}
       nums = []

       for string in strs:
        sorted_str = ''.join(sorted(string))
        if mpp.get(sorted_str,0):
            mpp[sorted_str].append(string)
        else:
            mpp[sorted_str] = [string]

        
       for key,value in mpp.items():
        nums.append(value)

       return nums
        

        