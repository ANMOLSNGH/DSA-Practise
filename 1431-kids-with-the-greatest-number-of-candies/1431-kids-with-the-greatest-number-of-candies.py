class Solution(object):
    def kidsWithCandies(self, candies, extraCandies):

      maxi = -58
      for i in  candies:
        if i>maxi:
            maxi = i
      
      ans = []

      for i in candies:
        if extraCandies+i>=maxi:
            ans.append(True)
        else:
            ans.append(False)

      return ans
        