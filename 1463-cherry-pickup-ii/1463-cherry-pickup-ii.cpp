class Solution {
public:

   // row1 , colm1,colm2 so 3 states at a time dp[row][colm1][colm2];
   // 
   //
    int dp[71][71][71];
    int n,m;
    int solve(int row,int colm1,int colm2,vector<vector<int>>&grid) {

        if(row>=n) return 0;

        if(dp[row][colm1][colm2]!=-1) return dp[row][colm1][colm2];
       
       int curr_cherri= grid[row][colm1];
       if(colm1!=colm2) curr_cherri += grid[row][colm2];

       int maxi_cherri = 0;
       for(int i = -1;i<=1;i++) {
        for(int j = -1;j<=1;j++) {
            int n_c1 = colm1 + i;
            int n_c2 = colm2 + j;
            if(n_c1<0||n_c1>=m) continue;
            if(n_c2<0||n_c2>=m) continue;
            maxi_cherri = max(maxi_cherri,curr_cherri + solve(row+1,n_c1,n_c2,grid));     
         }
       }
       return dp[row][colm1][colm2] = maxi_cherri;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,m-1,grid);
    }
};