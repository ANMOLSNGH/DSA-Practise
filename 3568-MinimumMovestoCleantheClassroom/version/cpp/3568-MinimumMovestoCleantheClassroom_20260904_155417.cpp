// Last updated: 9/4/2026, 3:54:17 PM
1class Solution {
2public:
3    using v = vector<bool>;
4    using vv = vector<v>;
5    using vvv = vector<vv>;
6
7    vector<pair<int,int>>direc = {{1,0},{-1,0},{0,1},{0,-1}};
8    typedef tuple<int,int,int,int>t;
9    int minMoves(vector<string>& classroom, int energy) {
10        int n = classroom.size();
11        int m = classroom[0].size();
12        queue<t>q;
13
14        vector<vector<int>>litter_path(n,vector<int>(m,0));
15        int cnt = 0;
16        for(int i = 0;i<n;i++) {
17            for(int j = 0;j<m;j++) {
18                if(classroom[i][j]=='L') {
19                    litter_path[i][j] = cnt;
20                    cnt++;
21                    
22                }
23            }
24        }
25        if(cnt==0) return 0;
26        int total_paths = (1<<cnt)-1;;
27        vector<vvv>dp(n,vector<vv>(m,vector<v>(energy+1,v(1<<cnt,false))));
28        
29
30        for(int i = 0;i<n;i++) {
31            for(int j = 0;j<m;j++) {
32                if(classroom[i][j]=='S') {
33                     dp[i][j][energy][0] = true;
34                     q.push({i,j,energy,0});
35                     break;
36                }
37            }
38        }
39        int moves = 0;
40        while(!q.empty()) {
41            int sz = q.size();
42            while(sz--) {
43            auto [i,j,e,p] = q.front();
44            q.pop();
45            if(p==total_paths) return moves;
46            if(e==0) continue;
47
48            for(auto [u,s]:direc) {
49                int new_i = i + u;
50                int new_j = j + s;
51                int new_e = e-1;
52                int next_mask = p;
53                if(new_i>=0&&new_i<n&&new_j>=0&&new_j<m) {
54                      if(classroom[new_i][new_j]=='X') continue;
55                      if(classroom[new_i][new_j]=='R') 
56                        new_e = energy;
57
58                      else if(classroom[new_i][new_j]=='L') {
59                        next_mask |= (1<<litter_path[new_i][new_j]);
60                      }
61
62                      if(!dp[new_i][new_j][new_e][next_mask]) {
63                        dp[new_i][new_j][new_e][next_mask] = true;
64                        q.push({new_i,new_j,new_e,next_mask});
65                      }
66                       
67                }
68            }
69        }
70        moves++;
71    }
72
73    return -1;
74    }
75};