class Solution {
public:
  
    unordered_map<long long, int> dp;
    int solve(long long n) {
        if(n == 1) return 0;
        

        if(dp.count(n)) return dp[n];

        int even = INT_MAX;
        int odd = INT_MAX;
        
        if((n & 1) == 0) {
           even = 1 + solve(n / 2);
        }
        else {
           odd = 1 + min(solve(n - 1), solve(n + 1));
        }
        
        return dp[n] = min(even, odd);
    }
    
    int integerReplacement(int n) {

        return solve(n);
    }
};