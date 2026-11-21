// Last updated: 11/21/2026, 8:08:25 PM
1class Solution {
2public:
3    vector<string> assignUmbrella(vector<int>& rain) {
4        int alice_cnt = 0;
5        int bob_cnt = 0;
6        int n = rain.size();
7        vector<string>ans(n);
8        for(int i = 0;i<n;i++) {
9            if(i+1<n&&rain[i]==rain[i+1]&&rain[i]==1) {
10                if(alice_cnt>bob_cnt) {
11                    ans[i] = "Bob";
12                    bob_cnt++;
13                }
14                else {
15                    ans[i] = "Alice";
16                    alice_cnt++;
17                }
18            }
19            else if(rain[i]==1) {
20                ans[i] = "Bob";
21                bob_cnt++;
22            }
23            else if(rain[i]==0) {
24                ans[i] = "None";
25            }
26        }
27        return ans;
28    }
29};