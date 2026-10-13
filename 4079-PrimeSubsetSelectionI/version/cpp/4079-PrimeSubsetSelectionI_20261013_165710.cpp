// Last updated: 10/13/2026, 4:57:10 PM
1class Solution {
2public:
3    vector<int> maxPrimes(int n, int s) {
4        vector<bool>primes(n+1,true);
5        vector<int>ans;
6        int sum = 0;
7
8        for(int i = 2;i<=n;i++) {
9            if(primes[i]==true) {
10                sum += i;
11                if(sum<=s) ans.push_back(i);
12                else break;
13                for(long long j = (long long)i*i;j<=n;j += i) {
14                    primes[j] = false;
15                }
16            }
17        }
18        return ans;
19    }
20};