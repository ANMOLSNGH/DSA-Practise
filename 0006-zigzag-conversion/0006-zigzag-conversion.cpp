class Solution {
public:
    string convert(string s, int n) {
        if (n == 1) return s;
        
        string ans = "";
        vector<string> res(n, "");
        int i = 0;
        int cnt = 0;
        
        while(i < s.size()) {
            for(int k = 0; k < n && i < s.size(); k++) {
                if(cnt & 1) {
                    if((n - k - 1) != 0 && (n - k - 1) != n - 1) {
                       res[n - k - 1] += s[i];
                       i++;
                    }
                }
                else {
                    res[k] += s[i];
                    i++;
                }
            }
            cnt++;
        }
        
        for(int j = 0; j < n; j++) ans += res[j];

        return ans;
    }
};