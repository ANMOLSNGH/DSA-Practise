// Last updated: 9/2/2026, 11:26:54 PM
1class Solution {
2public:
3    typedef tuple<int,int,int>t;
4    
5    int minJumps(vector<int>& arr) {
6        ios_base::sync_with_stdio(false);
7        cin.tie(NULL);
8        int n = arr.size();
9        unordered_map<int,vector<int>>mpp;
10        for(int i = 0;i<n;i++) {
11            mpp[arr[i]].push_back(i);
12        }
13        queue<t>q;
14        q.push({arr[0],0,0});
15        vector<bool>visited(n,false);
16        visited[0] = true;
17        int prev_ele  = INT_MIN;
18        while(!q.empty()) {
19            auto [node,indx,steps] = q.front();
20            q.pop();
21            if(indx==n-1) return steps;
22            if(indx+1<=n&&!visited[indx+1]) {
23                q.push({arr[indx+1],indx+1,steps+1});
24                visited[indx+1] = true;
25            }
26            if(indx-1>=0&&!visited[indx-1]) {
27                q.push({arr[indx-1],indx-1,steps+1});
28                visited[indx-1] = true;
29            }
30            if(node!=prev_ele) {
31            for(auto i : mpp[arr[indx]]) {
32                if(!visited[i]) {
33                     q.push({arr[i],i,steps+1});
34                     visited[i] = true;
35                }
36            }
37        }
38            prev_ele = node;
39        }
40        return n-1;
41    }
42};