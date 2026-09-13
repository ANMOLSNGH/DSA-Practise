class Solution {
public:
    long long shadowPairs(vector<int>& nums) {
        int n = nums.size();
        vector<int>nse(n);
        stack<int>st;
        for(int i = n-1;i>=0;i--) {
            while(!st.empty()&&nums[st.top()]>=nums[i]) {
                st.pop();
            }
            nse[i] = st.empty()?n:st.top();
            st.push(i);
        }
        long long count = 0;
        unordered_map<int,int>mpp;
        vector<int>cnt(n,0);
        for(int i = n-1;i>=0;i--) {
           int next_indx = -1;
           if(mpp.count(nums[i])) {
                  next_indx = mpp[nums[i]];
                  if(next_indx<nse[i])
                  cnt[i] = 1+cnt[next_indx];
           }
           mpp[nums[i]] = i;
           count += (nse[i]-i-1)-cnt[i];
        }
        return count;
    }
};