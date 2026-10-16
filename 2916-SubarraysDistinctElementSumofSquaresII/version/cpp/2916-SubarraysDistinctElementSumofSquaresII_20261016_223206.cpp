// Last updated: 10/16/2026, 10:32:06 PM
1class Solution {
2public:
3    typedef long long ll;
4    ll mod = 1e9 + 7;
5
6    vector<ll> lazySegt;
7    vector<ll> sumSegt;
8    vector<ll> squareSegt;
9
10    void lazyAddition(int i, int l, int r, ll val) {
11        ll len = r - l + 1;
12        val %= mod;
13        
14        ll term1 = (2 * val % mod) * sumSegt[i] % mod;
15        ll term2 = (len * (val * val % mod)) % mod;
16        squareSegt[i] = (squareSegt[i] + term1 + term2) % mod;
17        
18        sumSegt[i] = (sumSegt[i] + val * len) % mod;
19    }
20
21    void updateRange(int start, int end, int i, int l, int r, ll val) {
22        if (lazySegt[i] != 0) {
23            lazyAddition(i, l, r, lazySegt[i]);
24            if (l != r) {
25                lazySegt[2 * i + 1] = (lazySegt[2 * i + 1] + lazySegt[i]) % mod;
26                lazySegt[2 * i + 2] = (lazySegt[2 * i + 2] + lazySegt[i]) % mod;
27            }
28            lazySegt[i] = 0;
29        }
30
31        if (start > r || end < l) return;
32
33        if (l >= start && r <= end) {
34            lazyAddition(i, l, r, val);
35            if (l != r) {
36                lazySegt[2 * i + 1] = (lazySegt[2 * i + 1] + val) % mod;
37                lazySegt[2 * i + 2] = (lazySegt[2 * i + 2] + val) % mod;
38            }
39            return;
40        }
41
42        int mid = l + (r - l) / 2;
43        updateRange(start, end, 2 * i + 1, l, mid, val);
44        updateRange(start, end, 2 * i + 2, mid + 1, r, val);
45
46        sumSegt[i] = (sumSegt[2 * i + 1] + sumSegt[2 * i + 2]) % mod;
47        squareSegt[i] = (squareSegt[2 * i + 1] + squareSegt[2 * i + 2]) % mod;
48    }
49
50    int sumCounts(vector<int>& nums) {
51        int n = nums.size();
52
53        lazySegt.assign(4 * n, 0);
54        sumSegt.assign(4 * n, 0);
55        squareSegt.assign(4 * n, 0);
56
57        vector<int> lastSeenindx(100001, -1);
58        ll res = 0;
59
60        for (int i = 0; i < n; i++) {
61            int start = lastSeenindx[nums[i]] + 1;
62            int end = i;
63
64            updateRange(start, end, 0, 0, n - 1, 1);
65            res = (res + squareSegt[0]) % mod;
66
67            lastSeenindx[nums[i]] = i;
68        }
69
70        return res;
71    }
72};
73