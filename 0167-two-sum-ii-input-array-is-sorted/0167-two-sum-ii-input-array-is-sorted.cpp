class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int i = 0;
        int j =  n - 1;
        vector<int>ans;
        while(i<j) {
            int sum = nums[i] + nums[j];
            if(sum==target) {
                ans.push_back(i+1);
                ans.push_back(j+1);
                break;
            }
            else if(sum>target) {
                j--;
            }
            else i++;
        }
        return ans;
    }
};