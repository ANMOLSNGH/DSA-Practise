// Last updated: 10/4/2026, 10:36:33 PM
1class Solution {
2public:
3  typedef long long ll;
4    long long maxAlternatingSum(vector<int>& nums) {
5        ll neg = LLONG_MIN/4;
6        ll end = neg;
7        ll ond = neg;
8        ll ed = neg;
9        ll od = neg;
10        ll ans = neg;
11
12        for(ll x:nums) {
13            ll n_end = max(ond+x,x);
14            ll n_ond = end-x;
15            ll n_ed = max(end,od+x);
16            ll n_od = max(ond,ed-x);
17
18            ans = max(ans,max({n_end,n_ond,n_ed,n_od}));
19
20            end = n_end;
21            ond = n_ond;
22            ed = n_ed;
23            od = n_od;
24        }
25        return ans;
26    }
27};