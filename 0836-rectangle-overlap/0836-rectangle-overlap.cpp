class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x1 = rec1[2];
        int y1 = rec1[3];
        int x0 = rec1[0];
        int y0 = rec1[1];
        int x2 = rec2[0];
        int y2 = rec2[1];
         int x3 = rec2[2];
        int y3 = rec2[3];
        if(x2<x1&&y2<y1&&x3>x0&&y3>y0) return true;
        return false;
    }
};