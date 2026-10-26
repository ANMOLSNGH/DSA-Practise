// Last updated: 10/26/2026, 1:21:45 PM
1class Solution {
2public:
3    int n , m;
4    bool isvalid(int x,int y){
5         return x>=0&&x<n&&y>=0&&y<m;
6    }
7
8    vector<pair<int,int>>direc = {{1,0},{0,1},{-1,0},{0,-1}};
9    int countIslands(vector<vector<int>>& grid, int k) {
10        n = grid.size();
11        m = grid[0].size();
12        int cnt = 0;
13        for(int i = 0;i<n;i++) {
14            for(int j = 0;j<m;j++) {
15                if(grid[i][j]!=0&&grid[i][j]!=-1) {
16                    queue<pair<int,int>>q;
17                    long long sum = grid[i][j];
18                    grid[i][j] = -1;
19                    q.push({i,j});
20                    while(!q.empty()) {
21                        auto [x,y] = q.front();
22                        q.pop();
23                        for(int k = 0;k<4;k++) {
24                            int new_x = x + direc[k].first;
25                            int new_y = y + direc[k].second;
26                            if(!isvalid(new_x,new_y)) {
27                                continue;
28                            }
29
30                            if(grid[new_x][new_y]==0||grid[new_x][new_y]==-1) continue;
31
32                            sum += grid[new_x][new_y];
33                            grid[new_x][new_y] = -1;
34                            q.push({new_x,new_y});
35                        
36                        }
37                    }
38                    if(sum%k==0) cnt++;
39                }
40            }
41        }
42        return cnt;
43
44    }
45};