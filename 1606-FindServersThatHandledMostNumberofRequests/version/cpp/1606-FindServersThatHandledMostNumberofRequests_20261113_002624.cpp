// Last updated: 11/13/2026, 12:26:24 AM
1class Solution {
2public:
3    typedef long long ll;
4    using p = pair<ll,int>;
5
6    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
7         priority_queue<p,vector<p>,greater<p>>busy;
8         set<int>free;
9         for(int i = 0;i<k;i++) free.insert(i);
10         vector<int>ans;
11         vector<int>cnt(k,0);
12         for(int i = 0;i<arrival.size();i++) {
13            ll time = arrival[i];
14            while(!busy.empty()&&busy.top().first<=time) {
15                free.insert(busy.top().second);
16                busy.pop();
17            }
18            if(free.empty()) continue;
19            int id = i%k;
20            auto it = free.lower_bound(id);
21            if(it == free.end()) it = free.begin();
22            int val = *it;
23            free.erase(it);
24            cnt[val]++;
25            busy.emplace(time+load[i],val);
26
27         }
28
29         int mx = *max_element(cnt.begin(),cnt.end());
30         for(int i = 0;i<k;i++) {
31            if(cnt[i]==mx) ans.push_back(i);
32         }
33
34         return ans;
35    }
36};