class Solution {
public:
    int numberOfUniqueGoodSubsequences(string binary) {
        int n = binary.size();
        int i = 0;
        while(i<n&&binary[i]!='1') i++;
        if(i==n) return 1;

        long long mod = 1e9 + 7;
        vector<long long> dp(n, 0);
        dp[i] = 1;
        int lastZero = 0, lastOne = 0;
        for(int indx = i+1;indx<n;indx++) {
            int j = binary[indx]=='0'?lastZero:lastOne;
            long long dup = (j>0)?dp[j-1]:0;

            dp[indx] = (2*dp[indx-1]%mod - dup + mod)%mod;
            if (binary[indx] == '0') {
                lastZero = indx;
            } else {
                lastOne = indx;
            }
        }

        int hasZero = 0;
        if (binary.find('0') != string::npos) {
            hasZero = 1;
        }

        return (dp[n-1]+hasZero)%mod;
    }
};