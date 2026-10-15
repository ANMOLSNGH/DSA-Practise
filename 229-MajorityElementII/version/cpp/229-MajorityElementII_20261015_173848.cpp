// Last updated: 10/15/2026, 5:38:48 PM
1class Solution {
2public:
3    vector<int> majorityElement(vector<int>& nums) {
4        int n = nums.size();
5        int cand1 = 0;
6        int cand2 = 0;
7
8        int cnt1 = 0;
9        int cnt2 = 0;
10        for(int i = 0;i<n;i++) {
11             if(nums[i]==cand1) {
12                cnt1++;
13             }
14             else if(nums[i]==cand2) {
15                cnt2++;
16             }
17
18             else if(cnt1==0) {
19                cand1 = nums[i];
20                cnt1 = 1;
21             }
22             else if(cnt2==0) {
23                cand2 = nums[i];
24                cnt2 = 1;
25             }
26             else {
27                cnt1--;
28                cnt2--;
29             }
30        }
31        
32        cnt1 = 0;
33        cnt2 = 0;
34        for(int i = 0;i<n;i++) {
35            if(nums[i]==cand1) cnt1++;
36            else if(nums[i]==cand2) cnt2++;
37        }
38        vector<int>ans;
39        if(cnt1>n/3) ans.push_back(cand1);
40        if(cnt2>n/3) ans.push_back(cand2);
41        return ans;
42    }
43};