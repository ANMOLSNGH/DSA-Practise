class Solution {
public:
    int dp[105][105];
    int n;
    bool solve(int open_cnt,int indx,string &s) {
        if(indx>=n) {
            if(open_cnt==0) return true;
            return false;
        }
        if(open_cnt>n-indx) return false;

        if(dp[indx][open_cnt]!=-1) return dp[indx][open_cnt];

        char c = s[indx];

        if(c=='(') return dp[indx][open_cnt] = solve(open_cnt+1,indx+1,s);

       else if (c == ')') {
            if (open_cnt == 0) return dp[indx][open_cnt] = false;
            return dp[indx][open_cnt] = solve(open_cnt - 1,indx + 1,s);
        }

        else {
            bool option1 = solve(open_cnt+1,indx+1,s);
            if(option1) return dp[indx][open_cnt] = true;
             bool option2 = open_cnt>0&&solve(open_cnt-1,indx+1,s);
            if(option2) return dp[indx][open_cnt] = true;
             bool option3 = solve(open_cnt,indx+1,s);
            if(option3) return dp[indx][open_cnt] = true;

        }
        return dp[indx][open_cnt] = false;
    }
    bool checkValidString(string s) {
        n = s.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,s);
    }
};