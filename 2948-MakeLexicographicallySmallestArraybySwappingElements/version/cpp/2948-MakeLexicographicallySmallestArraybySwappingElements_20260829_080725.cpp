// Last updated: 8/29/2026, 8:07:25 AM
1class Solution {
2public:
3    int n;
4    
5    bool solve(string &curr, string &target, int i, bool greater, vector<int>& freq) {
6        if(i >= n / 2) {
7            string full = curr; 
8            
9            if(n % 2 == 1) {
10                for(int j = 0; j < 26; j++) {
11                    if(freq[j] % 2 == 1) {
12                        full.push_back(j + 'a');
13                        break;
14                    }
15                }
16            }
17            
18            string temp = curr; 
19            reverse(temp.begin(), temp.end());
20            full += temp;
21            
22            if (full > target) {
23                curr = full; 
24                return true;
25            }
26            return false; 
27        }
28
29        for(char ch = 'a'; ch <= 'z'; ch++) {
30            if(freq[ch - 'a'] < 2) continue;
31            if(greater == false && target[i] > ch) continue;
32            
33            curr.push_back(ch);
34            freq[ch - 'a'] -= 2;
35            
36            bool isGreater = greater || (ch > target[i]);
37            
38            if(solve(curr, target, i + 1, isGreater, freq)) return true;
39            
40            curr.pop_back();
41            freq[ch - 'a'] += 2;
42        }
43        return false;
44    }
45    
46    string lexPalindromicPermutation(string s, string target) {
47        n = s.size();
48        vector<int> freq(26, 0);
49        int odd_cnt = 0;
50        
51        for(int i = 0; i < n; i++) {
52             freq[s[i] - 'a']++;
53        }
54        
55        for(int i = 0; i < 26; i++) {
56            if(freq[i] % 2 == 1) odd_cnt++;
57            if(odd_cnt > 1) return ""; 
58        }
59        
60        string curr = "";
61        
62        if(solve(curr, target, 0, false, freq)) {
63            return curr; 
64        }
65        
66        return ""; 
67    }
68};