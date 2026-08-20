class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        vector<int>temp;
        int last_seen = nums[0];
        temp.push_back(nums[1]);
        ans.push_back(last_seen);
        for(int i = 2;i<n;i++) {
           if(last_seen>temp.back()) {
            last_seen = nums[i];
           }
           else temp.push_back(nums[i]);

           if(last_seen!=ans.back()) {
              ans.push_back(last_seen);
           }
        }

        for(int i = 0;i<temp.size();i++) {
            ans.push_back(temp[i]);
        }
       
        return ans;
        
    }
};