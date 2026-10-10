# Last updated: 10/10/2026, 5:11:58 PM
1class Solution(object):
2    def kidsWithCandies(self, candies, extraCandies):
3
4      maxi = -58
5      for i in  candies:
6        if i>maxi:
7            maxi = i
8      
9      ans = []
10
11      for i in candies:
12        if extraCandies+i>=maxi:
13            ans.append(True)
14        else:
15            ans.append(False)
16
17      return ans
18        