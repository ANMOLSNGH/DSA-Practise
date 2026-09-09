// Last updated: 9/9/2026, 11:12:29 PM
1class Solution {
2public:
3    int maxArea(vector<vector<int>>& mat) {
4        int n = mat.size(),m = mat[0].size();
5        vector<vector<int>> dp(n,vector<int>(m));
6        unordered_map<int,vector<pair<int,int>>> mpp;
7        for(int i=0; i<n; i++){
8            dp[i][0] = (mat[i][0]==1);
9            mpp[dp[i][0]].push_back({i,0});
10        }
11        for(int j=0; j<m; j++){
12            dp[0][j] = (mat[0][j]==1);
13            mpp[dp[0][j]].push_back({0,j});
14        }
15        for(int i=1; i<n; i++){
16            for(int j=1; j<m; j++){
17                if(mat[i][j]==0) continue;
18                dp[i][j] = min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
19                mpp[dp[i][j]].push_back({i,j});
20            }
21        }
22        
23        int ans = 0;
24        for(auto& it : mpp){
25            int s = it.first;
26            vector<pair<int,int>> v = it.second;
27            int x = v.size();
28            if(x<=1) continue;
29            for(int i=0; i<x; i++){
30                for(int j=i+1; j<x; j++){
31                    int r1=v[i].first;
32                    int c1=v[i].second;
33                    int r2=v[j].first;
34                    int c2=v[j].second;
35
36                    if(abs(r1-r2)>=s || abs(c1-c2)>=s){
37                        ans=max(ans,s);
38                        break;
39                    }
40                }
41            }  
42            
43        }
44        return ans*ans;
45
46        
47    }
48};