// Last updated: 9/9/2026, 8:09:30 PM
1class Solution {
2public:
3    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
4        vector<pair<double,int>>record;
5        int n = points.size();
6        for(int  i = 0;i<n;i++) {
7            double distance = sqrt(points[i][0]*points[i][0]+points[i][1]*points[i][1]);
8            record.push_back({distance,i});
9        }
10        vector<vector<int>>ans;
11        sort(record.begin(),record.end());
12        for(int i = 0;i<k;i++) ans.push_back(points[record[i].second]);
13        return ans;
14    }
15};