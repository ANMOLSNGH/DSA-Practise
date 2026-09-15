// Last updated: 9/15/2026, 10:32:38 AM
1class Solution {
2public:
3    int maxPalindromes(string s, int k) {
4        int n = s.size();
5        vector<pair<int,int>>intervals;
6        vector<vector<bool>>dp(n,vector<bool>(n,false));
7        for(int i =0; i<n ;i++) {
8            dp[i][i] = true;
9            if (k <= 1) { 
10                intervals.push_back({i, i}); 
11            }
12        }
13        
14       for(int len = 2;len<=n;len++) {
15         for(int i = 0;i<n-len+1;i++) {
16            int j = i+len-1;
17            if(i>j) continue;
18            if(len==2){
19                 if(s[i]==s[j]) {
20                
21                 dp[i][j] = true;
22            }
23        }
24            
25            else {
26                if(s[i]==s[j]&&dp[i+1][j-1]) {
27                   
28                    dp[i][j] = true;
29                }
30            }
31            if(dp[i][j]&&len>=k)  
32                    intervals.push_back({i,j});
33              
34                    
35
36         }
37       }
38       sort(intervals.begin(), intervals.end(), []( pair<int, int>& a,  pair<int, int>& b) {
39            return a.second < b.second;
40        });
41
42        int last_end = -1;
43        int count = 0;
44        for(auto &interval : intervals) {
45            if(interval.first>last_end){ count++;
46            last_end = interval.second;}
47        }
48        return count;
49       
50    }
51};