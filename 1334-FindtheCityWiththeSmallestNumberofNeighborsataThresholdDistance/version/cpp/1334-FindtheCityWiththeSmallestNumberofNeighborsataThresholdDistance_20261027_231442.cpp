// Last updated: 10/27/2026, 11:14:42 PM
1class Solution {
2public:
3
4    int INF = 1e9 + 7;
5    int findTheCity(int n, vector<vector<int>>& edges, int dist) {
6   
7       //floyd warshall o(n^3)
8
9       /*
10        k = 0->1->2->3   (dp[i][k] != INF && dp[k][j] != INF) {
11                dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
12
13                1 -> 2 ->3 -> 5 -> 6 so [1 to 3 path is  1-> 2 + 2-> 3] now from 1 to 5 is 1-> 3 + 3-> 5 
14                also add one threshold condn 
15          }
16       */
17        vector<vector<int>>dp(n,vector<int>(n,INF));
18
19
20        for(int i = 0;i<n;i++) dp[i][i] = 0;
21
22        for(int i = 0;i<edges.size();i++) {
23            int u = edges[i][0];
24            int v = edges[i][1];
25            int wt = edges[i][2];
26
27            dp[u][v] = wt;
28            dp[v][u] = wt;
29        }
30
31        for(int k = 0;k<n;k++) {
32            for(int i = 0;i<n;i++) {
33                for(int j = 0;j<n;j++) {
34                    if(dp[i][k]!=INF&&dp[k][j]!=INF) {
35                        dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
36                    }
37                }
38            }
39        }
40        int mini = INT_MAX;
41        int node = -1;
42        for(int i = 0;i<n;i++) {
43            int cnt = 0;
44            for(int j = 0;j<n;j++) {
45                   if(dp[i][j]<=dist) {
46                      cnt++;
47                   }
48            }
49            
50                if(cnt<=mini) {
51                    mini = cnt;
52                    node = i;
53                }
54        }
55       return node;
56    }
57};