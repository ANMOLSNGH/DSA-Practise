// Last updated: 9/2/2026, 7:41:17 PM
1class Solution {
2public:
3    int minSwaps(string s) {
4        int max_imbalance = 0; 
5        int cnt = 0;
6        
7        for(char c : s) {
8            if(c == ']') cnt--;
9            else cnt++;
10            
11          
12            max_imbalance = min(max_imbalance, cnt);
13        }
14        
15       
16        max_imbalance = abs(max_imbalance);
17        
18       
19        return (max_imbalance + 1) / 2; 
20    }
21};