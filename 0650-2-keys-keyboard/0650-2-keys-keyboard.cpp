class Solution {
public:
    int dp[1001][1001];
    int solve(int n,int current,int clip) {
       if(current==n) return 0;
       if(current>n) return 10001;
       if(dp[current][clip]!=-1) return dp[current][clip];

       int paste = 10000;
       if(clip>0) {
          paste  = 1 + solve(n,current+clip,clip);
       }
       int copy = 10000;
       if(current!=clip) {
        copy = 1 + solve(n,current,current);
       }
       return dp[current][clip] = min(paste,copy);
    }
    int minSteps(int n) {
        if(n==1) return 0;
        memset(dp,-1,sizeof(dp));
        return 1+solve(n,1,1);
    }
};