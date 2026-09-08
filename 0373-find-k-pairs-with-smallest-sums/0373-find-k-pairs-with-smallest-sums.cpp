class Solution {
public:
    typedef pair<int,pair<int,int>>P;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>>ans;
        priority_queue<P,vector<P>,greater<P>>pq;
        set<pair<int,int>>st;
        st.insert({0,0});
        int sum = nums1[0] + nums2[0];
        pq.push({sum,{0,0}});
        while(k--&&!pq.empty()) {
            auto temp = pq.top();
            pq.pop();
            int sum = temp.first;
            int i = temp.second.first;
            int j = temp.second.second;
            ans.push_back({nums1[i],nums2[j]});
            if(i+1<n&&st.find({i+1,j})==st.end()) {
                pq.push({nums1[i+1]+nums2[j],{i+1,j}});
                st.insert({i+1,j});
            }
            if(j+1<m&&st.find({i,j+1})==st.end()) {
                pq.push({nums1[i]+nums2[j+1],{i,j+1}});
                st.insert({i,j+1});
            }
        }
        return ans;

    }
};