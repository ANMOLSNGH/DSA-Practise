class Solution {
public:
    int n;
    
    bool solve(string &curr, string &target, int i, bool greater, vector<int>& freq) {
        if(i >= n / 2) {
            string full = curr; 
            
            if(n % 2 == 1) {
                for(int j = 0; j < 26; j++) {
                    if(freq[j] % 2 == 1) {
                        full.push_back(j + 'a');
                        break;
                    }
                }
            }
            
            string temp = curr; 
            reverse(temp.begin(), temp.end());
            full += temp;
            
            if (full > target) {
                curr = full; 
                return true;
            }
            return false; 
        }

        for(char ch = 'a'; ch <= 'z'; ch++) {
            if(freq[ch - 'a'] < 2) continue;
            if(greater == false && target[i] > ch) continue;
            
            curr.push_back(ch);
            freq[ch - 'a'] -= 2;
            
            bool isGreater = greater || (ch > target[i]);
            
            if(solve(curr, target, i + 1, isGreater, freq)) return true;
            
            curr.pop_back();
            freq[ch - 'a'] += 2;
        }
        return false;
    }
    
    string lexPalindromicPermutation(string s, string target) {
        n = s.size();
        vector<int> freq(26, 0);
        int odd_cnt = 0;
        
        for(int i = 0; i < n; i++) {
             freq[s[i] - 'a']++;
        }
        
        for(int i = 0; i < 26; i++) {
            if(freq[i] % 2 == 1) odd_cnt++;
            if(odd_cnt > 1) return ""; 
        }
        
        string curr = "";
        
        if(solve(curr, target, 0, false, freq)) {
            return curr; 
        }
        
        return ""; 
    }
};