// Last updated: 9/26/2026, 10:55:26 PM
1class Solution {
2public:
3    string evaluate(string s, vector<vector<string>>& knowledge) {
4        unordered_map<string,string>mpp;
5        for(auto str : knowledge) {
6            mpp[str[0]] = str[1];
7        }
8        string ans = "";
9        for(int i = 0;i<s.size();i++) {
10            if(s[i]=='(') {
11                i++;
12                string get = "";
13                while(s[i]!=')') {
14                    get += s[i];
15                    i++;
16                }
17                if(mpp.find(get)!=mpp.end()) ans += mpp[get];
18                else ans += '?';
19            }
20            else 
21            ans += s[i];
22        }
23        return ans;
24    }
25};