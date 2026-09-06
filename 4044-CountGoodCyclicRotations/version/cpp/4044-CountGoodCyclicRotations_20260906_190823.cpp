// Last updated: 9/6/2026, 7:08:23 PM
1class Solution {
2public:
3    typedef long long ll;
4    int countGoodRotations(vector<int>& nums) {
5        int n = nums.size();
6        ll  total_sum = accumulate(nums.begin(),nums.end(),0ll);
7        int i = 0;
8        int j = n/2-1;
9        ll sum = 0;
10        ll cnt = 0;
11        if(n==2&&nums[0]!=nums[1]) return 1;
12        for(;i<=j;i++) sum += nums[i];
13        if(sum>(total_sum-sum)) cnt++;
14        i=0;
15        j++;
16        while(j<n) {
17            sum += nums[j];
18            sum -= nums[i];
19            if(sum>(total_sum-sum)) cnt++;
20            i++;
21            j++;
22        }
23        sum -= nums[i++];
24        j = i;
25        sum += nums[0];
26        i = 0;
27        if(sum>total_sum-sum) cnt++;
28        i++;
29        while(i<n/2-1) {
30            sum += nums[i++];
31            sum -= nums[j++];
32            if(sum>total_sum-sum) cnt++;
33        }
34         return cnt;
35    }
36};