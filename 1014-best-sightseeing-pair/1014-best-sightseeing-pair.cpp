class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int res = 0;
        int maxSoFar = values[0] + 0;

        for(int i = 1;i<values.size();i++) {
            maxSoFar = max(maxSoFar,values[i-1] + i - 1);
            res = max(res,values[i] - i + maxSoFar);
        }
        return res;
    }
};