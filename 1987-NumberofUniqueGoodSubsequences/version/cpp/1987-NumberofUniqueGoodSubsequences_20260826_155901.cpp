// Last updated: 8/26/2026, 3:59:01 PM
1class Solution {
2public:
3    int numberOfUniqueGoodSubsequences(string binary) {
4        int n = binary.size();
5        int i = 0;
6        while(i<n&&binary[i]!='1') i++;
7        if(i==n) return 1;
8
9        long long mod = 1e9 + 7;
10        vector<long long> dp(n, 0);
11        dp[i] = 1;
12        int lastZero = 0, lastOne = 0;
13        for(int indx = i+1;indx<n;indx++) {
14            int j = binary[indx]=='0'?lastZero:lastOne;
15            long long dup = (j>0)?dp[j-1]:0;
16
17            dp[indx] = (2*dp[indx-1]%mod - dup + mod)%mod;
18            if (binary[indx] == '0') {
19                lastZero = indx;
20            } else {
21                lastOne = indx;
22            }
23        }
24
25        int hasZero = 0;
26        if (binary.find('0') != string::npos) {
27            hasZero = 1;
28        }
29
30        return (dp[n-1]+hasZero)%mod;
31    }
32};