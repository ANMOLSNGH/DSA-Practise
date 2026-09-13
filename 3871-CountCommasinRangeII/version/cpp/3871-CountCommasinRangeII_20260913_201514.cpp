// Last updated: 9/13/2026, 8:15:14 PM
1class Solution {
2public:
3   long long case1 = 1e3;
4    long long case2 = 1e6;
5    long long case3 = 1e9;
6    long long case4 = 1e12;
7    long long case5 = 1e15;
8    long long countCommas(long long n) {
9        if(n<case1) return 0;
10        long long cnt = 0;
11        if(n>=case1&&n<case2) cnt += n-case1+1;
12        if(n>=case2&&n<case3) {
13              cnt += (case2-case1)*1 + (n-case2+1)*2;
14        }
15        if(n>=case3&&n<case4) {
16            cnt += (case2-case1) + (case3-case2)*2 + (n-case3+1)*3;
17        }
18        if(n>=case4&&n<case5) {
19            cnt += (case2-case1) + (case3-case2)*2 + (case4-case3)*3 + (n-case4+1)*4;
20        }
21         if(n>=case5) {
22            cnt += (case2-case1) + (case3-case2)*2 + (case4-case3)*3 + (case5-case4)*4+(n-case5+1)*5;
23        }
24        return cnt;
25    }
26};