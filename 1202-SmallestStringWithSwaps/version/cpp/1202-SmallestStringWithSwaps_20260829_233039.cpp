// Last updated: 8/29/2026, 11:30:39 PM
1class Solution {
2public:
3    vector<int>parent;
4    vector<int>rank;
5
6    int find(int u) {
7        if(u==parent[u]) return u;
8        return parent[u]  = find(parent[u]);
9    }
10
11    void unioni(int x,int y) {
12        int parent_x = find(x);
13        int parent_y = find(y);
14        if(parent_x==parent_y) return;
15
16        if(rank[parent_x]>=rank[parent_y]) {
17            parent[parent_y] = parent_x;
18            rank[parent_x]++;
19        }
20        else {
21            parent[parent_x] = parent_y;
22            rank[parent_y]++;
23        }
24    }
25    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
26        int n = s.size();
27        parent.assign(n,0);
28        rank.assign(n,0);
29        for(int i = 0;i<n;i++) parent[i] = i;
30        for(auto ele : pairs) {
31            unioni(ele[0],ele[1]);
32        }
33
34        unordered_map<int,vector<int>>mpp;
35        for(int i = 0;i<n;i++) {
36            mpp[find(i)].push_back(i);
37        }
38
39        for(auto &p : mpp) {
40            string temp = "";
41            for(int i : p.second) temp += s[i];
42            sort(temp.begin(),temp.end());
43            int k = 0;
44            for(int i : p.second) s[i] = temp[k++];
45        }
46
47        return s;
48    }
49};