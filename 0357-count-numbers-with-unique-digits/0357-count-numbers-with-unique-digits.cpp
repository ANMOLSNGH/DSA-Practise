class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int prev = 1;
        int multiply = 1;
        int cnt = 9;
        for(int i = 1 ;i<=n;i++) {
             prev += 9*multiply;
             multiply = multiply*cnt;
             cnt--;
        }
        return prev;
    }
};