// Last updated: 10/27/2026, 9:46:59 PM
1class Solution {
2public:
3    vector<string> createGrid(int m, int n) {
4        vector<string>ans;
5        for(int i = 0;i<m;i++) {
6            string s = "";
7            for(int j = 0;j<n;j++) {
8
9                 if(i==0)  s += '.';
10
11                 else {
12                    if(j==n-1) s += '.';
13                    else s += '#';
14                 }
15            }
16            ans.push_back(s);
17        }
18
19        return ans;
20    }
21};