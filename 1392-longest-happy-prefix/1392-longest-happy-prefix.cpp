class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        vector<int>z(n,0);
        int l = 0 , r = 0;
        int longest = 0;
        string ans = "";
        int indx = -1;
        bool mark = false;
        for(int i = 1;i<n;i++) {
            if(i<r) {
                z[i] = z[i-l];

                 if(z[i]+i>r) z[i] = r-i;
            }


            while(z[i]+i<n&&s[z[i]]==s[i+z[i]]) z[i]++;
            if(z[i]+i==n) { 
                if(longest<z[i]) {
                longest = z[i];
                indx = i;
                mark = true;
            }
          }

          if(i+z[i]>r) {
            l = i;
            r = z[i]+i;
          }
            
       

            if(mark) break;

        }
        if(mark) {
            ans = s.substr(indx);
            return ans;
        }
        return "";
        
    }
};