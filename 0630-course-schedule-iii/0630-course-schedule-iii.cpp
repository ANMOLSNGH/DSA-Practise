class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size();
        sort(courses.begin(),courses.end(),[](vector<int>&a,vector<int>&b){
            return a[1]<b[1];
        });
        int mx = courses[n-1][1];
        int ans = 0;
        vector<int>dp(mx+1,-1);
        dp[0] = 0;

        for(auto &course : courses) {
            int d = course[0];
            int deadline = course[1];
            for(int j = deadline;j>=d;j--) {
                 if(dp[j-d]!=-1) dp[j] = max(dp[j],dp[j-d]+1);

                 ans = max(dp[j],ans);
            }
        }
        return ans;
        
    }

};