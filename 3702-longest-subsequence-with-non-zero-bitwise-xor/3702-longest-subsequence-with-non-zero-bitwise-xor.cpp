class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int totalxor = 0;
        bool allzero = true;

        for(auto num : nums) {
            totalxor ^= num;
            if(num!=0) allzero = false;
        }
        if(totalxor>0) return n;

        int ans = allzero?0:n-1;
        return ans;
    }
};