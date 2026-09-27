You are given an integer array nums.

You start with an empty array ans. Repeat the following operation until nums is empty:


	Identify all distinct values currently present in nums.
	Remove one occurrence of every distinct value currently in nums, and append those values to ans in ascending order.


Return the array ans.

 
Example 1:


Input: nums = [3,1,3,2,1,3]

Output: [1,2,3,1,3,3]

Explanation:

OperationAppended to ansnums afterans after11, 2, 3[3, 1, 3][1, 2, 3]21, 3[3][1, 2, 3, 1, 3]33[][1, 2, 3, 1, 3, 3]

nums is now empty, so the answer is [1, 2, 3, 1, 3, 3].


Example 2:


Input: nums = [7,7,4,4,4]

Output: [4,7,4,7,4]

Explanation:

OperationAppended to ansnums afterans after14, 7[7, 4, 4][4, 7]24, 7[4][4, 7, 4, 7]34[][4, 7, 4, 7, 4]

nums is now empty, so the answer is [4, 7, 4, 7, 4].


 
Constraints:


	1 <= nums.length <= 100
	1 <= nums[i] <= 100

