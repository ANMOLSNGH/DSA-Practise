You are given a tree with n nodes numbered from 0 to n - 1, represented by a 2D integer array edges. Each edges[i] = [ui, vi, ci] represents an edge between nodes ui and vi with cost ci.

You are also given an integer array values of length n, where values[i] is the value of node i.

A path between two distinct nodes is Balanced-XOR if the bitwise XOR of the values of all nodes on the path, including both endpoints, has an even number of set bits.

The cost of a path is the sum of its edge costs.

Return the minimum cost of a Balanced-XOR path. If no such path exists, return -1.

The number 0 has zero set bits.

 
Example 1:




Input: edges = [[0,1,4],[0,2,6],[0,3,3],[3,4,5]], values = [3,1,7,1,3]

Output: 7

Explanation:

Balanced-XOR PathXOR ValueTotal Cost1 - 0 - 21 XOR 3 XOR 7 = 54 + 6 = 101 - 0 - 31 XOR 3 XOR 1 = 34 + 3 = 71 - 0 - 3 - 41 XOR 3 XOR 1 XOR 3 = 04 + 3 + 5 = 122 - 0 - 37 XOR 3 XOR 1 = 56 + 3 = 92 - 0 - 3 - 47 XOR 3 XOR 1 XOR 3 = 66 + 3 + 5 = 14

The minimum cost is 7, achieved by the path 1 - 0 - 3. Thus, the answer is 7.


Example 2:




Input: edges = [[0,1,5],[1,2,10]], values = [1,7,3]

Output: 5

Explanation:

Balanced-XOR PathXOR ValueTotal Cost0 - 11 XOR 7 = 650 - 1 - 21 XOR 7 XOR 3 = 55 + 10 = 15

The minimum cost is 5, achieved by the path 0 - 1. Thus, the answer is 5.


Example 3:




Input: edges = [[0,1,5],[0,2,7],[0,3,9]], values = [1,3,5,9]

Output: -1

Explanation:


	Every path between two distinct nodes has an XOR value with an odd number of set bits.
	Therefore, no Balanced-XOR path exists, so the answer is -1.



 
Constraints:


	2 <= n <= 105
	edges.length == n - 1
	edges[i] = [ui, vi, ci​​​​​​​]
	
		0 <= ui, vi <= n - 1
		1 <= ci <= 109
	
	
	values.length == n
	1 <= values[i] <= 109
	edges represents a valid tree.

