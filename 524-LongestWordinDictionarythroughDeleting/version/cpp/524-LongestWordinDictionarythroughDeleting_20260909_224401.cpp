// Last updated: 9/9/2026, 10:44:01 PM
1class Solution {
2public:
3    string findLongestWord(string s, vector<string>& dictionary) {
4        string longest_word = "";
5        
6        for (auto word : dictionary) {
7            int i = 0; 
8            int j = 0; 
9            
10            while (i < s.length() && j < word.length()) {
11                if (s[i] == word[j]) {
12                    j++; 
13                }
14                i++; 
15            }
16            
17            if (j == word.length()) {
18                if (word.length() > longest_word.length() || 
19                   (word.length() == longest_word.length() && word < longest_word)) {
20                    longest_word = word;
21                }
22            }
23        }
24        
25        return longest_word;
26    }
27};