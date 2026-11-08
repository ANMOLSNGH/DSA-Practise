// Last updated: 11/8/2026, 1:10:34 PM
1class Solution {
2public:
3    long long countValidSubstrings(string s) {
4      int n = s.size();
5
6      vector<int>next_a(n,n);
7      vector<int>next_b(n,n);
8      vector<int>next_c(n,n);
9
10      int prev_a = n;
11      int prev_b = n;
12      int prev_c = n;
13
14      for(int i = n-1;i>=0;i--) {
15        if(s[i]=='a') {
16            prev_a = i;
17        }
18        next_a[i] = prev_a;
19
20        if(s[i]=='b') {
21            prev_b = i;
22        }
23        next_b[i] = prev_b;
24
25        if(s[i]== 'c') prev_c = i;
26
27        next_c[i] = prev_c;
28      }
29      
30
31      long long cnt = 0;
32      for(int i = 0;i<n;i++) {
33          int nxt_a = n;
34          int nxt_b = n;
35          int nxt_c = n;
36
37          if(next_a[i]!=n) {
38             nxt_a = next_a[i];
39          }
40
41          if(nxt_a<n) {
42            if(next_b[nxt_a]!=n) nxt_b = next_b[nxt_a];
43          }
44
45          if(nxt_b<n) {
46            if(next_c[nxt_b]!=n) nxt_c = next_c[nxt_b];
47          }
48          if(nxt_c>=n) cnt += n-i;
49          else cnt += nxt_c - i;
50      }
51      return cnt;      
52   }
53};