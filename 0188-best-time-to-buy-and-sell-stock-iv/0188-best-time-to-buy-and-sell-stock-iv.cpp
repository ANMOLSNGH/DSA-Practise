class Solution {
public:
     int dp[1001][2][101];
     int n;

     using v = vector<int>;
     using vv = vector<v>;
     using vvv = vector<vv>;

    int solve(vector<int>&prices,int indx,int cnt,int state) {
        if(indx>=n) return 0;
        if(cnt==0) return 0;

        if(dp[indx][state][cnt]!=-1) return dp[indx][state][cnt];
        int profit = 0;
        // skip 
        if(state==0) {
            int take = -prices[indx] + solve(prices,indx+1,cnt,1);
            int skip = solve(prices,indx+1,cnt,0);
            profit = max(take,skip);
        }

        else if(state==1) {
            int take = prices[indx] + solve(prices,indx+1,cnt-1,0);
            int skip = solve(prices,indx+1,cnt,1);
            profit =  max(take,skip);
        }

        return dp[indx][state][cnt] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        n = prices.size();
        memset(dp,-1,sizeof(dp));
        return solve(prices,0,k,0);
    }
};