// Last updated: 9/13/2026, 8:27:11 AM
1class Solution {
2public:
3    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
4
5        for(int i = 0; i < rowShift.size(); i++) {
6            vector<int> temp = grid[i];
7            int k = rowShift[i] % n;
8            
9            for(int j = 0; j < n; j++) {
10                
11                grid[i][(j - k + n) % n] = temp[j];
12            }
13        }
14
15  
16        for(int i = 0; i < colShift.size(); i++) {
17           
18            vector<int> temp(n);
19            for(int j = 0; j < n; j++) {
20                temp[j] = grid[j][i];
21            }
22            
23            int k = colShift[i] % n; 
24            
25            for(int j = 0; j < n; j++) {
26               
27                grid[(j - k + n) % n][i] = temp[j];
28            }
29        }
30        
31        return grid;
32    }
33};