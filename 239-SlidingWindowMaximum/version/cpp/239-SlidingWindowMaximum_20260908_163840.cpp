// Last updated: 9/8/2026, 4:38:40 PM
1class Solution {
2public:
3    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
4        int n = nums.size();
5        deque<int>dq;
6        int left = 0;
7        vector<int>ans;
8        for(int right = 0;right<n;right++) {
9            if((right-left+1)>k) {
10                left++;
11                if(dq.front()<left) dq.pop_front();
12            }
13            while(!dq.empty()&&nums[dq.back()]<nums[right]) {
14                dq.pop_back();
15            }
16            dq.push_back(right);
17            if((right-left+1)==k) {
18                ans.push_back(nums[dq.front()]);
19            }
20        }
21        return ans;
22    }
23};