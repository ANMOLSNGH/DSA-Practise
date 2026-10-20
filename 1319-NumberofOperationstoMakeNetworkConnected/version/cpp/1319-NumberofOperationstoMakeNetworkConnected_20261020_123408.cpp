// Last updated: 10/20/2026, 12:34:08 PM
1class Solution {
2public:
3    vector<int> parent;
4    vector<int> rank;
5
6    int find(int x) {
7        if (x == parent[x]) return x;
8        return parent[x] = find(parent[x]);
9    }
10
11    void unioni(int x, int y, int &val) {
12        int parent_x = find(x);
13        int parent_y = find(y);
14
15        if (parent_x == parent_y) {
16            val++;
17            return;
18        }
19
20        if (rank[parent_x] < rank[parent_y]) {
21            parent[parent_x] = parent_y;
22        }
23        else if (rank[parent_x] > rank[parent_y]) {
24            parent[parent_y] = parent_x;
25        }
26        else {
27            parent[parent_y] = parent_x;
28            rank[parent_x]++;
29        }
30    }
31
32    int makeConnected(int n, vector<vector<int>>& connections) {
33        int total = 0;
34
35        rank.assign(n, 0);
36        parent.resize(n);
37
38        for (int i = 0; i < n; i++)
39            parent[i] = i;
40
41        for (int i = 0; i < connections.size(); i++) {
42            int x = connections[i][0];
43            int y = connections[i][1];
44            unioni(x, y, total);
45        }
46
47        int components = 0;
48
49        for (int i = 0; i < n; i++) {
50            if (parent[i] == i)
51                components++;
52        }
53
54        if (components == 1) return 0;
55
56        if (components <= total + 1)
57            return components - 1;
58
59        return -1;
60    }
61};