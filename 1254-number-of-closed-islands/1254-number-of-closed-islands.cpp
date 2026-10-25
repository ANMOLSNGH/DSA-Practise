class Solution {
public:
    int n , m;
    bool isvalid(int x,int y){
         return x>=0&&x<n&&y>=0&&y<m;
    }

    vector<pair<int,int>>direc = {{1,0},{0,1},{-1,0},{0,-1}};
    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int cnt = 0;
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                if(grid[i][j]==0) {
                    queue<pair<int,int>>q;
                    grid[i][j] = -1;
                    bool isPossible = true;
                    q.push({i,j});
                    while(!q.empty()) {
                        auto [x,y] = q.front();
                        q.pop();
                        for(int k = 0;k<4;k++) {
                            int new_x = x + direc[k].first;
                            int new_y = y + direc[k].second;
                            if(!isvalid(new_x,new_y)) {
                                isPossible = false;
                                continue;
                            }

                            if(grid[new_x][new_y]==1||grid[new_x][new_y]==-1) continue;

                            else {
                                grid[new_x][new_y] = -1;
                                q.push({new_x,new_y});
                            } 
                        }
                    }
                    if(isPossible) cnt++;
                }
            }
        }
        return cnt;

    }
};