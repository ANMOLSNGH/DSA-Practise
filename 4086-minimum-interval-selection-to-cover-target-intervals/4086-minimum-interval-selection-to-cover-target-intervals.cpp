class Solution {
public:
    int minSelection(vector<vector<int>>& a, vector<vector<int>>& t) {
        int n = a.size();
        int m = t.size();

        sort(a.begin(),a.end());
        sort(t.begin(),t.end());
        vector<vector<int>>merge_t;

        int start = t[0][0];
        int end = t[0][1];

        for(int i = 1;i<m;i++) {
            if(t[i][0]<=end) {
                end = max(t[i][1],end);
            }
            else {
                merge_t.push_back({start,end});
                start = t[i][0];
                end = t[i][1];
            }
        }
        merge_t.push_back({start,end});
        

        int cnt = 0;
        int indx = 0;
        int covered = -1;

        for(auto&merge : merge_t) {
            int l = merge[0] , r = merge[1];
            while(covered<r) {
                int start = max(covered,l);
                int end = covered;

                while(indx<n&&a[indx][0]<=start) {
                    end = max(end,a[indx][1]);
                    indx++;
                }
                if(end<=covered||end<l) return -1;
                covered = end;
                cnt++;
            }
        }
        return cnt;

        

    }
};