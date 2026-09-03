class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0];
        int possi = 0;
        for(auto num : nums) {
            if(possi==0) candidate = num; 
            if(candidate==num) possi++;
            else possi--;
                
        }
        return candidate;
    }
};