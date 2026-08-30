class Solution {
public:
    typedef long long ll;
    ll mod = 1e9+7;
    ll exponent(ll x,ll y,ll mod) {
        ll res = 1;
        while(y) {
            if(y&1) {
                res = res*x;
                res = res%mod;
            }

            x *= x;
            x = x%mod;
            y >>= 1;
        }
        return res%mod;
    }
    int countWays(vector<vector<int>>& ranges) {
        int grps = 0;
        int n = ranges.size();
        sort(ranges.begin(),ranges.end());
        int first = ranges[0][0];
        int last = ranges[0][1];
        for(int i = 1;i<n;i++) {
            if(ranges[i][0]<=last) {
                last = max(last,ranges[i][1]);
            }
            else {
                grps++;
                first = ranges[i][0];
                last = ranges[i][1];
            }
        }
        grps++;
        ll ans = exponent(2,grps,mod);
        return ans;
    }
};