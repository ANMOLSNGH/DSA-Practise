// Last updated: 11/21/2026, 12:14:48 AM
1class Solution {
2public:
3    vector<vector<int>> dp;
4    int n;
5
6    int findMethod(vector<int>& nums, int start, int target) {
7        int j = lower_bound(nums.begin() + start, nums.end(), target) - nums.begin();
8        if (j < n && nums[j] == target)
9            return j;
10
11        return -1;
12    }
13
14    int maxSelectedElements(vector<int>& nums) {
15        sort(nums.begin(), nums.end());
16        n = nums.size();
17        dp.assign(n + 1, vector<int>(2, 0));
18
19        int result = 1;
20
21
22        for (int i = n - 1; i >= 0; i--) { //O(n * log(n))
23            for (int inc = 0; inc <= 1; inc++) {
24
25                int currVal = nums[i] + inc;
26                int len = 1;
27
28                //1st Option = find (currVal+1)
29                int j = findMethod(nums, i + 1, currVal + 1);
30                if (j != -1) {
31                    len = max(len, 1 + dp[j][0]);
32                }
33
34                //2nd Option = find (currVal) and then inc by +1
35                j = findMethod(nums, i + 1, currVal);
36                if (j != -1) {
37                    len = max(len, 1 + dp[j][1]);
38                }
39
40                dp[i][inc] = len;
41                result = max(result, len);
42            }
43        }
44
45        return result;
46    }
47};