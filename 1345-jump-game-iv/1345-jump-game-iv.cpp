class Solution {
public:
    typedef tuple<int,int,int>t;
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,vector<int>>mpp;
        for(int i = 0;i<n;i++) {
            mpp[arr[i]].push_back(i);
        }
        queue<t>q;
        q.push({arr[0],0,0});
        vector<bool>visited(n,false);
        visited[0] = true;
        int prev_ele  = INT_MIN;
        while(!q.empty()) {
            auto [node,indx,steps] = q.front();
            q.pop();
            if(indx==n-1) return steps;
            if(indx+1<=n&&!visited[indx+1]) {
                q.push({arr[indx+1],indx+1,steps+1});
                visited[indx+1] = true;
            }
            if(indx-1>=0&&!visited[indx-1]) {
                q.push({arr[indx-1],indx-1,steps+1});
                visited[indx-1] = true;
            }
            if(node!=prev_ele) {
            for(auto i : mpp[arr[indx]]) {
                if(!visited[i]) {
                     q.push({arr[i],i,steps+1});
                     visited[i] = true;
                }
            }
        }
            prev_ele = node;
        }
        return n-1;
    }
};