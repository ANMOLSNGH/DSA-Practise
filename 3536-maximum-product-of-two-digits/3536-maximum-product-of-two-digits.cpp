class Solution {
public:
    int maxProduct(int n) {
        int maxi = 0;
        int second_maxi = 0;

        while(n) {
            int digit = n%10;
            if(digit>maxi) {
                second_maxi = maxi;
                maxi = digit;
            }
            else if(second_maxi<digit) {
                second_maxi = digit;
            }
            n = n/10;
        }
        return maxi*second_maxi;
    }
};