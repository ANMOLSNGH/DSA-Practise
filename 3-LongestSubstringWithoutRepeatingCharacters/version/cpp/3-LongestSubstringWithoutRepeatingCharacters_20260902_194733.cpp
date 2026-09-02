// Last updated: 9/2/2026, 7:47:33 PM
1class Solution {
2public:
3    int lengthOfLongestSubstring(string s) {
4        int n = s.size();
5       unordered_map<char,int>mpp;
6        int i = 0 , j = 0;
7        int maxi_len = 0;
8        while(j<n) {
9            mpp[s[j]]++;
10            while(mpp[s[j]]>1) {
11                mpp[s[i]]--;
12                i++;
13            }
14         
15            maxi_len = max(maxi_len,j-i+1);
16            j++;
17        }
18        return maxi_len;
19    }
20};