// Last updated: 9/6/2026, 3:42:03 PM
1class Solution {
2public:
3    int largestVariance(string s) {
4        int n = s.size();
5        vector<int>cnt(26,0);
6        for(auto c:s) cnt[c-'a']++;
7        int result  = 0;
8        for(char ch = 'a';ch<='z';ch++) {
9            for(char ch_s = 'a';ch_s<='z';ch_s++) {
10                if(cnt[ch-'a']==0||cnt[ch_s-'a']==0) continue;
11                int firstcnt = 0;
12                int secondcnt = 0;
13                bool hasseenpast = false;
14                for(auto alpha : s) {
15                    if(alpha==ch) firstcnt++;
16                    if(alpha==ch_s) secondcnt++;
17
18                    if(secondcnt>0) {
19                        result = max(result,firstcnt-secondcnt);
20                    }
21                    else {
22                        if(hasseenpast) {
23                            result = max(result,firstcnt-1);
24                        }
25                    }
26
27                    if(secondcnt>firstcnt) {
28                        firstcnt = 0;
29                        secondcnt = 0;
30                        hasseenpast = true;
31                    }
32                }
33            }
34        }
35        return result;
36    }
37};