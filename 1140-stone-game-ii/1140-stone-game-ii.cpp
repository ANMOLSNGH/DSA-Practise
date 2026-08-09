class Solution {
public:
    int t[2][101][101];
    int n;
    int solve(int indx,int player,int M,vector<int>&piles) {
        if(indx>=n) return 0;

        if(t[player][indx][M]!=-1) return t[player][indx][M];
        int total = 0;
        int result = player==1?-1:1e9;

        for(int i = 1;i<=min(2*M,n-indx);i++) {
            total += piles[i+indx-1];
            if(player==1) {
                result = max(result,total + solve(i+indx,1-player,max(M,i),piles));
            }
            else {
                result  = min(result,solve(i+indx,1-player,max(M,i),piles));
            }
        }
        return t[player][indx][M] = result; 
    }
    int stoneGameII(vector<int>& piles) {
         n = piles.size();
        memset(t,-1,sizeof(t));
        return solve(0,1,1,piles);
    }
};