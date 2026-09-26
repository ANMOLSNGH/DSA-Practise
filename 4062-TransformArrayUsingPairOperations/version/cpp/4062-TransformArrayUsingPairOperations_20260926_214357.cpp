// Last updated: 9/26/2026, 9:43:57 PM
1class Solution {
2public:
3    typedef long long ll;
4
5bool canTransform(vector<int>& source, vector<int>& target) {
6    ll sum_src = accumulate(source.begin(), source.end(), 0LL);
7    ll sum_targ = accumulate(target.begin(), target.end(), 0LL);
8
9        return sum_src==sum_targ;
10    }
11};