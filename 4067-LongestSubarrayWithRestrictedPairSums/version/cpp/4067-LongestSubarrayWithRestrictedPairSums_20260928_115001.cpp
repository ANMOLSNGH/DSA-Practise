// Last updated: 9/28/2026, 11:50:01 AM
1class Solution {
2public:
3
4    bool check_two_sum(vector<int>&nums,int i,int j){
5        vector<int>f(501,0);
6
7
8        for(int l=i;l<=j;l++){
9            f[nums[l]]++;
10        }
11        
12        for(int l=1;l<=500;l++){
13            if(f[l] <= 0){
14                continue;
15            }
16            for(int k=1;k<=500;k++){
17                if(f[k] <= 0){
18                    continue;
19                }
20                if(l==k) {
21                    if(f[l]>=2&&l+k<=500&&f[l+k]>0)  return true;
22                }
23                else {
24
25                int val = l + k;
26
27                if(val <= 500 && f[val] > 0){return true;}
28                }
29                
30            }
31
32        }
33        return false;
34    }
35
36    
37    int maxSubarray(vector<int>& nums) {
38
39        int n = nums.size();
40    
41        int l = 0;
42        int r = 2;
43        int ans = min(2,n);
44
45        while(r < n){
46            if(check_two_sum(nums,l,r)){
47                l++;
48                r++;
49            }else{
50                ans = max(ans,r-l+1);
51                r++;
52            }
53        }
54
55        return ans;
56        
57    }
58};