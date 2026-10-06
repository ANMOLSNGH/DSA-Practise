// Last updated: 10/6/2026, 2:34:38 PM
1class Solution {
2public:
3    int countPrimes(int n) {
4        int cnt = 0;
5        vector<bool>prime(n,true);
6        for(int i = 2;i<n;i++) {
7            if(prime[i]) cnt++;
8            for(int j = 2*i;j<n;j+= i) {
9                prime[j] = false;
10            }
11        }
12        return cnt;
13    }
14};