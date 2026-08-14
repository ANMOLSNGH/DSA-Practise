class Solution {
public:
    int mod = 1e9+7;
    unordered_set<int>st;
    unordered_map<int,long long>dp;

   long long solve(int num) {
        if(dp.count(num)) return dp[num];
        long long ways = 1;
        for(int i = 2;i*i<=num;i++) {
            if (num % i == 0) {
                int factor1 = i;
                int factor2 = num / i;
                if (st.count(factor1) && st.count(factor2)) {
                    long long left_ways = solve(factor1);
                    long long right_ways = solve(factor2);

                    long long combination = (left_ways*right_ways)%mod;

                    if(factor1==factor2) {
                        ways = (ways+combination)%mod;
                    }
                    else ways = (ways+combination*2)%mod;

                }
        }
        }
        return dp[num] = ways;
   }
    int numFactoredBinaryTrees(vector<int>& arr) {
        for (int x : arr) {
            st.insert(x);
        }
        
        long long total_trees = 0;
        for (int x : arr) {
            total_trees = (total_trees + solve(x)) % mod;
        }
        
        return total_trees;
    }
};