// Last updated: 9/26/2026, 8:32:15 PM
1class Solution {
2public:
3    int minQueenMoves(vector<int>& src, vector<int>& tar) {
4        int i = src[0];
5        int j = src[1];
6        int i_n = tar[0];
7        int j_n = tar[1];
8        if(i==i_n&&j==j_n) return 0;
9        if((i+j)==(i_n+j_n)||(j-i)==(j_n)-(i_n)) return 1;
10        if(i==i_n||j==j_n) return 1;
11        return 2;
12    }
13};