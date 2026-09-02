class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int n = rowIndex;
        vector<int>ans(n+1);
        ans[0]= 1;
        long long res = 1;
        for(int i = 0;i<n;i++) {
            res *= n-i;
            res /= i+1;
            ans[i+1] = res;
            }
            return ans;
        }
    
};