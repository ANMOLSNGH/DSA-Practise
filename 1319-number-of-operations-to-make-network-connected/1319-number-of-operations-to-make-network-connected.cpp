class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    void unioni(int x, int y, int &val) {
        int parent_x = find(x);
        int parent_y = find(y);

        if (parent_x == parent_y) {
            val++;
            return;
        }

        if (rank[parent_x] < rank[parent_y]) {
            parent[parent_x] = parent_y;
        }
        else if (rank[parent_x] > rank[parent_y]) {
            parent[parent_y] = parent_x;
        }
        else {
            parent[parent_y] = parent_x;
            rank[parent_x]++;
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        int total = 0;

        rank.assign(n, 0);
        parent.resize(n);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        for (int i = 0; i < connections.size(); i++) {
            int x = connections[i][0];
            int y = connections[i][1];
            unioni(x, y, total);
        }

        int components = 0;

        for (int i = 0; i < n; i++) {
            if (parent[i] == i)
                components++;
        }

        if (components == 1) return 0;

        if (components <= total + 1)
            return components - 1;

        return -1;
    }
};