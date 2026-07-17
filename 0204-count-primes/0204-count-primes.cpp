class Solution {
public:
    int countPrimes(int n) {
        if(n==0) return 0;
        vector<bool>prime(n,true);

        prime[0] = false;
        prime[1] = false;
        int cnt = 0;
        for(int i = 2;i<n;i++) {
            if(prime[i]) {
                cnt++;
                for(int j = i*2;j<n;j = j + i ) {
                    prime[j] = 0;
                }
            }
        }
        return cnt;
    }
};