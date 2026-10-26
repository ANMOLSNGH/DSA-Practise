// Last updated: 10/26/2026, 11:53:37 PM
1class Solution {
2public:
3    int maxScoreSightseeingPair(vector<int>& values) {
4        int res = 0;
5        int maxSoFar = values[0] + 0;
6
7        for(int i = 1;i<values.size();i++) {
8            maxSoFar = max(maxSoFar,values[i-1] + i - 1);
9            res = max(res,values[i] - i + maxSoFar);
10        }
11        return res;
12    }
13};