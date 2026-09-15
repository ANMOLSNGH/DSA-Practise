// Last updated: 9/15/2026, 10:35:11 PM
1class Solution {
2public:
3    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
4        int x1 = rec1[2];
5        int y1 = rec1[3];
6        int x0 = rec1[0];
7        int y0 = rec1[1];
8        int x2 = rec2[0];
9        int y2 = rec2[1];
10         int x3 = rec2[2];
11        int y3 = rec2[3];
12        if(x2<x1&&y2<y1&&x3>x0&&y3>y0) return true;
13        return false;
14    }
15};