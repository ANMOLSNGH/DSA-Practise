// Last updated: 10/5/2026, 12:15:52 PM
1class Solution {
2public:
3    bool checkValidString(string s) {
4        int mini = 0,maxi = 0;
5        for(char c:s) {
6            if(c==')') {
7                mini--;
8                maxi--;
9            }
10            else if(c=='(') {
11                mini++;
12                maxi++;
13            }
14            else {
15                mini--;
16                maxi++;
17            }
18            if(maxi<0) return false;
19
20            mini = max(mini,0);
21        }
22        return mini==0;
23    }
24};