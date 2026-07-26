class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        long long ans = 0;
        while(i<n-2) {
            int j = i;
            int diff = 0;
            if(j+1<n) diff = nums[j+1]-nums[j];
            while(j+1<n&&nums[j+1]-nums[j]==diff) {
                j++;
            }
            ans += (j-i-1)*(j-i)/2;
            i = j;
        }
        return ans;
    }
};