class Solution {
public:
    int dp[1001][1001];
    int n,m;
    int solve(int i,int j,string &s1,string &s2) {
        if(i>=n&&j<m) {
             int sum = 0;
             for(int ind = j;ind<m;ind++) sum += s2[ind];
             return sum;
        }

        if(j>=m&&i<n) {
             int sum = 0;
             for(int ind = i;ind<n;ind++) sum += s1[ind];
             return sum;
        }
        if(i>=n&&j>=m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]) {
            return dp[i][j] = solve(i+1,j+1,s1,s2);
        }
        int poss1 = INT_MAX;
        int poss2 = INT_MAX;
        if(s1[i]!=s2[j]) {
           poss1 = s2[j] + solve(i,j+1,s1,s2); 
           poss2 = s1[i] + solve(i+1,j,s1,s2);
        }
        return dp[i][j] = min(poss1,poss2);
    }
    int minimumDeleteSum(string s1, string s2) {
        n = s1.size();
        m = s2.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,s1,s2);
    }
};