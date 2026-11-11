// Last updated: 11/11/2026, 8:36:54 PM
1class Solution {
2public:
3    typedef long long ll;
4    long long appealSum(string s) {
5        
6        vector<pair<ll,int>> count(26, {0, -1});
7        ll cnt = 0;
8        for(int i = 0; i < s.size(); i++) {
9             cnt += (ll)(i+1)*(i+2)/2;
10             
11             for(int j = 0; j < 26; j++) {
12                 if((s[i]-'a') == j) {
13                     cnt -= count[j].first;
14                 } else {
15                    cnt -= count[j].first;
16                    cnt += count[j].second + 1;
17                 }
18             }
19
20             count[s[i]-'a'].first += i+1;
21             count[s[i]-'a'].second = i;
22        }
23        return cnt;
24    }
25};