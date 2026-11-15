// Last updated: 11/15/2026, 9:14:48 PM
1class Solution {
2public:
3    int numOfSubarrays(vector<int>& arr) {
4        int n = arr.size();
5        vector<int> odd_indx;
6        for(int i = 0; i < n; i++) {
7            if(arr[i] & 1) odd_indx.push_back(i);
8        }
9        
10        if (odd_indx.empty()) return 0;
11        
12        int m = odd_indx.size();
13        vector<long long> dp(m, 0);
14        dp[0] = odd_indx[0] + 1;
15        
16        long long ans = dp[0] * ((1 < m) ? (odd_indx[1] - odd_indx[0]) : (n - odd_indx[0]));
17        
18        for(int i = 1; i < m; i++) {
19            dp[i] += odd_indx[i] - odd_indx[i-1];
20            dp[i] += (i - 2 >= 0 ? dp[i-2] : 0);
21            long long ends = (i + 1 < m) ? (odd_indx[i+1] - odd_indx[i]) : (n - odd_indx[i]);
22            ans = (ans + dp[i] * ends) % 1000000007;
23        }
24        
25        return ans;
26    }
27};