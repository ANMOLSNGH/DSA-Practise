
    /*Optimised to O(nlogn) using some logical data structure multiset
    multiset to preserve duplicacy
    l to r len is valid including l and r;

    so    l<=j-i<=r
          j-r<=i<=j-l; is valid i is from right - r  to right - l if valid;
          so I will mantain pref sum in valid range only
          start from right = l  and store st.insert(pref[right-l]);
          and erase st.erase(st.find(pref[right-r-1]));
    */
    class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();

        // 1-based prefix sum array makes sliding window math much easier.
        // pref[i] will store the sum of the first 'i' elements.
        vector<int> pref(n + 1, 0);
        for(int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + nums[i];
        }

        multiset<int> st;
        int ans = INT_MAX;

        // j represents the ending length of the prefix we are currently at.
        // We start evaluating when the prefix length is at least 'l'.
        for(int j = l; j <= n; j++) {
            
            // Insert the prefix sum that creates a subarray of length 'l'
            st.insert(pref[j - l]);
            
            // Remove the prefix sum that creates a subarray of length greater than 'r'
            // j - r - 1 is the index that falls out of our valid [l, r] window.
            if(j - r - 1 >= 0) {
                st.erase(st.find(pref[j - r - 1]));
            }
            
            int need = pref[j];
            
            // Find the strictly largest prefix sum in our valid window that is LESS than 'need'.
            // We want (need - *it) > 0, so *it < need.
            auto it = st.lower_bound(need);
            
            if(it != st.begin()) {
                it--; // Move to the greatest element strictly smaller than 'need'
                ans = min(ans, need - *it);
            }
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};