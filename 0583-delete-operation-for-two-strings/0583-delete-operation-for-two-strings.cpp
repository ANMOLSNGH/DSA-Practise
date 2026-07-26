class Solution {
public:
    int dp[501][501];
    int n,m;
    int solve(int i , int j,string &word1,string &word2) {
     if(i>=n&&j>=m) return 0;
     if(i>=n) return m-j;
     if(j>=m) return n-i;

     if(dp[i][j]!=-1) return dp[i][j];
     if(word1[i]==word2[j]) {
        return dp[i][j] = solve(i+1,j+1,word1,word2);
     }
     int delete1 = INT_MAX;
     int delete2 = INT_MAX;

     if(i<n)
     delete1 = 1 + solve(i+1,j,word1,word2);
     if(j<m)
     delete2 = 1 + solve(i,j+1,word1,word2);
     return dp[i][j] = min(delete1,delete2);

    }
    int minDistance(string word1, string word2) {
        n = word1.size();
        m = word2.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,word1,word2);
    }
};