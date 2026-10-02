class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        
     
        sort(intervals.begin(), intervals.end());
  
   
        vector<int> start(n);
        for(int i = 0; i < n; i++) {
            start[i] = intervals[i][0];
        }
        
        long long cnt = 0; 
        
        for(int i = 0; i < n; i++) {
            int end = intervals[i][1];
            
          
            int indx = upper_bound(start.begin() + i + 1, start.end(), end) - start.begin();
            
            cnt += (indx - i - 1); 
        }
        
        return cnt;
    }
};