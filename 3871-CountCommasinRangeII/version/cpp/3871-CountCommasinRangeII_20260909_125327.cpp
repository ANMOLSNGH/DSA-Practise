// Last updated: 9/9/2026, 12:53:27 PM
1class Solution {
2public:
3    long long countCommas(long long n) {
4        long long commas = 0;
5        long long base = 1000;
6        
7        // As long as n is greater than or equal to the current base (1e3, 1e6, 1e9...)
8        while (n >= base) {
9            commas += (n - base + 1); // Add a comma for every number >= base
10            
11            // Prevent long long overflow if n is exceptionally large
12            if (base > LLONG_MAX / 1000) break;
13            
14            base *= 1000; 
15        }
16        
17        return commas;
18    }
19};