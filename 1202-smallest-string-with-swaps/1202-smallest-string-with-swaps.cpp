class Solution {
public:
    vector<int>parent;
    vector<int>rank;

    int find(int u) {
        if(u==parent[u]) return u;
        return parent[u]  = find(parent[u]);
    }

    void unioni(int x,int y) {
        int parent_x = find(x);
        int parent_y = find(y);
        if(parent_x==parent_y) return;

        if(rank[parent_x]>=rank[parent_y]) {
            parent[parent_y] = parent_x;
            rank[parent_x]++;
        }
        else {
            parent[parent_x] = parent_y;
            rank[parent_y]++;
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        parent.assign(n,0);
        rank.assign(n,0);
        for(int i = 0;i<n;i++) parent[i] = i;
        for(auto ele : pairs) {
            unioni(ele[0],ele[1]);
        }

        unordered_map<int,vector<int>>mpp;
        for(int i = 0;i<n;i++) {
            mpp[find(i)].push_back(i);
        }

        for(auto &p : mpp) {
            string temp = "";
            for(int i : p.second) temp += s[i];
            sort(temp.begin(),temp.end());
            int k = 0;
            for(int i : p.second) s[i] = temp[k++];
        }

        return s;
    }
};