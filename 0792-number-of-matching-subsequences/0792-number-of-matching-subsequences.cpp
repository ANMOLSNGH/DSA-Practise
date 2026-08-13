class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>>pos(26);

        for(int i = 0;i<s.size();i++) {
            pos[s[i]-'a'].push_back(i);
        }
        int cnt = 0;

        for(string &word : words) {
            int current_idx = -1; 
            bool possi = true;
            for(char c : word) {
                auto it = upper_bound(pos[c-'a'].begin(),pos[c-'a'].end(),current_idx);
                if(it == pos[c - 'a'].end()) {
                    possi = false;
                    break;
                }


                current_idx = *it;
            }
            if(possi) cnt++;
        }
        return cnt;
    }
};