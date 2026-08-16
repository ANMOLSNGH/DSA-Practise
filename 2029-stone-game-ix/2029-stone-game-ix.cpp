class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        vector<int> counts(3, 0);
        
        // Count frequencies of modulo 3
        for(int i = 0; i < stones.size(); i++) {
            counts[stones[i] % 3]++;
        }
        
        // If the number of 0s is even, they essentially cancel each other out.
        // Alice just needs at least one 1 and one 2 to force a win.
        if(counts[0] % 2 == 0) {
            return counts[1] > 0 && counts[2] > 0;
        } 
        // If the number of 0s is odd, it flips the parity of the game.
        // Alice needs a difference of at least 3 between the 1s and 2s to win.
        else {
            return abs(counts[1] - counts[2]) > 2;
        }
    }
};