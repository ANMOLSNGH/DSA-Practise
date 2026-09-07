class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.size();
        vector<int>dp(26,0);
        int mod = 1e9+7;
        int prev  = 0;
        for(auto ch : s) {
            int p = prev;
            prev = (2*prev%mod - dp[ch-'a'] + 1+mod)%mod;
            dp[ch-'a'] = (p+1)%mod;
        }
        return prev;
    }
};