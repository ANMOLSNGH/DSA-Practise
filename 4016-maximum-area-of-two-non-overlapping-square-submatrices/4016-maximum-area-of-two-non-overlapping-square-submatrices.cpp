class Solution {
public:
    // make dp to solve maximum sq area ending at i,j

    bool check(int n,int m,int mid , vector<vector<int>>&dp,vector<int>&suffixi,vector<int>&suffixj ) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) { 
                if(dp[i][j]>=mid) {
                     int rowBelow = i +mid;
                     if(rowBelow<n&&suffixi[rowBelow]>=mid) {
                        return true;
                     }
                     int colRight = j+mid;
                     if(colRight<m&&suffixj[colRight]>=mid) return true;
                }
           }
        }
        return false;
    }
    int maxArea(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        if(n==0||m==0) return 0;
        vector<vector<int>>dp(n,vector<int>(m));
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                if(mat[i][j]==1) {
                if(i==0||j==0) {
                    dp[i][j] = 1;
                }
                else 
                dp[i][j] = min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]}) + 1;
                }
            }
        }

        vector<int>suffixi(n);
        vector<int>suffixj(m);

        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                suffixi[i] = max(suffixi[i],dp[i][j]);
                suffixj[j] = max(suffixj[j],dp[i][j]);
            }
        }

        for(int i = n-2;i>=0;i--) {
            suffixi[i] = max(suffixi[i],suffixi[i+1]);
        }
         for(int i = m-2;i>=0;i--) {
            suffixj[i] = max(suffixj[i],suffixj[i+1]);
        }

        int low = 1;
        int high = min(n,m);
        int ans  = 0;

        while(low<=high) {
            int mid = low + (high - low) / 2;
            if(check(n,m,mid,dp,suffixi,suffixj)) {
                ans = mid;
                low = mid + 1;
            }
            else high = mid-1;
        }
        return ans*ans;

    }
};