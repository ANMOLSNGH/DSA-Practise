class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& locked, int k) {
        int ans = 0;
         int n = nums.size();
        for(int i = 0; i < n-1; i++){
            for(int i = 0; i<n-1; i++){
                if(nums[i] > nums[i+ 1]){
                    if(locked[i]){
                        if(k == 0) return -1;
                        locked[i] = 0;
                        k--;
                        ans++;
                    }
                    if(locked[i+1]){
                        if(k == 0) return -1;
                        locked[i+1] = 0;
                        k--;
                        ans++;
                    }
                    swap(nums[i] , nums[i + 1]);
                    ans++;   
                }
            }
        }
        return ans;
    }
};