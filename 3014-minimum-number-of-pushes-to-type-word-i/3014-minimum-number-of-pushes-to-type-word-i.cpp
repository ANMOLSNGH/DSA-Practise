class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int sz = n;
        int ans = 0;
        if(sz<8) ans = sz;
        if(sz>=8&&sz<=16) {
            ans = 8 + (sz-8)*2;
        }
        if(sz>16&&sz<=24) ans += 24 + (sz-16)*3;
        if(sz>24) ans += 48 + (sz-24)*4;
        return ans;
        
    }
};