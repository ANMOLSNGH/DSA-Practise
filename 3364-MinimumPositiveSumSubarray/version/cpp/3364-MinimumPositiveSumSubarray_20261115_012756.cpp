// Last updated: 11/15/2026, 1:27:56 AM
1
2    /*Optimised to O(nlogn) using some logical data structure multiset
3    multiset to preserve duplicacy
4    l to r len is valid including l and r;
5
6    so    l<=j-i<=r
7          j-r<=i<=j-l; is valid i is from right - r  to right - l if valid;
8          so I will mantain pref sum in valid range only
9          start from right = l  and store st.insert(pref[right-l]);
10          and erase st.erase(st.find(pref[right-r-1]));
11    */
12    class Solution {
13public:
14    int minimumSumSubarray(vector<int>& nums, int l, int r) {
15        int n = nums.size();
16
17        // 1-based prefix sum array makes sliding window math much easier.
18        // pref[i] will store the sum of the first 'i' elements.
19        vector<int> pref(n + 1, 0);
20        for(int i = 0; i < n; i++) {
21            pref[i + 1] = pref[i] + nums[i];
22        }
23
24        multiset<int> st;
25        int ans = INT_MAX;
26
27        // j represents the ending length of the prefix we are currently at.
28        // We start evaluating when the prefix length is at least 'l'.
29        for(int j = l; j <= n; j++) {
30            
31            // Insert the prefix sum that creates a subarray of length 'l'
32            st.insert(pref[j - l]);
33            
34            // Remove the prefix sum that creates a subarray of length greater than 'r'
35            // j - r - 1 is the index that falls out of our valid [l, r] window.
36            if(j - r - 1 >= 0) {
37                st.erase(st.find(pref[j - r - 1]));
38            }
39            
40            int need = pref[j];
41            
42            // Find the strictly largest prefix sum in our valid window that is LESS than 'need'.
43            // We want (need - *it) > 0, so *it < need.
44            auto it = st.lower_bound(need);
45            
46            if(it != st.begin()) {
47                it--; // Move to the greatest element strictly smaller than 'need'
48                ans = min(ans, need - *it);
49            }
50        }
51        
52        return ans == INT_MAX ? -1 : ans;
53    }
54};