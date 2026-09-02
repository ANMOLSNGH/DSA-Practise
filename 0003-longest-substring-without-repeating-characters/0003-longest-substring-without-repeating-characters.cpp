class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
       unordered_map<char,int>mpp;
        int i = 0 , j = 0;
        int maxi_len = 0;
        while(j<n) {
            mpp[s[j]]++;
            while(mpp[s[j]]>1) {
                mpp[s[i]]--;
                i++;
            }
         
            maxi_len = max(maxi_len,j-i+1);
            j++;
        }
        return maxi_len;
    }
};