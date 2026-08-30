// Last updated: 8/31/2026, 12:05:48 AM
1class Solution {
2public:
3    typedef long long ll;
4    ll mod = 1e9+7;
5    ll exponent(ll x,ll y,ll mod) {
6        ll res = 1;
7        while(y) {
8            if(y&1) {
9                res = res*x;
10                res = res%mod;
11            }
12
13            x *= x;
14            x = x%mod;
15            y >>= 1;
16        }
17        return res%mod;
18    }
19    int countWays(vector<vector<int>>& ranges) {
20        int grps = 0;
21        int n = ranges.size();
22        sort(ranges.begin(),ranges.end());
23        int first = ranges[0][0];
24        int last = ranges[0][1];
25        for(int i = 1;i<n;i++) {
26            if(ranges[i][0]<=last) {
27                last = max(last,ranges[i][1]);
28            }
29            else {
30                grps++;
31                first = ranges[i][0];
32                last = ranges[i][1];
33            }
34        }
35        grps++;
36        ll ans = exponent(2,grps,mod);
37        return ans;
38    }
39};