class Solution {
public:
    int n,m;
    typedef tuple<int,int,int>t;
    vector<pair<int,int>>direc = {{0,1},{0,-1},{1,0},{-1,0}};
    bool isvalid(int x,int y) {
        return x>=0&&x<n&&y>=0&&y<m;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        n = mat.size();
        m = mat[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));

        queue<t>q;
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                 if(mat[i][j]==0) q.push({0,i,j});
            }
        }

        while(!q.empty()) {
            auto [val,x,y] = q.front();
            q.pop();
            for(auto [u,d]:direc) {
                int new_x = x + u;
                int new_y = y + d;
                if(isvalid(new_x,new_y)&&dp[new_x][new_y]==0&&mat[new_x][new_y]!=0) {
                    dp[new_x][new_y] = val+1;
                    q.push({val+1,new_x,new_y});
                }

            }
        }
        return dp;
    }
};