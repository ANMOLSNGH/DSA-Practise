class Solution {
public:
    using v = vector<bool>;
    using vv = vector<v>;
    using vvv = vector<vv>;

    vector<pair<int,int>>direc = {{1,0},{-1,0},{0,1},{0,-1}};
    typedef tuple<int,int,int,int>t;
    int minMoves(vector<string>& classroom, int energy) {
        int n = classroom.size();
        int m = classroom[0].size();
        queue<t>q;

        vector<vector<int>>litter_path(n,vector<int>(m,0));
        int cnt = 0;
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                if(classroom[i][j]=='L') {
                    litter_path[i][j] = cnt;
                    cnt++;
                    
                }
            }
        }
        if(cnt==0) return 0;
        int total_paths = (1<<cnt)-1;;
        vector<vvv>dp(n,vector<vv>(m,vector<v>(energy+1,v(1<<cnt,false))));
        

        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                if(classroom[i][j]=='S') {
                     dp[i][j][energy][0] = true;
                     q.push({i,j,energy,0});
                     break;
                }
            }
        }
        int moves = 0;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
            auto [i,j,e,p] = q.front();
            q.pop();
            if(p==total_paths) return moves;
            if(e==0) continue;

            for(auto [u,s]:direc) {
                int new_i = i + u;
                int new_j = j + s;
                int new_e = e-1;
                int next_mask = p;
                if(new_i>=0&&new_i<n&&new_j>=0&&new_j<m) {
                      if(classroom[new_i][new_j]=='X') continue;
                      if(classroom[new_i][new_j]=='R') 
                        new_e = energy;

                      else if(classroom[new_i][new_j]=='L') {
                        next_mask |= (1<<litter_path[new_i][new_j]);
                      }

                      if(!dp[new_i][new_j][new_e][next_mask]) {
                        dp[new_i][new_j][new_e][next_mask] = true;
                        q.push({new_i,new_j,new_e,next_mask});
                      }
                       
                }
            }
        }
        moves++;
    }

    return -1;
    }
};