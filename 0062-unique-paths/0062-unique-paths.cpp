class Solution {
public:
    int uniquePaths(int m, int n) {
        int r = m - 1;
        int c = n - 1;
        // just do (r+c)!/r!*c!;
        n = r+c;
        r = min(r,c);

        // ncr -> n*n-1*n-2*.....n-r-1/r*r-1*r-2..1
        long long ans = 1;
        for(int i = 1;i<=r;i++) {
            ans *= n-i+1;
            ans /= i;
        }
        return ans;
    }
};