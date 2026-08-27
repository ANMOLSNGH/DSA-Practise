class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        int m = target.size();
        vector<int> freq(26, 0);
        
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        int max_prefix = 0;
        while (max_prefix < n && max_prefix < m && freq[target[max_prefix] - 'a'] > 0) {
            freq[target[max_prefix] - 'a']--;
            max_prefix++;
        }

        
        for (int i = max_prefix; i >= 0; i--) {
            if (i < m) {
                
                for (char ch = target[i] + 1; ch <= 'z'; ch++) {
                    if (freq[ch - 'a'] > 0) {
                        
                        string curr = target.substr(0, i);
                        curr += ch;
                        freq[ch - 'a']--;

                        
                        for (char fill = 'a'; fill <= 'z'; fill++) {
                            while (freq[fill - 'a'] > 0) {
                                curr += fill;
                                freq[fill - 'a']--;
                            }
                        }
                        return curr;
                    }
                }
            }
           
            if (i > 0) {
                freq[target[i - 1] - 'a']++;
            }
        }

        return "";
    }
};