class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        int start = intervals[0][0];
        int last = intervals[0][1];
        vector<vector<int>>ans;
        for(int i = 1;i<n;i++) {
            if(intervals[i][0]<=last) {
                  last = max(last,intervals[i][1]);
            }

            else {
                ans.push_back({start,last});
                start = intervals[i][0];
                last = intervals[i][1];
            }
        }
        ans.push_back({start,last});

        return ans;
    }
};