class Solution {
public:
    int n,m;
    vector<pair<int,int>>direc = {{1,0},{-1,0},{0,1},{0,-1}};
    bool isvalid(int i,int j) {
        return i>=0&&i<n&&j>=0&&j<m;
    }
    void solve(vector<vector<char>>& board) {
         n =board.size();
         m = board[0].size();

        queue<pair<int,int>>q;
         for(int i = 0;i<n;i++) {
            if(board[i][0]=='O') {
                board[i][0] = 't';
                q.push({i,0});
            }
         }
          for(int i = 0;i<n;i++) {
            if(board[i][m-1]=='O') {
                board[i][m-1] = 't';
                q.push({i,m-1});
            }
         }
          for(int i = 0;i<m;i++) {
            if(board[0][i]=='O') {
                board[0][i] = 't';
                q.push({0,i});
            }
         }
          for(int i = 0;i<m;i++) {
            if(board[n-1][i]=='O') {
                board[n-1][i] = 't';
                q.push({n-1,i});
            }
         }

         while(!q.empty()) {
             auto [x,y] = q.front();
             q.pop();
             for(auto [r,c]:direc) {
                int new_x = x + r;
                int new_y = y + c;
                if(isvalid(new_x,new_y)&&board[new_x][new_y]=='O') {
                    board[new_x][new_y] = 't';
                    q.push({new_x,new_y});
                } 
             }
         }

         for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                if(board[i][j]=='t') board[i][j] = 'O';
                else board[i][j] = 'X';
            }
         }
    }
};