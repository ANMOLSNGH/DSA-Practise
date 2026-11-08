// Last updated: 11/8/2026, 12:49:34 PM
1class Solution {
2public:
3    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
4        vector<vector<string>>ans;
5        int i = 0 , j = 0;
6        int n = s1.size();
7        string a = "";
8        string b = "";
9        vector<string>res;
10        while(i<n&&j<n) {
11            if(s1[i]!=s2[j]) {
12                a += s1[i];
13                b += s2[j];
14            }
15            else {
16                if(a!=""&&b!="") {
17                    res.push_back(a);
18                    res.push_back(b);
19
20                    ans.push_back(res);
21                }
22
23                res.clear();
24                a.clear();
25                b.clear();
26            }
27            i++,j++;
28        }
29        if(a!=""&&b!="") {
30            res.push_back(a);
31            res.push_back(b);
32
33            ans.push_back(res);
34        }
35        return ans;
36    }
37};