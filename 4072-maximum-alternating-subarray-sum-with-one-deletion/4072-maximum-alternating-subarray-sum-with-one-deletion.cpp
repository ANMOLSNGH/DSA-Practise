class Solution {
public:
  typedef long long ll;
    long long maxAlternatingSum(vector<int>& nums) {
        ll neg = LLONG_MIN/4;
        ll end = neg;
        ll ond = neg;
        ll ed = neg;
        ll od = neg;
        ll ans = neg;

        for(ll x:nums) {
            ll n_end = max(ond+x,x);
            ll n_ond = end-x;
            ll n_ed = max(end,od+x);
            ll n_od = max(ond,ed-x);

            ans = max(ans,max({n_end,n_ond,n_ed,n_od}));

            end = n_end;
            ond = n_ond;
            ed = n_ed;
            od = n_od;
        }
        return ans;
    }
};