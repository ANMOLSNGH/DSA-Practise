class Solution {
public:
    int integerBreak(int n) {
        if(n==2) return 1;
        if(n==3) return 2;
        if(n==4) return 4;
        int multiply = 1;
        while(n>0) {
         if(n>4)
          multiply *= 3;
          else multiply *= n;
          n -= 3;
        }
        return multiply;
    }
};