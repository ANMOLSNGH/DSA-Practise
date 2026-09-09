class Solution {
public:
// 4-6 -> 1 total 1000 to 999999
// 7-9 -> 2   1000000 to 999999999
// 10-12 -> 3 10000000000 to 999999999999
// 13-15-> 4  1000000000000 to 999999999999999
    long long case1 = 1e3;
    long long case2 = 1e6;
    long long case3 = 1e9;
    long long case4 = 1e12;
    long long case5 = 1e15;
    long long countCommas(long long n) {
        if(n<case1) return 0;
        long long cnt = 0;
        if(n>=case1&&n<case2) cnt += n-case1+1;
        if(n>=case2&&n<case3) {
              cnt += (case2-case1)*1 + (n-case2+1)*2;
        }
        if(n>=case3&&n<case4) {
            cnt += (case2-case1) + (case3-case2)*2 + (n-case3+1)*3;
        }
        if(n>=case4&&n<case5) {
            cnt += (case2-case1) + (case3-case2)*2 + (case4-case3)*3 + (n-case4+1)*4;
        }
         if(n>=case5) {
            cnt += (case2-case1) + (case3-case2)*2 + (case4-case3)*3 + (n-case4+1)*4+1;
        }
        return cnt;
    }
};