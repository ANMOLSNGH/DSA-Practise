// Last updated: 11/1/2026, 6:34:34 PM
1class Solution {
2public:
3    /*
4    any two odd no. bit xor will always be even 
5    proof let a and b be two value a has odd no. of set bit similarly b also have 
6    odd no. of set bit
7
8    let say k no. of bit are at same posn while we are ready to perform xor
9    now k can be odd or even 
10
11    odd case -> o1 ) from a total odd 1 bit - o1 that got decomposed make it even
12    similarly for b also now remaining bit are now even so we can say it is even
13
14    similarly for even bit also
15
16
17    now if 1-0-1 is there it is also possible so we will store best 0 node ans 
18
19    */
20    using ll = long long;
21    const ll INF = 1e18;
22    using v = vector<ll>;
23    int minActivationCost(vector<vector<int>>& edges, vector<int>& values) {
24        ll ans = INF;
25        int n = values.size();
26        v best(n,INF);
27      
28        for(auto &e : edges) {
29            int u = e[0] , v = e[1];
30            ll w = e[2];
31            int u_bit = __builtin_parity(values[u]);
32            int v_bit = __builtin_parity(values[v]);
33
34            if(u_bit==v_bit) ans = min(ans,w);
35            else {
36                int zero_ = (u_bit==0)?u:v;
37                ans = min(ans,best[zero_] + w);
38                best[zero_] = min(best[zero_],w);
39            }
40        }
41        return ans>=INF ? -1 : ans;
42    }
43};