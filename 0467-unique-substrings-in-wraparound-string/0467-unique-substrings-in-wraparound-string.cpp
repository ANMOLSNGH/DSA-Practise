// class Solution {
// public:
//     bool isvalid(char ch1 , char ch2) {
//         if(ch1=='z'&&ch2=='a') return true;
//         return false;
//     }
//     int findSubstringInWraproundString(string s) {
//         vector<bool>dp(26,0);
//         int n = s.size();
//         int i = 0;
//         int j = 0;
//         long long ans = 0;
//         while(j<n) {
//             int cnt = 0;
//             while(j+1<n&&(s[j]-'a')==(s[j+1]-'a'+1)||(isvalid(s[j],s[j+1]))) {
//                  if(dp[s[j]-'a']==true) {
//                     cnt++;
//                  } 
//                  else dp[s[j]-'a'] = true;
//                  j++;
//              }
//              ans += ((j-i+1)*(j-i+2)/2) - (cnt*(cnt+1)/2);
//              i = j;

//         }
//         return ans;

//     }
// };

// this code fail since it cant distinguish a  b  and ab give us 0 with the derived formula 


class Solution {
public:
    bool isvalid(char ch1 , char ch2) {
        if(ch1 == 'z' && ch2 == 'a') return true;
        return false;
    }
    
    int findSubstringInWraproundString(string s) {
    
        vector<int> dp(26, 0); 
        int n = s.size();
        int i = 0;
        long long ans = 0;
        
        while(i < n) {
            int j = i;
            
        
            while(j + 1 < n && ((s[j+1] - s[j] == 1) || isvalid(s[j], s[j+1]))) {
                j++;
            }
            
     
            for(int k = i; k <= j; k++) {
                int current_len = k - i + 1; 
                int index = s[k] - 'a';
                
             
                if (current_len > dp[index]) {
                    ans += (current_len - dp[index]); 
                    dp[index] = current_len; 
                }
            }
            
            i = j + 1;
        }
        return ans;
    }
};