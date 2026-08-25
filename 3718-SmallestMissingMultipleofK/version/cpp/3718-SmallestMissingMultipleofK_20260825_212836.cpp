// Last updated: 8/25/2026, 9:28:36 PM
1class Solution {
2public:
3    int missingMultiple(vector<int>& nums, int k) {
4            int n = nums.size();
5            sort(nums.begin(),nums.end());
6            bool found = false;
7            int indx = 0;
8            for(int i = 0;i<n;i++) {
9                if(nums[i]==k) {
10                    indx = i;
11                    found = true;
12                    break;
13                }
14            }
15            if(found==false) return k;
16            int j = 2; 
17            for(int i = indx;i<nums.size();i++) {
18                 if(nums[i]==j*k) j++;
19            }
20            return j*k;
21    }
22};