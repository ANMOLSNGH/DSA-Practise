class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int maxi = *max_element(lights.begin(),lights.end());

        int max_wait = 0;
        for(auto num : arrivalTime) {
             int val = num%period;
             if(val>=maxi) {
                max_wait = max(max_wait, period - val);
             }
        }
        return max_wait;
    }
};