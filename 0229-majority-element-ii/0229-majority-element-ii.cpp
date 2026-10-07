class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        int n = nums.size();

        int candi1 = 0;
        int candi2 = 0;

        int count_1 = 0;
        int count_2 = 0;

        // Phase 1: Find potential candidates
        for(int i = 0; i < n; i++) {

            if(nums[i] == candi1) {
                count_1++;
            }
            else if(nums[i] == candi2) {
                count_2++;
            }
            else if(count_1 == 0) {
                candi1 = nums[i];
                count_1 = 1;
            }
            else if(count_2 == 0) {
                candi2 = nums[i];
                count_2 = 1;
            }
            else {
                count_1--;
                count_2--;
            }
        }

        // Phase 2: Verify actual frequencies
        count_1 = 0;
        count_2 = 0;

        for(int x : nums) {
            if(x == candi1)
                count_1++;
            else if(x == candi2)
                count_2++;
        }

        vector<int> ans;

        if(count_1 > n/3)
            ans.push_back(candi1);

        if(count_2 > n/3)
            ans.push_back(candi2);

        return ans;
    }
};