// Last updated: 8/30/2026, 11:26:31 PM
1class Solution {
2public:
3    vector<int> partitionLabels(string s) {
4        vector<int>last_seen(26,0);
5        int n = s.size();
6        for(int i = 0;i<s.size();i++) {
7            last_seen[s[i]-'a'] = i;
8        }
9        int block_start = 0;
10        int max_indx_seen = 0;
11        vector<int>ans;
12        for(int i = 0;i<n;i++) {
13            int q_indx = last_seen[s[i]-'a'];
14
15            max_indx_seen = max(max_indx_seen,q_indx);
16            if(i==max_indx_seen) {
17                int partition = max_indx_seen - block_start + 1;
18                ans.push_back(partition);
19                block_start = i + 1;
20            }
21        }
22        return ans;
23    }
24};