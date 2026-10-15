class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        int cand = 0;
        for(auto num:nums) {
            if(cnt==0) {
                cand = num;
                cnt++;
            }
            else if(cand==num) cnt++;
            else cnt--;
        }
        return cand;
    }
};