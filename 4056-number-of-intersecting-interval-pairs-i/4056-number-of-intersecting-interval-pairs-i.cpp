class Solution {
public:
    int  countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int>start(n);
        for(int i = 0;i<n;i++) start[i] = intervals[i][0];

        sort(start.begin(),start.end());
        sort(intervals.begin(),intervals.end());
        
        long long j = 0;
        long long cnt = 0;
        for(int i = 0;i<n;i++) {
           int end = intervals[i][1];
           int indx = upper_bound(start.begin()+j+1,start.end(),end)-start.begin();
           cnt += indx-j-1;

           j++;
        }
        return cnt;
    }
};