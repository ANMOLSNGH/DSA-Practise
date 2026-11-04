// Last updated: 11/4/2026, 8:20:35 PM
1class Solution {
2public:
3    int scheduleCourse(vector<vector<int>>& courses) {
4        int n = courses.size();
5        sort(courses.begin(),courses.end(),[](vector<int>&a,vector<int>&b){
6            return a[1]<b[1];
7        });
8        int mx = courses[n-1][1];
9        int ans = 0;
10        vector<int>dp(mx+1,-1);
11        dp[0] = 0;
12
13        for(auto &course : courses) {
14            int d = course[0];
15            int deadline = course[1];
16            for(int j = deadline;j>=d;j--) {
17                 if(dp[j-d]!=-1) dp[j] = max(dp[j],dp[j-d]+1);
18
19                 ans = max(dp[j],ans);
20            }
21        }
22        return ans;
23        
24    }
25
26};