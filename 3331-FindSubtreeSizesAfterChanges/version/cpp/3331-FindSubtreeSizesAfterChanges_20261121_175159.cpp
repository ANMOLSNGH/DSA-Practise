// Last updated: 11/21/2026, 5:51:59 PM
1class Solution {
2public:
3    unordered_map<int, vector<int>> adj;
4    vector<int> resultSize;
5    vector<int> last;
6
7    void dfs(int currNode, string& s, vector<int>& parent) {
8        int c = s[currNode] - 'a';
9
10        int nearestAncestor = last[c];
11
12        last[c] = currNode;
13        for(int child : adj[currNode]) {
14            dfs(child, s, parent);
15        }
16
17        //back to currNode
18        last[c] = nearestAncestor;
19
20        //if currNode is root, it has no ancestor
21        if(currNode != 0) {
22            int newParent = parent[currNode]; //old parent
23
24            if(nearestAncestor != -1) {
25                newParent = nearestAncestor;
26            }
27
28            parent[currNode] = newParent;
29
30            resultSize[newParent] += resultSize[currNode];
31        }
32    }
33
34    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
35        int n = parent.size();
36
37        //parent[i] = node
38        //node is the parent of ith node
39        //node ---> i
40
41        for(int i = 1; i < n; i++) {
42            int u = parent[i]; //u is the parent
43            int v = i;
44            adj[u].push_back(v); //u --> v
45        }
46
47        resultSize.assign(n, 1);
48        last.assign(26, -1);
49
50        dfs(0, s, parent);
51
52        return resultSize;
53    }
54};
55