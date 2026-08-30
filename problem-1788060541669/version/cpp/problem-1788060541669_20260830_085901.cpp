// Last updated: 8/30/2026, 8:59:01 AM
1class Solution {
2public:
3    #define ll long long
4    ll mod = 1e9+7;
5    ll exponent(ll x,ll y, ll mod) {
6        ll res = 1;
7        while(y>0) {
8            if(y&1) {
9                res = (res*x)%mod;
10                res = res%mod;
11            }
12            x *= x;
13            x = x%mod;
14            y >>= 1;
15        }
16        return res%mod;
17    }
18    int sumDecoded(vector<long long>& nums) {
19        ll sum = 0;
20
21        for(auto num : nums)  {
22            int width = num%10;
23            ll d = num/10;
24            int total_digi = 0;
25            ll temp = d;
26            while(temp)  {
27                total_digi++;
28                temp /= 10;
29            }
30            ll power = 1;
31            int y_digits = total_digi - width;
32            for(int i = 0; i < y_digits; i++) {
33                power *= 10;
34            }
35            ll xi = d / power;
36            ll yi = d % power;
37            sum = (sum + exponent(xi, yi, mod)) % mod;
38        }
39        return sum;
40    }
41};