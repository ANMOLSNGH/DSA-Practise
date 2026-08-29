// Last updated: 8/30/2026, 12:25:22 AM
1class Solution {
2public:
3    vector<int> parent;
4    vector<int> rank;
5
6    int find(int u) {
7        if (u == parent[u]) return u;
8        return parent[u] = find(parent[u]);
9    }
10
11    void unioni(int x, int y) {
12        int parent_x = find(x);
13        int parent_y = find(y);
14        if (parent_x == parent_y) return;
15
16        if (rank[parent_x] >= rank[parent_y]) {
17            parent[parent_y] = parent_x;
18            rank[parent_x]++;
19        } else {
20            parent[parent_x] = parent_y;
21            rank[parent_y]++;
22        }
23    }
24
25    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& pairs) {
26        int n = source.size();
27        parent.assign(n, 0);
28        rank.assign(n, 0);
29        
30        for (int i = 0; i < n; i++) parent[i] = i;
31        
32        for (auto& ele : pairs) {
33            unioni(ele[0], ele[1]);
34        }
35        
36        // Group indices by their root parent
37        unordered_map<int, vector<int>> mpp;
38        for (int i = 0; i < n; i++) {
39            mpp[find(i)].push_back(i);
40        }
41        
42        int cnt = 0;
43        
44        for (auto& p : mpp) {
45            unordered_map<int, int> freq;
46            
47            // Count frequencies of source elements in this component
48            for (int idx : p.second) {
49                freq[source[idx]]++;
50            }
51            
52            // Try to match with target elements
53            for (int idx : p.second) {
54                if (freq[target[idx]] > 0) {
55                    freq[target[idx]]--; // Match found
56                } else {
57                    cnt++; // No match found, distance increases
58                }
59            }
60        }
61        
62        return cnt;
63    }
64};