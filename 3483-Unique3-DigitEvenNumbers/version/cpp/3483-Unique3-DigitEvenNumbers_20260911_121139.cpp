// Last updated: 9/11/2026, 12:11:39 PM
1class Solution {
2public:
3    int totalNumbers(auto& digits) {
4        int f[10] = {0};
5        int res = 0;
6
7        for (auto& d : digits)
8            f[d]++;
9
10        for (int i = 1; i < 10; i++) 
11            for (int j = 0; j < 10; j++) 
12                for (int k = 0; k < 9; k += 2) 
13                    res += f[i] > 0 &&
14                           f[j] > (i == j) &&
15                           f[k] > (i == k) + (j == k);
16        
17
18        return res;
19    }
20};