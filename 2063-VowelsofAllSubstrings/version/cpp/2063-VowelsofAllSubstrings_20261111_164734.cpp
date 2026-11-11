// Last updated: 11/11/2026, 4:47:34 PM
1class Solution {
2public:
3    bool isVowel(char ch) {
4        return ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u';
5    }
6    
7    long long countVowels(string word) {
8        long long count = 0;
9        int len = word.size();
10        
11        for(int pos = 0; pos < len; pos++) {
12            if(isVowel(word[pos])) {
13                count += (long)(len - pos) * (long)(pos + 1);
14            }
15        }
16        
17        return count;
18    }
19};