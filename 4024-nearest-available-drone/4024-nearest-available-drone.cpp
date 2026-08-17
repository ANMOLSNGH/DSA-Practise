class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int mini_val = INT_MAX;
        int n = drones.size();
        int indx = -1;
        int tar_x = target[0];
        int tar_y = target[1];
        for(int i = 0;i<n;i++) {
            int x = drones[i][0];
            int y = drones[i][1];
            int range = drones[i][2];
            int val = abs(x-tar_x)+abs(y-tar_y);
            if(val<=range) {
               if(mini_val>val) {
                mini_val = val;
                indx = i;
               }
            }
        }
        return indx;
    }
};