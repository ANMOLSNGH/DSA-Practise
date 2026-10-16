class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int topRow = 0;
        int bottomRow = n - 1;
        int leftColm = 0;
        int rightColm = m - 1;

        vector<int> ans;

        while (leftColm <= rightColm && topRow <= bottomRow) {
            for (int i = leftColm; i <= rightColm; i++) {
                ans.push_back(matrix[topRow][i]);
            }
            topRow++;

            for (int i = topRow; i <= bottomRow; i++) {
                ans.push_back(matrix[i][rightColm]);
            }
            rightColm--;

            if (topRow <= bottomRow) {
                for (int i = rightColm; i >= leftColm; i--) {
                    ans.push_back(matrix[bottomRow][i]);
                }
                bottomRow--;
            }

            if (leftColm <= rightColm) {
                for (int i = bottomRow; i >= topRow; i--) {
                    ans.push_back(matrix[i][leftColm]);
                }
                leftColm++;
            }
        }
        return ans;
    }
};