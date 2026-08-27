class Solution {
public:
    int n;
    bool solve(string &s,string &curr,vector<int>&freq,string &target,int indx,bool greater) {
         if(indx==n) {
            if(greater==true) {
                s = curr;
                return true;
            }
            return false;
         }

         for(char ch ='a';ch <= 'z' ; ch++) {
            if(freq[ch-'a']==0) continue;
            if(greater==false&&ch<target[indx]) continue;
            curr.push_back(ch);
            freq[ch-'a']--;
            bool isGreater = greater || ch>target[indx];
            if(solve(s,curr,freq,target,indx+1,isGreater)) return true;
            curr.pop_back();
            freq[ch-'a']++;
         }
         return false;
    }
    string lexGreaterPermutation(string s, string target) {
        n = s.size();
        string curr = "";

        vector<int>freq(26,0);
        for(auto ch : s) freq[ch-'a']++;
        if(solve(s,curr,freq,target,0,false)) return s;
        return "";
    }
};