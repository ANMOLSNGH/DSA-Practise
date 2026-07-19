class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        int max_reach = 0;
        int station = 0;
        priority_queue<long long>pq;
        for(int i = 0;i<n;i++) {
            if(startFuel>=target) return station; 
            int position = stations[i][0];
            int fuel = stations[i][1];
            
            while(!pq.empty()&&position>startFuel) {
                startFuel += pq.top();
                pq.pop();
                station++;
            }
            if(position>startFuel) return -1;

            pq.push(fuel);

        }
        while(startFuel  < target && !pq.empty()) {
           startFuel += pq.top();
            pq.pop();
            station++;
        }
        
        if(startFuel  < target) {
            return -1;
        }

        return station;
    }
};