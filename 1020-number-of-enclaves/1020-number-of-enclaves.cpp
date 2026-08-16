class Solution {
public:
    int n,m;
    vector<pair<int,int>>direc = {{1,0},{0,1},{-1,0},{0,-1}};
    bool isvalid(int x,int y) {
        return x>=0&&x<n&&y>=0&&y<m;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        queue<pair<int,int>>q;
        int cnt = 0;
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                if(grid[i][j]==1) cnt++;
            }
        }
        for(int i = 0;i<n;i++) {
            if(grid[i][0]==1) {
                grid[i][0] = 2;
                q.push({i,0});
                cnt--;
            }
        }
         for(int i = 0;i<n;i++) {
            if(grid[i][m-1]==1) {
                grid[i][m-1] = 2;
                q.push({i,m-1});
                cnt--;
            }
        }
         for(int i = 0;i<m;i++) {
            if(grid[0][i]==1) {
                grid[0][i] = 2;
                q.push({0,i});
                cnt--;
            }
        }
         for(int i = 0;i<m;i++) {
            if(grid[n-1][i]==1) {
                grid[n-1][i] = 2;
                q.push({n-1,i});
                cnt--;
            }
        }
        if(cnt==0) return 0;

        while(!q.empty()) {
            auto [x,y] = q.front();
            q.pop();
            for(auto [r,c] : direc) {
                int new_x = x + r;
                int new_y = y + c;
                if(isvalid(new_x,new_y)&&grid[new_x][new_y]==1) {
                    q.push({new_x,new_y});
                    grid[new_x][new_y] = 2;
                    cnt--;
                }
            }
        }
        return cnt;
    }
};