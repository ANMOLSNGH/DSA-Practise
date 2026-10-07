// Last updated: 10/7/2026, 1:38:48 PM
1class Solution {
2public:
3    vector<int> majorityElement(vector<int>& nums) {
4
5        int n = nums.size();
6
7        int candi1 = 0;
8        int candi2 = 0;
9
10        int count_1 = 0;
11        int count_2 = 0;
12
13        // Phase 1: Find potential candidates
14        for(int i = 0; i < n; i++) {
15
16            if(nums[i] == candi1) {
17                count_1++;
18            }
19            else if(nums[i] == candi2) {
20                count_2++;
21            }
22            else if(count_1 == 0) {
23                candi1 = nums[i];
24                count_1 = 1;
25            }
26            else if(count_2 == 0) {
27                candi2 = nums[i];
28                count_2 = 1;
29            }
30            else {
31                count_1--;
32                count_2--;
33            }
34        }
35
36        // Phase 2: Verify actual frequencies
37        count_1 = 0;
38        count_2 = 0;
39
40        for(int x : nums) {
41            if(x == candi1)
42                count_1++;
43            else if(x == candi2)
44                count_2++;
45        }
46
47        vector<int> ans;
48
49        if(count_1 > n/3)
50            ans.push_back(candi1);
51
52        if(count_2 > n/3)
53            ans.push_back(candi2);
54
55        return ans;
56    }
57};