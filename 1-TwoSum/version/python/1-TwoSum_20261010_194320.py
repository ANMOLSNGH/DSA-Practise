# Last updated: 10/10/2026, 7:43:20 PM
1
2class Solution:
3    def twoSum(self, nums: list[int], target: int) -> list[int]:
4        mpp = {}
5
6        for idx, num in enumerate(nums):
7            rem = target - num
8
9            if rem in mpp:
10                return [mpp[rem], idx]
11
12            mpp[num] = idx
13
14        return []
15