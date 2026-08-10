class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        int ans = 0;
        long long seen = 0; 

        for(int num : nums) {
            if((seen >> num) & 1) {
                ans = ans ^ num;
            } else {
                seen = seen | (1LL << num);
            }
        }
        
        return ans;
    }
};