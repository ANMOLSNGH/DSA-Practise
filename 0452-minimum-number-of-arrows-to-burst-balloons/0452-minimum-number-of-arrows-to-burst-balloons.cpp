class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& intervals) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        
        int n = intervals.size();
        if (n == 0) return 0;
        
        sort(intervals.begin(), intervals.end(), [](const vector<int>& v1, const vector<int>& v2) {
            return v1[1] < v2[1];
        });
        
        int i = 0;
        int count = 1;
        
        for (int j = 1; j < n; j++) {
            if (intervals[i][1] < intervals[j][0]) {
                count++;
                i = j;
            }
        }
        
        return count;
    }
};