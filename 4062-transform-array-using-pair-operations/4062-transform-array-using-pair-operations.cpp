class Solution {
public:
    typedef long long ll;

bool canTransform(vector<int>& source, vector<int>& target) {
    ll sum_src = accumulate(source.begin(), source.end(), 0LL);
    ll sum_targ = accumulate(target.begin(), target.end(), 0LL);

        return sum_src==sum_targ;
    }
};