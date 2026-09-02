// Last updated: 9/2/2026, 11:24:59 PM
1class Solution {
2public:
3    typedef tuple<int,int,int>t;
4    int minJumps(vector<int>& arr) {
5        int n = arr.size();
6        unordered_map<int,vector<int>>mpp;
7        for(int i = 0;i<n;i++) {
8            mpp[arr[i]].push_back(i);
9        }
10        queue<t>q;
11        q.push({arr[0],0,0});
12        vector<bool>visited(n,false);
13        visited[0] = true;
14        int prev_ele  = INT_MIN;
15        while(!q.empty()) {
16            auto [node,indx,steps] = q.front();
17            q.pop();
18            if(indx==n-1) return steps;
19            if(indx+1<=n&&!visited[indx+1]) {
20                q.push({arr[indx+1],indx+1,steps+1});
21                visited[indx+1] = true;
22            }
23            if(indx-1>=0&&!visited[indx-1]) {
24                q.push({arr[indx-1],indx-1,steps+1});
25                visited[indx-1] = true;
26            }
27            if(node!=prev_ele) {
28            for(auto i : mpp[arr[indx]]) {
29                if(!visited[i]) {
30                     q.push({arr[i],i,steps+1});
31                     visited[i] = true;
32                }
33            }
34        }
35            prev_ele = node;
36        }
37        return n-1;
38    }
39};