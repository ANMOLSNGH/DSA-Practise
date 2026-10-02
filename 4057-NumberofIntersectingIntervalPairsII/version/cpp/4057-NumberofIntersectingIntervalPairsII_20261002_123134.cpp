// Last updated: 10/2/2026, 12:31:34 PM
1class Solution {
2public:
3    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
4        int n = intervals.size();
5        
6     
7        sort(intervals.begin(), intervals.end());
8  
9   
10        vector<int> start(n);
11        for(int i = 0; i < n; i++) {
12            start[i] = intervals[i][0];
13        }
14        
15        long long cnt = 0; 
16        
17        for(int i = 0; i < n; i++) {
18            int end = intervals[i][1];
19            
20          
21            int indx = upper_bound(start.begin() + i + 1, start.end(), end) - start.begin();
22            
23            cnt += (indx - i - 1); 
24        }
25        
26        return cnt;
27    }
28};