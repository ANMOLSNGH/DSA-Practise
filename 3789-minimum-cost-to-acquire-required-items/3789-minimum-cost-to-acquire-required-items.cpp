class Solution {
public:
    typedef long long ll;
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        if(cost1+cost2<=costBoth) {
            return (ll)cost1*(ll)need1 + (ll)cost2*(ll)need2;
        }
        int both = min(need1,need2);
        ll total = (ll)both * (ll)costBoth;

        need1 -= both;
        need2 -= both;

        if(need1>0) {
            total += (ll)need1*(ll)min(cost1,costBoth);
        }
        else if(need2>0) {
            total += (ll)need2*(ll)min(cost2,costBoth);
        }

        return total;
    }
};