// Last updated: 9/30/2026, 5:19:28 PM
1class Solution {
2public:
3    vector<int> maxDepthAfterSplit(string seq) {
4        int n = seq.size();
5        vector<int>ans(n,0);
6        int depth = 0;
7        for(int i = 0;i<n;i++) {
8            if(seq[i]=='(') {
9                depth++;
10                if(depth&1) ans[i] = 1;
11            }
12            else {
13                if(depth&1) ans[i] = 1;
14                depth--;
15            }
16        }
17        return ans;
18    }
19};