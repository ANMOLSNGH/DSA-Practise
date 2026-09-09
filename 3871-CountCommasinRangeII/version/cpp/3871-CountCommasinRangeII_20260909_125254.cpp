// Last updated: 9/9/2026, 12:52:54 PM
1class Solution {
2public:
3// 4-6 -> 1 total 1000 to 999999
4// 7-9 -> 2   1000000 to 999999999
5// 10-12 -> 3 10000000000 to 999999999999
6// 13-15-> 4  1000000000000 to 999999999999999
7    long long case1 = 1e3;
8    long long case2 = 1e6;
9    long long case3 = 1e9;
10    long long case4 = 1e12;
11    long long case5 = 1e15;
12    long long countCommas(long long n) {
13        if(n<case1) return 0;
14        long long cnt = 0;
15        if(n>=case1&&n<case2) cnt += n-case1+1;
16        if(n>=case2&&n<case3) {
17              cnt += (case2-case1)*1 + (n-case2+1)*2;
18        }
19        if(n>=case3&&n<case4) {
20            cnt += (case2-case1) + (case3-case2)*2 + (n-case3+1)*3;
21        }
22        if(n>=case4&&n<case5) {
23            cnt += (case2-case1) + (case3-case2)*2 + (case4-case3)*3 + (n-case4+1)*4;
24        }
25         if(n>=case5) {
26            cnt += (case2-case1) + (case3-case2)*2 + (case4-case3)*3 + (n-case4+1)*4+1;
27        }
28        return cnt;
29    }
30};