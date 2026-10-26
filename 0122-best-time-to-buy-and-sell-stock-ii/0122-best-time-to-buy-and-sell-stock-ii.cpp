class Solution {
public:  
 /*
 we had to just take increasing slope throughout points 
 */
    int maxProfit(vector<int>& nums) {
        int n = nums.size();

        int profit = 0;
        for(int i = 0;i<n-1;i++) {
            if(nums[i+1]>nums[i]) {
                profit +=  nums[i+1] - nums[i];
            }
        }
        return profit;
    }
};