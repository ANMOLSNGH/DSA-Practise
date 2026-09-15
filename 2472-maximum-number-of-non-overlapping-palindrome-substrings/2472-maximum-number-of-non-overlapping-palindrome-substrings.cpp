class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<pair<int,int>>intervals;
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        for(int i =0; i<n ;i++) {
            dp[i][i] = true;
            if (k <= 1) { 
                intervals.push_back({i, i}); 
            }
        }
        
       for(int len = 2;len<=n;len++) {
         for(int i = 0;i<n-len+1;i++) {
            int j = i+len-1;
            if(i>j) continue;
            if(len==2){
                 if(s[i]==s[j]) {
                
                 dp[i][j] = true;
            }
        }
            
            else {
                if(s[i]==s[j]&&dp[i+1][j-1]) {
                   
                    dp[i][j] = true;
                }
            }
            if(dp[i][j]&&len>=k)  
                    intervals.push_back({i,j});
              
                    

         }
       }
       sort(intervals.begin(), intervals.end(), []( pair<int, int>& a,  pair<int, int>& b) {
            return a.second < b.second;
        });

        int last_end = -1;
        int count = 0;
        for(auto &interval : intervals) {
            if(interval.first>last_end){ count++;
            last_end = interval.second;}
        }
        return count;
       
    }
};