class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<int>suffixtrack(n,0);

        int i = n-1;
        int j = m-1;
        int cnt = 0;
        while(i>=0) {
            if(j>=0&&word1[i]==word2[j]) {
                 cnt++;
                 j--;
            }
            suffixtrack[i] = cnt;
            i--;
        } 
        bool usepower = false;
        i = 0,j = 0;
        vector<int>ans(m);
        while(i<n&&j<m) {
            if(word1[i]==word2[j]) {
                ans[j] = i;
                  j++;
            }
            else {
                if(usepower==false&&(i+1<n&&suffixtrack[i+1]>=m-j-1)) {
                    usepower = true;
                    ans[j] = i;
                    j++;
                }
            }
            i++;
        }
        if(j==m) return ans;
        else return {};
    }
}; 