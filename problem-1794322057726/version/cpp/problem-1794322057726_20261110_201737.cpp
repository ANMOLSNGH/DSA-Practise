// Last updated: 11/10/2026, 8:17:37 PM
1class Solution {
2public:
3    string convert(string s, int n) {
4        if (n == 1) return s;
5        
6        string ans = "";
7        vector<string> res(n, "");
8        int i = 0;
9        int cnt = 0;
10        
11        while(i < s.size()) {
12            for(int k = 0; k < n && i < s.size(); k++) {
13                if(cnt & 1) {
14                    if((n - k - 1) != 0 && (n - k - 1) != n - 1) {
15                       res[n - k - 1] += s[i];
16                       i++;
17                    }
18                }
19                else {
20                    res[k] += s[i];
21                    i++;
22                }
23            }
24            cnt++;
25        }
26        
27        for(int j = 0; j < n; j++) ans += res[j];
28
29        return ans;
30    }
31};