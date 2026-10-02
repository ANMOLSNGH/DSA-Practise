// Last updated: 10/2/2026, 12:32:36 PM
1class Solution {
2public:
3    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
4        int n = intervals.size();
5        vector<int>start(n);
6        for(int i = 0;i<n;i++) start[i] = intervals[i][0];
7
8        sort(start.begin(),start.end());
9        sort(intervals.begin(),intervals.end());
10        
11        long long j = 0;
12        long long cnt = 0;
13        for(int i = 0;i<n;i++) {
14           int end = intervals[i][1];
15           int indx = upper_bound(start.begin()+j+1,start.end(),end)-start.begin();
16           cnt += indx-j-1;
17
18           j++;
19        }
20        return cnt;
21    }
22};