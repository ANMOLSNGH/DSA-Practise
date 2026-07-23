class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        
        // Edge cases: If n is 1 or 2, we don't have enough elements 
        // to toggle extra bits. The answer is just n.
        if (n < 3) return n;
        
        // Find the number of bits in 'n'
        int bits = 0;
        int temp = n;
        while (temp > 0) {
            bits++;
            temp /= 2;
        }
        
        // 2^bits is perfectly calculated using a bitwise shift
        return 1 << bits;
    }
};