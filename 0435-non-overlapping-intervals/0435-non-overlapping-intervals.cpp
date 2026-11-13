class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),[](
            vector<int>&v1,vector<int>&v2) {
                return v1[1]<v2[1];
            });
        int i = 0; 
        int count = 0;
        while(i<n-1) {
            int j = i+1;
            if(intervals[i][1]<=intervals[j][0]) {
                i++;
            }
            else {
                while(j<n&&intervals[i][1]>intervals[j][0]) {
                    j++;
                    count++;
                }
                i = j;
            }
        }
        return count;
    }
};