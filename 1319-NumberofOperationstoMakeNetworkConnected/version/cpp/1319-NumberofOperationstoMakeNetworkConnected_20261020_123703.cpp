// Last updated: 10/20/2026, 12:37:03 PM
1class Solution {
2public:
3    vector<int>parent;
4    vector<int>rank;
5
6    int find(int x) {
7        if(x==parent[x]) return x;
8        return x = find(parent[x]);
9    }
10
11void unioni(int x, int y,int &val) {
12    int parent_x = find(x);
13    int parent_y = find(y);
14
15    if (parent_x == parent_y) {
16         val++;
17         return;
18    }
19
20    if (rank[parent_x] < rank[parent_y]) {
21        parent[parent_x] = parent_y;
22    }
23    else if (rank[parent_x] > rank[parent_y]) {
24        parent[parent_y] = parent_x;
25    }
26    else {
27        parent[parent_y] = parent_x;
28        rank[parent_x]++;
29    }
30}
31    int makeConnected(int n, vector<vector<int>>& connections) {
32        int total = 0;
33        rank.assign(n,0);
34        parent.resize(n);
35        for(int i = 0;i<n;i++) parent[i] = i;
36
37        for(int i = 0;i<connections.size();i++) {
38            int x = connections[i][0];
39            int y = connections[i][1];
40            unioni(x,y,total);
41        }
42
43        int components = 0;
44        for(int i = 0;i<n;i++) {
45            if(parent[i]==i) components++;
46        }
47
48        if(components==1) return 0;
49
50        if(components<=total+1) return components-1;
51
52        return -1;
53    }
54};