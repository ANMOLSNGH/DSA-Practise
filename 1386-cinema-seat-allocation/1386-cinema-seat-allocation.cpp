class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,int>mpp;

        for(auto &reservedSeat : reservedSeats) {
            int row = reservedSeat[0];
            int seat = reservedSeat[1];

            mpp[row] |= (1<<seat);

        }

        int result = (n - mpp.size())*2;

        int maskA = (1<<2)|(1<<3)|(1<<4)|(1<<5);
        int maskB = (1<<4)|(1<<5)|(1<<6)|(1<<7);
        int maskC = (1<<6)|(1<<7)|(1<<8)|(1<<9);

        for(auto [row,seat] : mpp) {
            bool grpA = (seat&maskA)==0;
            bool grpB = (seat&maskB)==0;
            bool grpC = (seat&maskC)==0;

            if(grpA&&grpC) result += 2;
            else if(grpA||grpB||grpC) result++;
        }
        return result;
        
    }
};