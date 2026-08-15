class Solution {
public:
    vector<pair<int,int>>direc = {{1,0},{0,1},{0,-1},{-1,0}};
    int n,m;
    bool isvalid(int x,int y) {
        return x>=0&&x<n&&y>=0&&y<m;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        queue<pair<int,int>>q;
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                if(grid[i][j]==2) {
                    q.push({i,j});
                }
            }
        } 
        int level = 0;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto [x,y] = q.front();
                q.pop();
                for(auto [r,c]:direc) {
                    int new_x = x+r;
                    int new_y = y+c;
                    if(isvalid(new_x,new_y)&&grid[new_x][new_y]==1) {
                        grid[new_x][new_y] = 2;
                        q.push({new_x,new_y});
                    }
                }
            }
            if(q.size()>0)
            level++;
        }

          for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                if(grid[i][j]==1) {
                   return -1;
                }
            }
        }
        return level;

    }
};