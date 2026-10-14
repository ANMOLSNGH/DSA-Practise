class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string s = "";
        int j = 9;
        while(num>0&&sum>=0&&j>=0) {
            if(sum<j) {
            j = sum;
            }
            else {
            sum -= j;
            s += to_string(j);
            num--;
            }
        }

        if(sum!=0) return "";
        return s;
    }
};