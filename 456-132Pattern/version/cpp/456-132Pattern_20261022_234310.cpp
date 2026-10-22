// Last updated: 10/22/2026, 11:43:10 PM
1class Solution {
2public:
3    bool find132pattern(vector<int>& nums) {
4        int n = nums.size();
5        if(n<3) return false;
6
7        stack<int>st;
8        int third = INT_MIN;
9
10        for(int i = n-1;i>=0;i--) {
11            if(third>nums[i]) return true;
12
13            while(!st.empty()&&st.top()<nums[i]) {
14                third = st.top();
15                st.pop();
16            }
17            st.push(nums[i]);
18        }
19        return false;
20    }
21};