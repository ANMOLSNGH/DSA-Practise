class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        vector<int>cnt(101,0);
        for(int i = 0;i<n;i++) cnt[nums[i]]++;
        

        while(ans.size()!=n) {
           for(int i = 0;i<cnt.size();i++) {
             if(cnt[i]==0) continue;
             ans.push_back(i);
             cnt[i]--;
           }
        }
        return ans;

    }
};