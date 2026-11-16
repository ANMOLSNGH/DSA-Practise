class Solution {
public:
    int dp[1<<20];
    int maxi;
    bool solve(int bitmask,int remain) {
        if(dp[bitmask]!=-1)  return dp[bitmask];

        for(int j = 1;j<=maxi;j++) {
            int curr_bit = 1<<(j-1);
            if((curr_bit&bitmask)==0) {
                if(j>=remain||!solve(bitmask|curr_bit,remain-j)) {
                    return dp[bitmask] = 1;
                }
            }
        }
        return dp[bitmask] = 0;
    }
    bool canIWin(int n, int t) {
        memset(dp,-1,sizeof(dp));
        maxi = n;

        if(t<=0) return true;
        if(maxi>=t) return true;

        int sum = maxi*(maxi+1)/2;
        if(sum<t) return false;

        return solve(0,t);
    }
};