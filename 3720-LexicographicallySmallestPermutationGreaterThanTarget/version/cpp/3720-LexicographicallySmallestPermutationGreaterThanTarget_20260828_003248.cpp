// Last updated: 8/28/2026, 12:32:48 AM
1class Solution {
2public:
3    string lexGreaterPermutation(string s, string target) {
4        int n = s.size();
5        int m = target.size();
6        vector<int> freq(26, 0);
7        
8        for (char ch : s) {
9            freq[ch - 'a']++;
10        }
11
12        int max_prefix = 0;
13        while (max_prefix < n && max_prefix < m && freq[target[max_prefix] - 'a'] > 0) {
14            freq[target[max_prefix] - 'a']--;
15            max_prefix++;
16        }
17
18        
19        for (int i = max_prefix; i >= 0; i--) {
20            if (i < m) {
21                
22                for (char ch = target[i] + 1; ch <= 'z'; ch++) {
23                    if (freq[ch - 'a'] > 0) {
24                        
25                        string curr = target.substr(0, i);
26                        curr += ch;
27                        freq[ch - 'a']--;
28
29                        
30                        for (char fill = 'a'; fill <= 'z'; fill++) {
31                            while (freq[fill - 'a'] > 0) {
32                                curr += fill;
33                                freq[fill - 'a']--;
34                            }
35                        }
36                        return curr;
37                    }
38                }
39            }
40           
41            if (i > 0) {
42                freq[target[i - 1] - 'a']++;
43            }
44        }
45
46        return "";
47    }
48};