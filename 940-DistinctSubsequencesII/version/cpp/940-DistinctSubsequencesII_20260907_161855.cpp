// Last updated: 9/7/2026, 4:18:55 PM
1class Solution {
2public:
3    int distinctSubseqII(string s) {
4        int n = s.size();
5        vector<int> hash(26, 0); 
6        int mod = 1e9 + 7;
7        
8        long long total = 0;
9        
10        for(int i = 0; i < n; i++) {
11            int indx = s[i] - 'a';
12            
13            // 1. Save the total before adding this character
14            long long prev_total = total;
15            
16            // 2. New total = (2 * previous total) + 1 (the char itself) - duplicates
17            total = (2 * prev_total % mod + 1 - hash[indx] + mod) % mod;
18            
19            // 3. The number of subsequences ending in this character is prev_total + 1
20            hash[indx] = (prev_total + 1) % mod; 
21        }
22        
23        return total;
24    }
25};