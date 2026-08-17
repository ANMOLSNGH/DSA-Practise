class Solution {
public:
    int maximumGap(string skill, string station) {
        int m = skill.size();
        int n = station.size();
        
        vector<int> left(m, -1);
        vector<int> right(m, -1);
        

        int j = 0;
        for (int i = 0; i < n && j < m; i++) {
            if (station[i] == skill[j]) {
                left[j] = i;
                j++;
            }
        }
        

        j = m - 1;
        for (int i = n - 1; i >= 0 && j >= 0; i--) {
            if (station[i] == skill[j]) {
                right[j] = i;
                j--;
            }
        }
        
        int max_gap = 0;
        for (int i = 0; i < m - 1; i++) {
            if (left[i] != -1 && right[i + 1] != -1) {
                max_gap = max(max_gap, right[i + 1] - left[i]);
            }
        }
        
        return max_gap;
    }
};