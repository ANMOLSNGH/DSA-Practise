class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        unsigned int xori = 0;
        for(auto num : nums) {
            xori ^= num;
        }
        unsigned int right_most1 = (xori)&(-xori);

        int num1 = 0;
        int num2 = 0;
        for(auto num : nums) {
            if ((num & right_most1) != 0) {
                num1 ^= num;
            }
            else num2 ^= num;
        }
        return {num1,num2};
    }
};