class Solution {
public:
    typedef long long ll;
    template<class T> using minHeap = priority_queue<T,vector<T>,greater<T>>;
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[&](vector<int>&a,vector<int>&b){
            if(a[0]==b[0]) return a[1]<b[1];
            return a[0]<b[0];
        });
        minHeap<int>pq;
        int grps  = 0;
        for(int i = 0;i<intervals.size();i++) {
            int strt_inter = intervals[i][0];
            int end_inter = intervals[i][1];
            if(!pq.empty()&&pq.top()<strt_inter) {
                pq.pop();
            }
            else {
                grps++;
            }
            pq.push(end_inter);
        }
        return grps;
    }
};