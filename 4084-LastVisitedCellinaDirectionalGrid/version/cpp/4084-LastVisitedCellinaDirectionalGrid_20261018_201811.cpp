// Last updated: 10/18/2026, 8:18:11 PM
1class Solution {
2public:
3    int n,m;
4    using v = vector<int>;
5    using vv = vector<v>;
6    pair<int,int>next_corr(int x,int y,char ch) {
7         if(ch=='R') return {x,y+1};
8         else if(ch=='L') return {x,y-1};
9         else if(ch=='U') return {x-1,y};
10         else return {x+1,y};
11    }
12    bool isvalid(int x,int y) {
13        return x>=0&&x<n&&y>=0&&y<m;
14    }
15    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
16        n = grid.size();
17        m = grid[0].size();
18        vv visited(n,v(m,false));
19        visited[0][0] = true;
20        queue<pair<int,int>>q;
21        q.push({0,0});
22        while(!q.empty()) {
23            auto [x,y] = q.front();
24            q.pop();
25            auto [new_x,new_y] = next_corr(x,y,grid[x][y]);
26
27            if(!isvalid(new_x,new_y)||visited[new_x][new_y]) return {x,y};
28            else {
29                visited[new_x][new_y] = true;
30                q.push({new_x,new_y});
31            }
32        }
33        return {};
34    }
35};