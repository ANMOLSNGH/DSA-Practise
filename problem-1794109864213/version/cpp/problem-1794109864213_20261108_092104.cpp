// Last updated: 11/8/2026, 9:21:04 AM
1class Solution {
2public:
3    int countSuffix(vector<int>& nums, vector<int>& target) {
4        int n = nums.size();
5        int indx_ = 0;
6        for(int i = n-1;i>=1;i--) {
7            if(target[i]>target[i-1]) {
8                indx_  = i;
9                break;
10            }
11        }
12        int cnt = 0;
13
14        for(int i = 0;i<n;i++) {
15            if(nums[i]!=target[i]&&indx_>i) return cnt;
16            else if(nums[i]!=target[i]) {
17                sort(nums.begin()+i,nums.end(),greater<int>());
18                if(nums==target) {
19                    cnt++;
20                    return cnt;
21                }
22                return 0;
23            }
24            else if(nums[i]==target[i]) {
25                if(indx_<=i) cnt++;
26            }
27        }
28        return cnt;
29    } 
30};