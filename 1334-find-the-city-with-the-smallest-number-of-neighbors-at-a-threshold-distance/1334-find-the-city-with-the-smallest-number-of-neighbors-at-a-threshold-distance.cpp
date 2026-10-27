class Solution {
public:

    int INF = 1e9 + 7;
    int findTheCity(int n, vector<vector<int>>& edges, int dist) {
   
       //floyd warshall o(n^3)

       /*
        k = 0->1->2->3   (dp[i][k] != INF && dp[k][j] != INF) {
                dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);

                1 -> 2 ->3 -> 5 -> 6 so [1 to 3 path is  1-> 2 + 2-> 3] now from 1 to 5 is 1-> 3 + 3-> 5 
                also add one threshold condn 
          }
       */
        vector<vector<int>>dp(n,vector<int>(n,INF));


        for(int i = 0;i<n;i++) dp[i][i] = 0;

        for(int i = 0;i<edges.size();i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            dp[u][v] = wt;
            dp[v][u] = wt;
        }

        for(int k = 0;k<n;k++) {
            for(int i = 0;i<n;i++) {
                for(int j = 0;j<n;j++) {
                    if(dp[i][k]!=INF&&dp[k][j]!=INF) {
                        dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
                    }
                }
            }
        }
        int mini = INT_MAX;
        int node = -1;
        for(int i = 0;i<n;i++) {
            int cnt = 0;
            for(int j = 0;j<n;j++) {
                   if(dp[i][j]<=dist) {
                      cnt++;
                   }
            }
            
                if(cnt<=mini) {
                    mini = cnt;
                    node = i;
                }
        }
       return node;
    }
};