// Last updated: 10/14/2026, 5:05:18 PM
1class Solution {
2public:
3    string maxSumOfSquares(int num, int sum) {
4        string s = "";
5        int j = 9;
6        while(num>0&&sum>=0&&j>=0) {
7            if(sum<j) {
8            j = sum;
9            }
10            else {
11            sum -= j;
12            s += to_string(j);
13            num--;
14            }
15        }
16
17        if(sum!=0) return "";
18        return s;
19    }
20};