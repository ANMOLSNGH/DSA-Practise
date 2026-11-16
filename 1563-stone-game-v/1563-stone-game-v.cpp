class Solution {
public:
    int dp[501][501];
    vector<int>pref;
    int solve(vector<int>&stoneValue,int l,int r) {
       if(l==r) return 0;
       if(dp[l][r]!=-1) return dp[l][r];
       int max_alice_score = 0;
       for(int i = l;i<r;i++) {
        int leftScore = pref[i+1]-pref[l];
        int rightScore = pref[r+1] - pref[i+1];

        if(leftScore<rightScore) {
             max_alice_score = max(max_alice_score,leftScore+solve(stoneValue,l,i));
        }
        else if(leftScore>rightScore) {
            max_alice_score = max(max_alice_score,rightScore+solve(stoneValue,i+1,r));
        }
        else {
            int optimal  = max(solve(stoneValue,l,i),solve(stoneValue,i+1,r));
            max_alice_score = max(max_alice_score,optimal+leftScore);
        }
       }
       return dp[l][r] = max_alice_score;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        pref.assign(n+1,0);
        memset(dp, -1, sizeof(dp));
        for(int i = 0;i<n;i++) {
            pref[i+1] = pref[i] + stoneValue[i];
        }

       return solve(stoneValue,0,n-1);

    }
};