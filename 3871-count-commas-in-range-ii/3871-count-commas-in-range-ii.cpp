class Solution {
public:
    long long countCommas(long long n) {
        long long commas = 0;
        long long base = 1000;
        
        // As long as n is greater than or equal to the current base (1e3, 1e6, 1e9...)
        while (n >= base) {
            commas += (n - base + 1); // Add a comma for every number >= base
            
            // Prevent long long overflow if n is exceptionally large
            if (base > LLONG_MAX / 1000) break;
            
            base *= 1000; 
        }
        
        return commas;
    }
};