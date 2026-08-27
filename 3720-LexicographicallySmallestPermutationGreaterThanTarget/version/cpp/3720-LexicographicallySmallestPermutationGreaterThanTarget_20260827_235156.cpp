// Last updated: 8/27/2026, 11:51:56 PM
1class Solution {
2public:
3    int n;
4    bool solve(string &s,string &curr,vector<int>&freq,string &target,int indx,bool greater) {
5         if(indx==n) {
6            if(greater==true) {
7                s = curr;
8                return true;
9            }
10            return false;
11         }
12
13         for(char ch ='a';ch <= 'z' ; ch++) {
14            if(freq[ch-'a']==0) continue;
15            if(greater==false&&ch<target[indx]) continue;
16            curr.push_back(ch);
17            freq[ch-'a']--;
18            bool isGreater = greater || ch>target[indx];
19            if(solve(s,curr,freq,target,indx+1,isGreater)) return true;
20            curr.pop_back();
21            freq[ch-'a']++;
22         }
23         return false;
24    }
25    string lexGreaterPermutation(string s, string target) {
26        n = s.size();
27        string curr = "";
28
29        vector<int>freq(26,0);
30        for(auto ch : s) freq[ch-'a']++;
31        if(solve(s,curr,freq,target,0,false)) return s;
32        return "";
33    }
34};