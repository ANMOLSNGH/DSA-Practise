// Last updated: 11/10/2026, 10:17:13 PM
1class Solution {
2public:
3    typedef long long ll;
4    long long countCompleteDayPairs(vector<int>& hours) {
5        unordered_map<ll,ll>mpp;
6        ll cnt = 0;
7        for(int i = 0;i<hours.size();i++) {
8            int rem = (24 - hours[i]%24)%24;
9            if(mpp.find(rem)!=mpp.end()) cnt += mpp[rem];
10            mpp[hours[i]%24]++;
11        }
12        return cnt;
13    }
14};