// Last updated: 10/27/2026, 12:34:12 AM
1class Solution {
2public:  
3 /*
4 we had to just take increasing slope throughout points 
5 */
6    int maxProfit(vector<int>& nums) {
7        int n = nums.size();
8
9        int profit = 0;
10        for(int i = 0;i<n-1;i++) {
11            if(nums[i+1]>nums[i]) {
12                profit +=  nums[i+1] - nums[i];
13            }
14        }
15        return profit;
16    }
17};