class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
       sort(logs.begin(),logs.end(),[&](vector<int>&a,vector<int>&b){
        return a[1]<b[1];
       });
       vector<pair<int,int>>q(queries.size());
       for(int i = 0;i<queries.size();i++) q.push_back({queries[i],i});
       sort(q.begin(),q.end());
       unordered_map<int,int>mpp;
       int j = 0;
       int k = 0;
       vector<int>ans(queries.size());
       for(int i = 0;i<q.size();i++) {
        int query_str = q[i].first - x;
        int query_end = q[i].first;

           while(j<logs.size()&&logs[j][1]<=query_end) {
              mpp[logs[j][0]]++;
              j++;
           }
           while(k<logs.size()&&logs[k][1]<query_str) {
            mpp[logs[k][0]]--;
            if(mpp[logs[k][0]]==0) mpp.erase(logs[k][0]);
            k++;
           }

          ans[q[i].second] = n - mpp.size();
       }
       return ans;
    }
};